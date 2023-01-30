#include "People.h"
#include <iostream>
#include <string>
using namespace std;
People::People ( ) {
    dayInPrison = 1;
    mostPhysicalStrength = 100;
    mostHealth = 100;
    caseFragment = 0;
    lifeTime = 19000;
    salt = 0;
    sugar = 0;
    addMind = 0;
    TVNumber = 0;
    everyDayLoseWater = 0.1;
    everyDayLosePhysicalStrength = 0;
    everyDayLoseHealth = 0;
    everyDayLoseFood = 0.1;
    haveStore = false;
    int k;
    k = rand ( ) % 8;
    hobby = k;
    if ( k == 0 )
        addMind = 5;
    k = rand ( ) % 20 - 10;
    health = mostHealth - k;
    k = rand ( ) % 20;
    money = k * 1.0;
    k = rand ( ) % 80;
    physicalStrength = k;
    k = rand ( ) % 20 - 10;
    food = 80.0 + k;
    k = rand ( ) % 20 - 10;
    water = 80.0 + k;
    k = rand ( ) % 20;
    mind = 80 + k;
    k = rand ( ) % 20 - 10;
    weight = 50.0 + k;

    myDisease [0].addMyDisease ( "����", 0, 10, 0, 0, 0 );
    myDisease [1].addMyDisease ( "����", 0, 10, 0, -1, 1 );
    myDisease [2].addMyDisease ( "��Ѫѹ", 0, 10, 0, -1, 2 );
    myDisease [3].addMyDisease ( "������", -1, -1, 0, 0, 3 );
    myDisease [4].addMyDisease ( "����", 0, 20, 0, -1, 4 );
    myDisease [5].addMyDisease ( "����", 0, 20, 0, -1, 5 );

}
void People::changeMoney ( double money_ ) {
    money += money_;
}
void People::getDrink ( Drink* myDrink ) {   //��ˮ������ˮ����
    mind += addMind;
    if ( hobby == 3 )
        mind += 10;
    myDrink->number--;
    int k = 0;   // ������
    int k_ = 0;   //����
    k = rand ( ) % 100;
    k_ = rand ( ) % 100;
    water += myDrink->addWater;
    mind += myDrink->addMind;
    food += myDrink->addFood;
    sugar += myDrink->addSugar;
    weight += myDrink->addWeight;
    if ( k_ < myDrink->probabilitYOfaddHealth )
        health += myDrink->addHealth;
    if ( k < myDrink->probabilityOfDiarrhea )
        getDisease ( 3 );
}

void People::getFood ( Food* myFood ) {   //��ʳ�����ʳ������
    mind += addMind;
    if ( hobby == 1 )
        mind += 10;
    myFood->number--;
    int k = 0;   // ������
    int k_ = 0;   //����
    k = rand ( ) % 100;
    k_ = rand ( ) % 100;
    water += myFood->addWater;
    mind += myFood->addMind;
    food += myFood->addFood;
    sugar += myFood->addSugar;
    salt += myFood->addSalt;
    weight += myFood->addWeight;
    if ( k_ < myFood->probabilitYOfaddHealth )
        health += myFood->addHealth;
    if ( k < myFood->probabilityOfDiarrhea )
        getDisease ( 3 );
}

void People::getTreatment ( Treatment* myTreatment, bool withCard ) {   //���ƣ��������Ʒ�����withCard(true)��ʾ����ʹ�ÿ�Ƭ
    int myLevel = 0;
    int kind = myTreatment->number;
    if ( kind != 5 )
        myLevel = myDisease [kind].level;
    if ( kind == 0 || kind == 3 ) {
        myDisease [myTreatment->number].level--;
        myLevel = myDisease [kind].level;
    }
    if ( myTreatment->number != 4 ) {   //����������
        if ( kind == 0 ) {
            if ( myLevel == 0 ) {
                myDisease [0].whenCure = 0;
                myDisease [0].now = 0;
            }
        } else if ( kind == 1 || kind == 2 ) {   //����ֻ�ܿ�����
            if ( myDisease [kind].level < 4 ) {
                myDisease [kind].level--;
                myLevel = myDisease [kind].level;
                everyDayLoseHealth --;
            }
        } else if ( kind == 3 ) {
            if ( myLevel == 0 ) {
                myDisease [0].whenCure = 0;
                myDisease [0].now = 0;
            }
            everyDayLoseFood--;
            everyDayLoseWater--;
        }
    } else {
        if ( withCard ) {
            if ( myLevel == 1 )
                money -= 100;
            else if ( myLevel == 2 )
                money -= 200;
            else if ( myLevel == 3 )
                money -= 400;
            else if ( myLevel == 4 )
                money -= 800;
        } else {
            if ( myLevel == 1 )
                money -= 500;
            else if ( myLevel == 2 )
                money -= 1000;
            else if ( myLevel == 3 )
                money -= 2000;
            else if ( myLevel == 4 )
                money -= 4000;
        }
        everyDayLoseFood = 0.1;
        everyDayLoseHealth = 0;
        everyDayLosePhysicalStrength = 0;
        everyDayLoseWater = 0.1;
        myDisease [kind].level = 0;
        myDisease [kind].now = 0;
        myDisease [kind].whenCure = 0;
        health = mostHealth;
        physicalStrength = mostPhysicalStrength / 2;
    }
}
void People::changeHealth ( int k ) {
    health -= k;
}

//����Ѿ����������֣��˶�������������Ҫ������������
void People::getDisease ( int kind ) {   //���������벡������
    myDisease [kind].level += 1;
    int diseaseLevel;
    diseaseLevel = myDisease [kind].level;
    if ( kind == 0 ) {
        if ( diseaseLevel == 1 )
            health -= 2;
        else if ( diseaseLevel == 2 )
            health -= 3;
        else if ( diseaseLevel == 3 )
            health -= 4;
        else if ( diseaseLevel >= 4 ) {
            myDisease [kind].level = 4;
            health -= 10;
        }
    } else if ( kind == 1 ) {
        if ( diseaseLevel >= 4 ) 
            myDisease [kind].level = 4;
        everyDayLoseHealth++;
    } else if ( kind == 2 ) {
        if ( diseaseLevel >= 4 )
            myDisease [kind].level = 4;
        everyDayLoseHealth++;
    } else if ( kind == 3 ) {
        if ( diseaseLevel >= 4 ) {
            myDisease [kind].level = 4;    
            health -= 5;
        }
        everyDayLoseFood++;
        everyDayLoseWater++;
    } else if ( kind == 4 ) {
        everyDayLosePhysicalStrength += 5;
        if ( diseaseLevel >= 4 ) {
            myDisease [kind].level = 4;
            health -= 20;
        }
    } else if ( kind == 5 ) {
        everyDayLosePhysicalStrength += 5;
        if ( diseaseLevel >= 4 ) {
            myDisease [kind].level = 4;
            health -= 20;
        }
    }
}
void People::sleep ( ) {
    mind += addMind;
    if ( hobby == 4 )
        mind += 10;
    //����
    if ( myDisease [0].level ) {
        if ( myDisease [0].whenCure == 0 ) {
            myDisease [0].level--;
        } else
            myDisease [0].whenCure--;
    }

    // ������������2�����򲡳̶ȼ�1
    if ( sugar > 2 )
        getDisease ( 1 );

    //������������9����Ѫѹ�̶ȼ�1
    if ( salt > 9 )
        getDisease ( 2 );

    //������
    if ( myDisease [3].level ) {
        if ( myDisease [3].whenCure == 0 )
            myDisease [3].level--;
        else
            myDisease [3].whenCure--;
    }

    //�����ڽ�ʳ�Ͷ����������󶼽����ж�

    mind += 5;

    if ( mind < -100 ) {
        everyDayLoseHealth += 10;
        everyDayLoseFood += 10;
        everyDayLosePhysicalStrength += 20;
        everyDayLoseWater += 10;
    } else if ( mind < -200 ) {
        everyDayLoseHealth += 20;
        everyDayLoseFood += 20;
        everyDayLosePhysicalStrength += 40;
        everyDayLoseWater += 20;
    } else if ( mind < -400 ) {
        health = -0x3f3f3f3f;
    } else if ( mind > 200 ) {
        everyDayLoseFood--;
        everyDayLosePhysicalStrength -= 5;
        everyDayLoseWater--;
    }
    if ( everyDayLoseFood < 0 )
        everyDayLoseFood = 0.1;
    if ( everyDayLoseHealth < 0 )
        everyDayLoseHealth = 0;
    if ( everyDayLosePhysicalStrength < 0 )
        everyDayLosePhysicalStrength = 0;
    if ( everyDayLoseWater < 0 )
        everyDayLoseWater = 0.1;
    dayInPrison++;
    lifeTime--;
    health -= everyDayLoseHealth;
    physicalStrength = mostPhysicalStrength - everyDayLosePhysicalStrength;
    water -= everyDayLoseWater;
    food -= everyDayLoseFood;
    if ( water < 0 )
        health--;
    if ( food < 0 )
        health--;
}
void People::watchTV ( ) {
    mind += addMind;
    if ( hobby == 5 )
        mind += 10;
    int k = 0;
    printf ( "����%d̨���ӣ����ҵ�������Ƭ�ļ���Ϊ%lf%%\n", TVNumber, TVNumber * 0.01 / 1000 );
    k = rand ( ) % ( 1000 / TVNumber );
    if ( k == 0 ) {
        cout << "�ҵ���һ��������Ƭ, �������� : ";
        caseFragment++;
        cout << caseFragment << "��������Ƭ��";
    }
}
void People::doExercise ( ) {
    weight -= 10;
    int k = 0;
    k = rand ( ) % 100;
    if ( k < 50 )
        this->myDisease [0].getDisease ( this, 1, 0 );
    mostPhysicalStrength += 1;
    if ( ( mostPhysicalStrength - 100 ) % 10 == 0 )   //��������ÿ����10���1��������
        mostHealth++;
    if ( ( mostPhysicalStrength - 100 ) % 50 == 0 )   //��������ÿ����50���1����
        lifeTime++;
    if ( weight < 50 )
        myDisease [5].getDisease ( this, 10, 5 );
    else
        myDisease [4].getDisease ( this, -10, 4 );
}
void People::getHobby ( int kind ) {
    if ( kind == hobby )
        mind += 40;
    else
        mind += 10;
}

void People::changeMind ( int k ) {
    mind += k;
}
void People::changeWeight ( int k ) {
    weight += k;
}
void People::Disease::getDisease ( People* you, int k, int kind ) {
    now += k;
    if ( now > most ) {
        now -= most;
        you->getDisease ( kind );
    }
}
void People::Disease::showItself ( ) {
    string Level [5] = { "�������޲�", "���", "�ж�", "�ض�", "����" };
    cout << "�������ƣ�" << name << endl
        << "�����ۼƣ�" << this->now << "\t�ۼƶ��ٻ�����" << most << endl
        << "���ڵȼ���" << Level [level] << "\tʲôʱ�����ƺã�" << whenCure;
}
void People::Disease::addMyDisease ( string name_, int now_, int most_, int level_, int whenCure_, int number_ ) {
    number = number_;
    name.assign ( name_ );
    now = now_;
    most = most_;
    level = level_;
    whenCure = whenCure_;
}
People::Disease::Disease ( string name_, int now_, int most_, int level_, int whenCure_, int number_ ) {
    number = number_;
    now = now_;
    most = most_;
    level = level_;
    whenCure = whenCure_;
    name.assign ( name_ );
}
People::Disease::Disease ( ) {
    number = 0;
    name.assign ( "*" );
    level = 0;
    now = 0;
    most = 0;   //������������һ���ȼ�
    whenCure = 0;   //���жȸ�Ѫѹ����ͨ�����������жȹ�������   10���һ���ȼ����߶Ⱥ;���ֻ�ܳ�ҩ����
}
void People::showYourself ( ) {
    string allHobbies [6] = { "����", "�Է�", "����", "��ˮ", "˯��", "������" };
    cout << endl << "\t����" << endl << endl;
    cout << "������ " << health << "\t������ " << physicalStrength << endl
        << "ˮ�� " << water << "\t�����ȣ� " << food << endl
        << "���ã� " << allHobbies [ hobby] << "\t���飺 " << mind << endl
        << "���أ� " << weight << "\t�ֽ� " << money << endl
        << "���ǣ� " << sugar << "\t���Σ� " << salt << endl
        << "ʣ���������� " << lifeTime << "\t�������ڼ����ĵڣ�" << dayInPrison << endl
        << "ÿ�ռ��������� " << everyDayLosePhysicalStrength << endl
        << "ÿ�ռ��������� " << everyDayLoseHealth << endl
        << "ÿ�ռ��ٱ����ȣ� " << everyDayLoseFood << endl
        << "ÿ�ռ���ˮ����" << everyDayLoseWater << endl;
}
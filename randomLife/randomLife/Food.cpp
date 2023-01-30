#include<iostream>
#include<string>
#include "Food.h"
using namespace std;
Food::Food(string name_, int addFood_, int addWater_, int addMind_, int surpluesShelfLife_, int value_, int addWeight_,
    int addSugar_, int addSalt_, int addHealth_, int probabilitYOfaddHealth_, int probabilityOfDiarrhea_, int number_, int which_) {
    which = which_;
    number = number_;
    name.assign(name_);
    addFood = addFood_;
    surpluesShelfLife = surpluesShelfLife_;
    value = value_;
    addWater = addWater_;
    addMind = addMind_;
    addWeight = addWeight_;
    addSugar = addSugar_;
    addSalt = addSalt_;
    addHealth = addHealth_;
    probabilitYOfaddHealth = probabilitYOfaddHealth_;
    probabilityOfDiarrhea = probabilityOfDiarrhea_;
    nowSurpluesShelfLife = surpluesShelfLife;
}
Food::Food() {
    name.assign("*");
    addFood = 0;
    surpluesShelfLife = 0;
    value = 0;
    addWater = 0;
    addMind = 0;
    addWeight = 0;
    addSugar = 0;
    addSalt = 0;
    addHealth = 0;
    probabilitYOfaddHealth = 0;
    probabilityOfDiarrhea = 0;
    number = 0;
    which = 0;
    nowSurpluesShelfLife = surpluesShelfLife;
}
void Food::addMyFood ( string name_, int addFood_, int addWater_, int addMind_, int surpluesShelfLife_, int value_, int addWeight_,
    int addSugar_, int addSalt_, int addHealth_, int probabilitYOfaddHealth_, int probabilityOfDiarrhea_, int number_, int which_ ) {
    which = which_;
    number = number_;
    nowSurpluesShelfLife = 0;
    name.assign ( name_ );
    addFood = addFood_;
    surpluesShelfLife = surpluesShelfLife_;
    value = value_;
    addWater = addWater_;
    addMind = addMind_;
    addWeight = addWeight_;
    addSugar = addSugar_;
    addSalt = addSalt_;
    addHealth = addHealth_;
    probabilitYOfaddHealth = probabilitYOfaddHealth_;
    probabilityOfDiarrhea = probabilityOfDiarrhea_;
}
void Food::showItself( ) {
    cout << "���ƣ�" << name << "\t��ţ�" << which << endl;
    cout << "����ˮ��" << addWater << "\t���ӱ����ȣ�" << addFood << endl;
    cout << "����������" << addHealth << "\t�������飺" << addMind << endl;
    cout << "�������أ�" << addWeight << endl;
    cout << "�����Σ�" << addSalt << "\t�����ǣ�" << addSugar << endl;
    cout << "�����Ӹ��ʣ�" << probabilityOfDiarrhea << "%\t��������ֵ���ʣ�" << probabilitYOfaddHealth << "%\n";
    cout << "�����ڣ�" << nowSurpluesShelfLife << "\t��ֵ��" << value << endl;
    cout << "ʣ��������" << number << endl;
}

void Food::changeNumber( int k ) {
    surpluesShelfLife = surpluesShelfLife;
    number+= k;
    if ( number == 0 )
        nowSurpluesShelfLife = 0;
}
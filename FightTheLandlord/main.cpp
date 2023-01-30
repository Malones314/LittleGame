#include<bits/stdc++.h>
#include<windows.h>
#include"people.h"
using namespace std;
string kindsOfCard[38] = { "None", "1.����", "2.����", "3.����", "4.˫�ɻ�", "5.���ɻ�", "6.�ķɻ�", "7.��ɻ�", "8.���ɻ�",
                                        "9.����һ", "10.������", "11.˫�ɴ�����", "12.˫��˫��", "13.���ɴ�����", "14.��������",
                                        "15.�ķɴ�����", "16.�ķ��Ĵ�", "17.�Ĵ���", "18.�Ĵ�����", "19.���ԣ�3�ԣ�",
                                        "20.���ԣ�4�ԣ�", "21.���ԣ�5�ԣ�", "22.���ԣ�6�ԣ�", "23.���ԣ�7�ԣ�", "24.���ԣ�8�ԣ�",
                                        "25.���ԣ�9�ԣ�", "26.���ԣ�10�ԣ�", "27.˳�ӣ�5�ţ�", "28.˳�ӣ�6�ţ�", "29.˳�ӣ�7�ţ�",
                                        "30.˳�ӣ�8�ţ�","31.˳�ӣ�9�ţ�", "32.˳�ӣ�10�ţ�", "33.˳�ӣ�11�ţ�", "34.˳�ӣ�12�ţ�",
                                        "35.ը��", "36.��ը", "37.Ҫ����"};   //�±��1��ʼ
void getCards( int [16], int [21]);   //�õ���, �����ֶ���������
void firstShow();   //��ʼ����
bool game( int [], int [], int [], int, int []);   //����, ���ص�����Ӯ( 1Ӯ0��)
void kind();   //չʾ��������
string computerPuts( int card[21], string put, int* cardsKind, int* lastPut, int computer);   //���ص���ѡ��ĳ���, ���ĳ�������, ������һ�γ�����
string putCardsAtWill( int card[21], int* cardsKind);   //�����������, ���س�����, ���ĳ�������
void changeCards( int [], string , int);

int main(){
    //freopen("D:\\MyCandCPPspace\\test.txt","r",stdin);
    system("title FightTheLandlord");   //����cmd��������
    firstShow();   //�����ʼ��
    int totalCards[16] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1};   //�������ƶ�
    bool choice = true;   //�Ƿ������Ϸ
    bool broken = false;   //����Ƿ��Ʋ�
    srand(time(0));
    cout << "�Ƿ�׼������Ϸ?(1/0)" << endl;
    cin >> choice;
    if(choice){
        string CARD = "***34567890JQKA2GR";
        system("cls");
        long long money1, money2;
        people play[3];   //play[0]�����, play[1], play[2]�ǵ���
        play[0].changeMoney(2000);

        //��ʼ�����ֵĽ�Ǯ
        cout << "��ʼ�����ֵĳ�ʼ�ʽ� : " << endl;
        cin >> money1 >> money2;
        play[1].changeMoney( money1);
        play[2].changeMoney( money2);

        for( ; !broken && choice && play[1].getMoney() > 0 && play[2].getMoney() > 0; cin >> choice){   //����㻹ʣǮ�������Ϸ, ���Լ��ֶ��˳�

            //��Ϸ����
            system("cls");
            firstShow();
            play[0].show();

            int setMoney;
            cout << "�������̵ĶĽ� : \n";
            cin >> setMoney;

            int landlordcard[3];
            landlordcard[0] = rand()%15+1;
            landlordcard[1] = rand()%15+1;
            landlordcard[2] = rand()%15+1;

            //��֤�����Ʋ����������С�������Ŵ���
            if(landlordcard[0] == 14){
                while( landlordcard[1] == 14)
                    landlordcard[1] = rand()%15+1;
                if( landlordcard[1] == 15)
                    while( landlordcard[2] == 15 || landlordcard[2] == 14)
                        landlordcard[2] = rand()%15+1;
                else
                    while( landlordcard[2] == 14 )
                        landlordcard[2] = rand()%15+1;
            }else if( landlordcard[0] == 15){
                while( landlordcard[1] == 15)
                    landlordcard[1] = rand()%15+1;
                if( landlordcard[1] == 14)
                    while( landlordcard[2] == 15 || landlordcard[2] == 14)
                        landlordcard[2] = rand()%15+1;
                else
                    while( landlordcard[2] == 15 )
                        landlordcard[2] = rand()%15+1;
            }else if( landlordcard[1] == 15){
                while( landlordcard[2] == 15)
                    landlordcard[2] = rand()%16+1;
            }else if( landlordcard[1] == 16)
                while( landlordcard[2] == 16)
                    landlordcard[2] = rand()%16+1;

            totalCards[landlordcard[0]]--;
            totalCards[landlordcard[1]]--;
            totalCards[landlordcard[2]]--;

            //����
            getCards( totalCards, play[0].cards);
            getCards( totalCards, play[1].cards);
            getCards( totalCards, play[2].cards);

            //ȷ������
            play[0].landlord = false;
            play[1].landlord = false;
            play[2].landlord = false;
            int landlord = rand()%3;

            landlord = 0;

            play[landlord].landlord = true;
            int farmer[2] = {0};
            switch(landlord){
                case 0:
                    play[0].landlordTimes++;
                    farmer[0] = 1;
                    farmer[1] = 2;
                    break;
                case 1:
                    farmer[1] = 2;
                    break;
                case 2:
                    farmer[1] = 1;
            }

            //׷�ӵ�����
            play[landlord].cards[landlordcard[0]]++;
            play[landlord].cards[landlordcard[1]]++;
            play[landlord].cards[landlordcard[2]]++;

            play[landlord].cards[0] = 20;
            play[farmer[0]].cards[0] = 17;
            play[farmer[1]].cards[0] = 17;

            bool t;   //�洢�����Ƿ�Ӯ��
            t = game( play[0].cards, play[1].cards, play[2].cards, landlord, farmer);

            if(t){
                play[landlord].win(setMoney*2);
                play[farmer[0]].lose(setMoney);
                play[farmer[1]].lose(setMoney);
            }else{
                play[landlord].lose(setMoney*2);
                play[farmer[0]].win(setMoney);
                play[farmer[1]].win(setMoney);
            }

            if(play[0].getMoney() < 0){
                bool buyMoney;
                cout << "�Ƿ�Ҫ��ֵ��Ǯ ?(1/0)" <<endl;
                cin >> buyMoney;
                if( buyMoney){
                    long long secreat;
                    cout << "д��ʮ�����ֵĳ�ֵ����" << endl;
                    cin >> secreat;
                    if(!play[0].buyMoney(secreat))
                        broken = true;
                }else
                    broken = true;
            }else{
                cout << "����������� ? " << endl;
            }
        }

        //��Ϸ����
        Sleep(1000);
        system("cls");
        if( broken){
            cout << "you lose " << endl;
            Sleep(1000);
            system("cls");
        }
        cout << endl << "you : " << endl;
        cout << "��ʼ��� : 2000" << endl;
        play[0].show();
        cout << endl << "enemy1 : " << endl;
        cout << "��ʼ��� : " << money1 << endl;
        play[1].show();
        cout << endl << "enemy2 : " << endl;
        cout << "��ʼ��� : " << money2 << endl;
        play[2].show();
    }
    cout << "thanks for your playing " << endl;
    return 0;
}

void firstShow(){
    cout << "------------------------------------------------------------" << endl << endl;
    cout << "\t\tFight! The! Landlord!!!\t\t" << endl << endl;
    cout << "------------------------------------------------------------" << endl;
}

/** \brief ����
 *
 * \param tota[]Ϊ���ƶ�
 * \param cards[]Ϊ��һ��߶�����, cards[0]Ϊ��������
 */
void getCards( int total[16], int cards[21]){
    int i;
    int card;
    for( i = 0; i < 17; i++){
        do{
            card = rand()%15+1;
        }while( total[card] < 1);
        cards[card]++;
        total[card]--;
    }
    cards[17] = cards[15];
    cards[16] = cards[14];
    cards[14] = cards[1];
    cards[15] = cards[2];
    cards[1] = 0;
    cards[2] = 0;
    for( i = 3; i < 18; i++){
        if( cards[i] == 1)
            cards[1]++;
        else if( cards[i] == 2)
            cards[2]++;
        else if( cards[i] == 3)
            cards[18]++;
        else if( cards[i] == 4)
            cards[19]++;
    }
    if( cards[16]&&cards[17]){
        cards[1] -= 2;
        cards[19]++;
        cards[20]++;
    }
}

/** \brief ����
 *
 * \param card[]Ϊ����
 * \param landlordΪ������˭(0,1,2)
 * \return �����Ƿ�����
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////
bool game( int card0[21], int card1[21], int card2[21], int landlord, int farmer[2]){
    string CARD = "***34567890JQKA2GR";

    int card[3][21];
    int i;
    string put;
    int cardsKind;
    system("cls");

    for( i = 0; i < 21; i++){
        card[0][i] = card0[i];
        card[1][i] = card1[i];
        card[2][i] = card2[i];
    }
    int lastPut = landlord;   //�ж�����������˭������������ʱ��һ�����������Լ�������������
    for( int time = landlord; card[ landlord][0] != 0 && (card[ farmer[0]][0] != 0 && card[ farmer[1]][0] != 0); time++){
        string put_;
        /**/
        cout << "�����ǣ�" << landlord << endl;

        cout << "����1ʣ��" << card[1][0] << endl;
        cout << "ʣ\t3 4 5 6 7 8 9 10 J Q K A 2 С ��" << endl;
        printf("%d\t%d %d %d %d %d %d %d %d  %d %d %d %d %d %d  %d\n",
                card[1][0], card[1][3], card[1][4], card[1][5], card[1][6], card[1][7], card[1][8], card[1][9],
                card[1][10], card[1][11], card[1][12], card[1][13], card[1][14], card[1][15], card[1][16], card[1][17]);
        cout << "����2ʣ��" << card[2][0] << endl;
        cout << "ʣ\t3 4 5 6 7 8 9 10 J Q K A 2 С ��" << endl;
        printf("%d\t%d %d %d %d %d %d %d %d  %d %d %d %d %d %d  %d\n",
                card[2][0], card[2][3], card[2][4], card[2][5], card[2][6], card[2][7], card[2][8], card[2][9],
                card[2][10], card[2][11], card[2][12], card[2][13], card[2][14], card[2][15], card[2][16], card[2][17]);

        cout << "��ʣ��" << card[0][0] << endl;
        cout << "ʣ\t3 4 5 6 7 8 9 10 J Q K A 2 С ��" << endl;
        printf("%d\t%d %d %d %d %d %d %d %d  %d %d %d %d %d %d  %d\n",
                card[0][0], card[0][3], card[0][4], card[0][5], card[0][6], card[0][7], card[0][8], card[0][9],
                card[0][10], card[0][11], card[0][12], card[0][13], card[0][14], card[0][15], card[0][16], card[0][17]);
        /**/
        kind();
        cout << endl;
        if( time == 0){
            if( lastPut != 0){   //�Ѿ����˳����ƣ����ݳ������жϳ������
                if(  !put.empty() ){
                    cout << "��ң�" << lastPut << "�� �������� �� " << cardsKind << "  �����ƣ�" << put;
                    cout << endl << "��ѡ��ĳ������� ��";
                }else
                    cout << "�����������, ѡ����ĳ������� ��";
            }else
                cout << "�����������, ѡ����ĳ������� ��";
            cin >> cardsKind ;
            if(cardsKind != 37){
                cout << "����Ҫ������, 0����10 G����С�� R�������" << endl;
                cout << "ʾ����\n����A��ֻ3 A3\n�������Ķ��� 345\n��ʮ 0\n��ը GR" << endl;
                cin >> put_;
                lastPut = 0;
            }else
                put_ = "NoCardsCanPut";

        }else if( time == 1)
            put_.assign( computerPuts( card[1], put, &cardsKind, &lastPut, 1) );
        else if( time == 2)
            put_.assign( computerPuts( card[2], put, &cardsKind, &lastPut, 2) );

        if( put_ != "NoCardsCanPut" ){
            put.assign( put_);
            changeCards( card[ lastPut], put, cardsKind);
            if( lastPut == 2 )
                time = -1;
            else
                time = lastPut;
        }else
            time = lastPut - 1;
        system("cls");
    }
    if( card[landlord][0])   //��������ʣ��
        return 0;
    else
        return 1;
}
void kind(){
    for( int i = 1; i < 37; i+=3)
        cout << kindsOfCard[i] << "\t" << kindsOfCard[i+1] << "\t" << kindsOfCard[i+2] << "\t\n";
    cout << kindsOfCard[37] << endl;
}

string computerPuts( int card[21], string put, int* cardsKind, int* lastPut, int computer){
//���û�пɳ����Ʒ���NoCardsCanPut, ��������Դ���������

    string CARD = "***34567890JQKA2GR";
    string put_ = "*";
    if( *lastPut == computer){   //�ϴγ��Ƶ������Ҫ����, �����������
        put_.assign( putCardsAtWill( card, cardsKind) );
    }else{   //�����ϴεĳ���ѡ�����
        bool follow = false;
        int kind_ = *cardsKind;
        int i, j, k;
        if( kind_ == 1){   //����
            if( card[1] > 0)
                for( i = CARD.find(put[0])+1; i < 18; i++)
                    if( card[i]==1){
                        put_[0] = CARD[i];
                        follow = true;
                        break;
                    }
        }else if( kind_ == 2){   //����
            if( card[2] > 0)
                for( i = put[0]-'0'+1; i < 18; i++)
                    if( card[i]==2){
                        put_[0] = CARD[i];
                        follow = true;
                        break;
                    }
        }else if( kind_ > 2 && kind_ < 17){   //�ɻ�

            int Length = 0;
            if( kind_ < 9){   //�����ɻ�
                Length = kind_ - 2;   //�ɻ�����
                put_.assign( Length, '*');
            }else{
                if( kind_%2 == 1)
                    Length = (kind_ - 7) / 2;
                else
                    Length = (kind_ - 8) / 2;
                put_.assign( Length*2, '*');
            }
            if( card[18] > Length){   //���ŵĸ������ڷɻ��ĸ���
                for( i = CARD.find(put[0])+1; i < 16; i++){
                    for( j = 0; j < Length;j++)
                        if( card[i+j] < 3)
                            break;
                    if( j == Length){
                        for( k = 0; k < Length; k++)
                            put_[k] = CARD[i+k];
                        follow = true;
                        break;
                    }
                }
                if( follow && kind_ > 8){
                    if( kind_ %2 == 1){   //�ɻ�������
                        if( card[1] < Length){   //�ɻ������ڵ�����
                            follow = false;
                        }else{
                            for( i = 3; i < 16; i++ )
                                if( card[i] == 1)
                                    put_[k++] = CARD[i];
                            if( k < Length * 2 - 1)
                                follow = false;
                        }
                    }else{   //�ɻ�������
                        if( card[2] < Length){   //�ɻ������ڶ�����
                            follow = false;
                        }else{
                            for( i = 3; i < 16; i++ )
                                if( card[i] == 2)
                                    put_[k++] = CARD[i];
                            if( k < Length * 2 - 1)
                                follow = false;
                        }
                    }
                }
            }
        }else if( kind_ == 17){   //�Ĵ���
            if( card[19] > 0){
                follow = true;
                if( card[19] == 1 && card[20])
                    follow = false;
                else{
                    if( card[1] > 0){
                        for( i = CARD.find(put[0])+1; i < 15; i++)
                            if(card[i] == 4){
                                put_[0] = CARD[i];
                                break;
                            }
                        for( i = 3; i < 15; i++)
                            if( card[i] == 1){
                                put_[1] = CARD[i];
                                break;
                            }
                    }else
                        follow = false;
                }
            }
        }else if( kind_ == 18){   //�Ĵ�����
            if( card[19] > 0){
                follow = true;
                if( card[19] == 1 && card[20])
                    follow = false;
                else{
                    if( card[2] > 0){
                        for( i = CARD.find(put[0])+1; i < 15; i++)
                            if( card[i] == 4){
                                put_[0] = CARD[i];
                                break;
                            }
                        for( i = 3; i < 15; i++)
                            if( card[i] == 2){
                                put_[1] = CARD[i];
                                break;
                            }
                    }
                    else
                        follow = false;
                }
            }
        }else if( kind_ > 18 && kind_ < 27){   //����
            int Length = 0;
            if( card[2] > 2){
                Length = put.length();
                for( i = CARD.find(put[0])+1; i < 15; i++){
                    if( card[i] > 1 && card[i] != 4)
                        for( j = 0; j < Length; j++)
                            if( card[i+j] < 2)
                                break;
                    if( j == Length){
                        follow = true;
                        break;
                    }
                }
                if( follow){
                    for( j = 0; j < Length; j++)
                        put_[j] = CARD[i+j];
                }
            }
        }else if( kind_ > 26 && kind_ < 35){   //˳��
            if( card[1] > 4){
                int Length = 0;
                Length = put.length();
                for( i = CARD.find(put[0])+1; i < 15; i++){
                    if( card[i] > 0 && card[i] != 4)
                        for( j = 0; j < Length; j++)
                            if( card[i+j] < 1)
                                break;
                    if( j == Length){
                        follow = true;
                        break;
                    }
                }
                if( follow){
                    for( j = 0; j < Length; j++)
                        put_[j] = CARD[i+j];
                }
            }
        }else if( kind_ == 35 ){   //ը��
            if(card[19] > 0){
                for( i = CARD.find(put[0])+1; i < 15; i++)
                    if( card[i] == 4){
                        follow = true;
                        break;
                    }
            }
            if( follow )
                put_[0] = CARD[i];

        }else if( kind_ == 36){   //��ը
            follow = false;
        }
        if( follow ){   //Ҫ����
            *lastPut = computer;
        }else{   //Ҫ����
            put_.assign("NoCardsCanPut");
        }
    }
    return put_;
}

string putCardsAtWill( int card[21], int* cardsKind){   //�������, ��֤�����������, �е���3���3�ȳ�, ����put
    string CARD = "***34567890JQKA2GR";
    string put = "0";
    string danzhi = "*";
    string duizi = "*";
    string threeOrFour[2] = { "4", "3" };
    int liandui_ = 0;
    int liandui_Begin = 0;
    int liandui_1 = 0;   //���ڼ�¼�·��ֵ�����, �Ƚ������ĸ�����, ���������
    int liandui_Begin1 = 0;
    string liandui = "*";
    int shunzi_ = 0;
    int shunzi_Begin = 0;
    int shunzi_1 = 0;   //���ڼ�¼�·��ֵ�˳��, �Ƚ������ĸ�����, ���������
    int shunzi_Begin1 = 0;
    string shunzi = "*";
    int feiji_ = 0;
    string feiji = "*";
    int feiji_Begin = 0;
    int feiji_1 = 0;
    int feiji_Begin1 = 0;
    int l;
    string sidaier = "***";
    string sidailiangdui = "***";
    int dan[2] = {0};
    int shuang[2] = {0};

    int j , i;
    int mostCard = 0;   //��¼����������
    int bestChoice = 0;   //��¼��ѷ���


    if( card[0] == 4 && card[19] && card[20] == 0 ){
        bestChoice = 35;
        mostCard = 4;
        for( i = 3; i < 16; i++)
            if( card[i] == 4){
                put[0] = CARD[i];
                break;
            }
    }else if( card[0] == 2 && card[20] ){
        bestChoice = 36;
        mostCard = 2;
        put = "GR" ;
    }else{
        //����

        if(card[2] > 2){   //����������2ʱ�ſ���������
            for( i = 3; i < 15; i++)
                if( card[i] > 1 && card[i]!=4){
                    if( liandui_Begin + liandui_ == i)
                        liandui_++;
                    else
                        if( liandui_Begin == 0){
                            liandui_Begin = i;
                            liandui_ = 1;
                        }else{
                            if( liandui_Begin1 == 0){
                                liandui_1 = 1;
                                liandui_Begin1 = i;
                            }else if( liandui_Begin1 + liandui_1 == i){
                                liandui_1++;
                            }else{
                                liandui_1 = 0;
                                liandui_Begin1 = 0;
                            }
                        }
                    if( liandui_1 > liandui_){   //���·��ֵ����Ը���ʱ, ����
                        liandui_ = liandui_1;
                        liandui_Begin = liandui_Begin1;
                        liandui_1 = 0;
                        liandui_Begin1 = 0;
                    }
                }

            if( liandui_ > 2){
                liandui.assign( liandui_, '*');
                for( j = liandui_Begin; j < liandui_Begin+liandui_; j++)
                    liandui[ j - liandui_Begin] = CARD[j];
            }
            bestChoice = liandui_+16;
            mostCard = liandui_*2;
        }

        //�ɻ�

        if(card[18] > 0){   //����������0�ſ����зɻ��������Ŵ�һ�Ż��߶���
            for( i = 3; i < 15; i++){
                if( card[i] == 3){
                    if( feiji_ + feiji_Begin == i)
                        feiji_++;
                    else{
                        if( feiji_ + feiji_Begin == 0){
                            feiji_ = 1;
                            feiji_Begin = i;
                        }else
                            if( feiji_Begin1 == 0){
                                feiji_Begin1 = i;
                                feiji_1 = 1;
                            }else if( feiji_Begin1 + feiji_1 == i)
                                feiji_1++;
                    }
                }
                if( feiji_1 > feiji_){
                    feiji_ = feiji_1;
                    feiji_Begin = feiji_Begin1;
                    feiji_1 = 0;
                    feiji_Begin1 = 0;
                }
            }
            if( feiji_ > 0){   //���ɻ�������0ʱ
                feiji.assign( feiji_,'*');
                for( j = feiji_Begin; j < feiji_Begin+feiji_; j++)
                    feiji[j-feiji_Begin] = CARD[j];
                if( feiji_ <= card[2]){   //�ɻ���<=������, ���ܳ�3�Ŵ�2��
                    int duizi_[feiji_];
                    for( j = 3, l = 0; j < feiji_Begin && l < feiji_; j++)
                        if( card[j] == 2){
                            duizi_[l] = j;
                            l++;
                        }
                    for( j = feiji_Begin+feiji_; j < 16 && l < feiji_; j++)
                        if( card[j] == 2){
                            duizi_[l] = j;
                            l++;
                        }
                    if( feiji_*5 > mostCard){
                        mostCard = feiji_*5;
                        bestChoice = 8 + feiji_*2;
                        feiji.insert( feiji_, feiji);
                        for( j = feiji_, i = 0; j < feiji_*2; j++, i++)
                            feiji[j] = CARD[duizi_[i]];
                    }
                }else if(feiji_ <= card[1]){   //�ɻ���<=������, ���ܳ�3�Ŵ�1��
                    int danzhang_[feiji_];
                    for( j = 3, l = 0; j < feiji_Begin && l < feiji_; j++)
                        if( card[j] == 1){
                            danzhang_[l] = j;
                            l++;
                        }
                    for( j = feiji_Begin+feiji_; j < 18 && l < feiji_; j++)
                        if( card[j] == 1){
                            danzhang_[l] = j;
                            l++;
                        }
                    if( feiji_*4 > mostCard){
                        mostCard = feiji_*4;
                        bestChoice = 7 + feiji_*2;
                        feiji.insert( feiji_, feiji);
                        for( j = feiji_, i = 0; j < feiji_*2; j++, i++)
                            feiji[j] = CARD[danzhang_[i]];
                    }
                }else   //ֻ�ܳ��ѵķɻ�
                    if( feiji_*3 > mostCard){
                        mostCard = feiji_*3;
                        bestChoice = feiji_+2;
                    }
            }
        }

        if(card[1] > 4){   //����������4ʱ�ſ�����˳��
            for( i = 3; i < 15; i++)
                if( card[i] > 0 && card[i]!=4){
                    if( shunzi_Begin + shunzi_ == i)
                        shunzi_++;
                    else
                        if( shunzi_Begin == 0){
                            shunzi_Begin = i;
                            shunzi_ = 1;
                        }else{
                            if( shunzi_Begin1 == 0){
                                shunzi_1 = 1;
                                shunzi_Begin1 = i;
                            }else if( shunzi_Begin1 + shunzi_1 == i){
                                shunzi_1++;
                            }
                        }
                    if( shunzi_1 > shunzi_){   //���·��ֵ�˳�Ӹ���ʱ, ����
                        shunzi_ = shunzi_1;
                        shunzi_Begin = shunzi_Begin1;
                        shunzi_1 = 0;
                        shunzi_Begin1 = 0;
                    }
                }

            if( shunzi_ > 4){
                shunzi.assign( shunzi_, '*');
                for( j = shunzi_Begin; j < shunzi_Begin+shunzi_; j++)
                    shunzi[ j - shunzi_Begin] = CARD[j];
            }
            if( mostCard < shunzi_){
                bestChoice = shunzi_+22;
                mostCard = shunzi_;
            }
        }

        if( ( mostCard == 0) && ( ( card[3] == 1 || card[4] == 1 ) || ( card[3] == 2 || card[4] == 2 ) ) ){   //��ǰ��ķ�ʽ������,���� 3 4
            if(card[3] == 1 || card[4] == 1){
                danzhi = threeOrFour[ card[3] ];
                bestChoice = 1;
            }else if( card[3] == 2 || card[4] == 2){
                duizi = threeOrFour[ card[3] ];
                bestChoice = 2;
            }
        }else{

            //�Ĵ���(��)

            if( card[19] - card[20] > 0){   //��ը��
                if( card[2] > 1)
                    for( i = 3, j = 0; i < 16 && j < 2; i++){
                        if( card[i] == 2){
                            shuang[j] = i;
                            j++;
                        }
                    }
                else if( card[1] > 1)
                    for( i = 3, j = 0, l = 0; i < 18 && j < 2 ; i++){
                        if( card[i] == 1){
                            dan[j] = i;
                            j++;
                        }
                    }
                if( shuang[1]){   //����������
                    for( i = 3; i < 18; i++)
                        if( card[i] == 4)
                            break;
                    sidailiangdui[0] = CARD[i];
                    sidailiangdui[1] = CARD[shuang[0]];
                    sidailiangdui[2] = CARD[shuang[1]];
                    if( mostCard < 8){
                        mostCard = 8;
                        bestChoice = 18;
                    }
                }else if( dan[1]){   //����������
                    for( i = 3; i < 18; i++)
                        if( card[i] == 4)
                            break;
                    sidaier[0] = CARD[i];
                    sidaier[1] = CARD[dan[0]];
                    sidaier[2] = CARD[dan[1]];
                    if( mostCard < 6){
                        mostCard = 6;
                        bestChoice = 17;
                    }
                }
            }

        }

        if( card[2] > 0){
            for( i = 4; i < 16; i++)
                if( card[i] == 2 && bestChoice < 2){
                    duizi = CARD[i];
                    bestChoice = 2;
                    break;
                }
        }

        if( card[1] > 0){
            for( i = 4; i < 16; i++)
                if( card[i] == 1 && bestChoice < 1){
                    danzhi = CARD[i];
                    bestChoice = 1;
                    break;
                }
        }

    }

    //Ѱ�ҳ��Ƹ������ķ���
    if( bestChoice == 1){
        put = danzhi;
    }else if( bestChoice == 2){
        put = duizi;
    }else if( bestChoice > 18 && bestChoice < 27){   //���������
        put.assign( liandui);
    }else if( bestChoice > 26 && bestChoice < 35){   //�����˳��
        put.assign( shunzi);
    }else if( bestChoice > 2 && bestChoice < 17 ){   //����Ƿɻ�
        put.assign( feiji);
    }else if( bestChoice == 17  ){   //������Ĵ���
        put.assign( sidaier);
    }else if( bestChoice == 18){   //������Ĵ�����
        put.assign( sidailiangdui);
    }

    *cardsKind = bestChoice;
    return put;
}

void changeCards( int card[21], string put, int cardsKind){
    string CARD = "***34567890JQKA2GR";
    int n[9] = {0};
    int i = -1;
    if( cardsKind == 1){
        n[0] = CARD.find( put[0]);
        card[n[0]]--;
        card[0]--;
    }else if( cardsKind == 2){
        n[0] = CARD.find( put[0]);
        card[n[0]] -= 2;
        card[0] -= 2;
    }else if( cardsKind >= 3 && cardsKind <= 8){
        n[0] = CARD.find( put[0]);
        for( int i = 0 ; i < cardsKind - 2; i++)
            card[n[0]+i] -= 3;
        card[0] -= ( cardsKind - 2)*3;
    }else if( cardsKind > 8 && cardsKind < 17){
        if( cardsKind % 2){
            int L = ( cardsKind - 7) / 2;
            for( i = 0; i < L; i++){
                n[i] = CARD.find( put[i]);
                card[n[i]] -= 3;
                n[i+L] = CARD.find( put[i+L]);
                card[n[i+L]]--;
            }
            card[0] -= L*4;
        }else{
            int L = ( cardsKind - 8) / 2;
            for( i = 0; i < L; i++){
                n[i] = CARD.find( put[i]);
                card[n[i]] -= 3;
                n[i+L] = CARD.find( put[i+L]);
                card[n[i+L]] -= 2;
            }
            card[0] -= L*4;
        }
    }else if( cardsKind == 17){
        n[0] = CARD.find( put[0]);
        card[n[0]] -= 4;
        n[1] = CARD.find( put[1]);
        card[n[1]] --;
        n[2] = CARD.find( put[2]);
        card[n[2]] --;
        card[0] -= 6;
    }else if( cardsKind == 18){
        n[0] = CARD.find( put[0]);
        card[n[0]] -= 4;
        n[1] = CARD.find( put[1]);
        card[n[1]] -= 2;
        n[2] = CARD.find( put[2]);
        card[n[2]] -= 2;
        card[0] -= 8;
    }else if( cardsKind > 18 && cardsKind < 27){
        n[0] = CARD.find( put[0]);
        for( i = 0; i < cardsKind-16; i++)
            card[n[0]+i] -= 2;
        card[0] -= (cardsKind - 16)*2;
    }else if( cardsKind > 26 && cardsKind < 35){
        n[0] = CARD.find( put[0]);
        for( i = 0; i < cardsKind - 22; i++)
            card[n[0]+i]--;
        card[0] -=  (cardsKind - 22);
    }else if( cardsKind == 35){
        n[0] = CARD.find( put[0]);
        card[n[0]] -= 4;
        card[0] -= 4;
    }else if( cardsKind == 36){
        card[15]--;
        card[16]--;
        card[0] -= 2;
    }
}

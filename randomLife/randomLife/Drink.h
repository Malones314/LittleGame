#include<iostream>
#include<string>
#ifndef DRINK_H
#define DRINK_H
using namespace std;
class Drink {
public:
    int addWater = 0;   //�ɼӵ�ˮ��
    int addHealth = 0;   //����ʱΪ��������
    int surpluesShelfLife = 0;   //��ʼ������
    int nowSurpluesShelfLife = 0;
    int value;   //�����ʱ���������̵�
    int addMind;   //�ɼӵ�����
    int addFood;
    int addWeight;
    int addSugar;
    int probabilityOfDiarrhea;   //eg��25������ٷ�֮25
    int probabilitYOfaddHealth;
    int number;
    int which;
    string name;
    Drink(string name_, int addWater_, int addhealth, int addMind, int surpluesShelfLife, int value_, int addFood_,
        int addWeight_, int addSugar_, int probabilityOfDiarrhea_, int probabilitYOfaddHealth_, int number_, int which_);
    Drink();
    void addMyDrink(string name_, int addWater_, int addhealth, int addMind, int surpluesShelfLife, int value_, int addFood_,
        int addWeight_, int addSugar_, int probabilityOfDiarrhea_, int probabilitYOfaddHealth_, int number_, int which_);
    void showItself();
    void changeNumber ( int k );
};

#endif // DRINK_H

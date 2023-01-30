#include<iostream>
#include<string>
#ifndef PEOPLE_H
#define PEOPLE_H
#include"Drink.h"
#include"Food.h"
#include"Treatment.h"

using namespace std;
//��������Ǯ������
//���ࣺ
//���飺������мӳɣ�ʳ����㣬ˮ�����㣬��ϲ����������ɼ����飬���������(���ǰ���Ϊ���죬�������Լ�����)������Ϊ0�޷���������
//���ã�"����", "�Է�", "����", "��ˮ", "˯��", "������", "�滭", "�鷨"
class People {
    public:
    People ( );
    void showYourself ( );
    void sleep ( );   //˯��
    void changeMoney ( double money_ );
    void changeMind ( int );
    void changeWeight ( int );
    void changeHealth ( int k );
    void watchTV ( );   //������
    void getDrink ( Drink* myDrink );   //��ˮ������ˮ����
    void getFood ( Food* myFood );   //��ʳ�����ʳ������
    void getTreatment ( Treatment* myTreatment, bool withCard );   //���ƣ�������������, ����ǰ�ж�Ǯ�Ƿ��㹻
    void getDisease ( int kind );   //���������벡������
    void doExercise ( );   //���˶�
    void getHobby ( int );
    int mostPhysicalStrength;   //�������ޣ�ÿ����10��1�������ޣ�û����50��1������
    int mostHealth;   //�������ޣ�ֻ��ͨ��������������
    int health;   //����
    int physicalStrength;   //����
    double food;   //������
    double water;   //����ֵ
    int hobby;   //����
    double money;   //��Ǯ
    int mind;   //����
    double weight;   //����
    int sugar;   //����
    int salt;   //����
    int lifeTime;   //������ʣ������
    int dayInPrison;   //�ڼ����ĵڼ�����
    int caseFragment;   //������Ƭ
    int TVNumber;   //���ӻ�����
    bool haveStore;   //�Ƿ�ӵ��С����
    double everyDayLosePhysicalStrength;
    double everyDayLoseHealth;
    double everyDayLoseFood;
    double everyDayLoseWater;
    int addMind;   //ֻ����Ȥ�Ƿ���ʱ��Ϊ5,���κ��¶���5
    class Disease {
        public:
        Disease ( );
        void addMyDisease ( string name_, int now_, int most_, int level_, int whenCure_, int number_ );
        void showItself ( );
        Disease ( string name_, int now_, int most_, int level_, int whenCure_, int number_ );
        void getDisease ( People* you, int k, int kind );   //kΪ���ӵ�now, kindΪ����
        string name;
        int level = 0;
        int number;
        int now = 0;
        int most = 0;   //������������һ���ȼ�
        int whenCure = 0;   //���жȸ�Ѫѹ����ͨ�����������жȹ�������   10���һ���ȼ����߶Ⱥ;���ֻ�ܳ�ҩ����
    };
    Disease myDisease [6];
};
#endif // PEOPLE_H

#include<iostream>
#include<string>
#ifndef TREATMENT_H
#define TREATMENT_H
using namespace std;
//ʹ��ҩƷ,����
//�������������ѡ��˫����Ǯ���迨Ƭ
//���ֺ͹���ֻ����������
class Treatment {
public:
    Treatment();
    Treatment(string name_, int addHealth_, int value_, int number);
    int addHealth = 0;
    int value = 0;
    int which = 0;   //0���� 1���� 2��Ѫѹ 3������ 5����
    int number = 0;
    void addMyTreatment(string name_, int addHealth_, int value_, int number_, int which_);
    void showItself();
    void changeNumber ( int k );
    string name;
};

#endif // TREATMENT_H

#include<string>
#ifndef DISEASE_H
#define DISEASE_H
#include"People.h"
using namespace std;
/*
������
0����ʱ��+1����0.5 +1���ۼ�10���� 10���ָ� ����2��ָ�
���� ���-5���ж�-10���ض�-30������-50��������
1���򲡣������ۼ�����������10��һ��
���� ���-1���ж�-5���ض�-10������-15��ÿ�죩
2��Ѫѹ��һ������������50��һ��
���� ���-1���ж�-5���ض�-10������-15��ÿ�죩
��ҩ��һ��
3�����ӣ�������
������ ���-1 �ж�-5 �ض�-10 ����-20
4���֣��ۼƷ��ֳ���100�÷��֣�������-20������������-5��
���� ���-5 �ж�-10 �ض�-20 ����-30��ÿ�죩���� ����-20��������
*/
class Disease {
public:
    Disease();
    void addMyDisease( string name_, int now_, int most_, int level_, int whenCure_, int number_);
    void showItself();
    Disease( string name_, int now_, int most_, int level_, int whenCure_, int number_);
    void getDisease ( People* you, int k, int kind );   //kΪ���ӵ�now, kindΪ����
    string name;
    int level = 0;
    int number;
    int now = 0;
    int most = 0;   //������������һ���ȼ�
    int whenCure = 0;   //���жȸ�Ѫѹ����ͨ�����������жȹ�������   10���һ���ȼ����߶Ⱥ;���ֻ�ܳ�ҩ����
};

#endif // DISEASE_H

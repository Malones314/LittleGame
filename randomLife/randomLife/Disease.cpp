#include<string>
#include<iostream>
#include "Disease.h"
#include"People.h"
using namespace std;
Disease::Disease() {
    number = 0;
    name.assign("*");
    level = 0;
    now = 0;
    most = 0;   //������������һ���ȼ�
    whenCure = 0;   //���жȸ�Ѫѹ����ͨ�����������жȹ�������   10���һ���ȼ����߶Ⱥ;���ֻ�ܳ�ҩ����
}

Disease::Disease( string name_, int now_, int most_, int level_, int whenCure_, int number_) {
    number = number_;
    now = now_;
    most = most_;
    level = level_;
    whenCure = whenCure_;
    name.assign(name_);
}

void Disease::addMyDisease(string name_, int now_, int most_, int level_, int whenCure_, int number_) {
    number = number_;
    name.assign(name_);
    now = now_;
    most = most_;
    level = level_;
    whenCure = whenCure_;
}

void Disease::showItself() {
    string Level[5] = { "�������޲�","���", "�ж�", "�ض�", "����" };
    cout << "�������ƣ�" << name << endl
        << "�����ۼƣ�" << now << "\t�ۼƶ��ٻ�����" << most << endl
        << "���ڵȼ���" << Level[level] << "\tʲôʱ�����ƺã�" << whenCure;
}

void Disease::getDisease ( People* you, int k , int kind) {
    now += k;
    if ( now > most  ) { 
        now -= most;
        you->getDisease ( kind );
    }
}

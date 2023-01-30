#include<string>
#ifndef DISEASE_H
#define DISEASE_H
#include"People.h"
using namespace std;
/*
疾病：
0工作时候+1锻炼0.5 +1，累计10轻伤 10天后恢复 治疗2天恢复
健康 轻度-5，中度-10，重度-30，绝境-50（触发）
1糖尿病：两周累计摄糖量超过10加一度
健康 轻度-1，中度-5，重度-10，绝境-15（每天）
2高血压：一周摄盐量超过50加一度
健康 轻度-1，中度-5，重度-10，绝境-15（每天）
吃药降一度
3拉肚子（触发）
饱腹度 轻度-1 中度-5 重度-10 绝境-20
4肥胖：累计肥胖超过100得肥胖，锻炼（-20），工作减（-5）
体力 轻度-5 中度-10 重度-20 绝境-30（每天）健康 绝境-20（触发）
*/
class Disease {
public:
    Disease();
    void addMyDisease( string name_, int now_, int most_, int level_, int whenCure_, int number_);
    void showItself();
    Disease( string name_, int now_, int most_, int level_, int whenCure_, int number_);
    void getDisease ( People* you, int k, int kind );   //k为增加的now, kind为种类
    string name;
    int level = 0;
    int number;
    int now = 0;
    int most = 0;   //超过量则上升一个等级
    int whenCure = 0;   //轻中度高血压糖尿病通过锻炼，轻中度工作受伤   10天减一个等级。高度和绝境只能吃药手术
};

#endif // DISEASE_H

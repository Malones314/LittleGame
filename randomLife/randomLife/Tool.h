#include<iostream>
#include<string>
#ifndef TOOL_H
#define TOOL_H
using namespace std;
//���ӻ����ܵõ�����ϸ���ص���Ƭ(50�����ռ���ȫ����ϴˢԩ��)

class Tool {
public:
    Tool();
    int which;
    int times = 0;   //������ʹ�ü���
    int totalTimes = 0;
    int value = 0;
    int number;
    void addMyTool(string name_, int totalTimes_, int value_, int number_, int which_);
    Tool(string name_, int totalTimes_, int value_, int number_, int which_);
    void showItself();
    void plusOne ( );
    void decrease ( );
    void useIt ( int k );
    string name;
};

#endif // TOOL_H

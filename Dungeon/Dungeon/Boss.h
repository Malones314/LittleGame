#ifndef BOSS_H
#define BOSS_H
#include "Human.h"
class Boss :   //����������Լ�����һ�Σ�ÿ�Լ�����һ�μ���Ӣ��50%ĿǰѪ�����Լ�����20%�����˺�3�غ�
    public Human {
    private:
        int beHatedTimes;
        double damageReduction;   //�˺�����(0-1֮��)
        int damageReductionTimes;   //�˺�����ʣ��غ�, Ĭ��3�غ�
    public:
        void addBeHatedTimes ( );
        void resetBeHatedTimes ( );
        int getBeHatedTimes ( );
        double getDamageReduction( );
        void newDamageReduction ( double newNumber);
        int getDamageReductionTimes ( );
        void reduceDamageReductionTimes ( );
        void resetDamageReductionTimes ( );
        Boss ( );
        Boss ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_ );
};



#endif // !BOSS_H

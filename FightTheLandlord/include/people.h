#ifndef PEOPLE_H
#define PEOPLE_H
class people{
    public:
        bool landlord;
        int cards[21];
        //cards[0]Ϊ������, 1Ϊ���Ÿ���, 2Ϊ���Ӹ���, 18Ϊ���Ÿ���, 19Ϊը����, 20Ϊ�Ƿ�����ը

        people();
        people(long long );
        long long getMoney();
        int getWins();
        int getLoses();
        bool buyMoney(long long secret_);
        void show();
        void changeMoney(long long);
        void win( int );
        int landlordTimes;
        int gameTimes;
        void lose( int);
    private:
        long long money;
        int wins;
        int loses;
        int secret;

};

#endif // PEOPLE_H

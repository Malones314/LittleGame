#ifndef SWORD_H
#define SWORD_H
#include<string>
using namespace std;
class Sword {
	private:
		int defence;
		int attack;
		int value;
	public:
		int getValue ( );
		int getDefence ( );
		int getAttack ( );
		Sword ( );
		Sword ( int addDefence_, int addAttack_, int value );
		void newName ( string newName );
		void newAttack ( int newNumber );
		void newDefence ( int newNumber );
		void newValue ( int newNumber );
		void newSword ( Sword* newSword );
};
#endif

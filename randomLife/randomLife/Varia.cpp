#include "Varia.h"
#include<iostream>
#include<string>
using namespace std;
Varia::Varia ( ) {
	value = 0;
	name.assign ( "*" );
	number = 0;
	which = 0;
}
Varia::Varia ( string name_, int value_, int number_, int which_ ) {
	name.assign ( name_ );
	number = number_;
	which = which_;
	value = value_;
}
void Varia::addMyVaria ( string name_, int value_, int number_, int which_ ) {
	name.assign ( name_ );
	number = number_;
	which = which_;
	value = value_;
}
void Varia::changeNumber ( int k ) {
	number += k;
}
void Varia::showItself ( ) {
	cout << name << "\t���� " << number << endl;
	cout << "��ţ�" << which << "\t��ֵ��" << value << endl;
}
/****************************************
* Environment: visual studio 2019 
* Author: ��� ( Malones)
* Date: 2021/5/19
*****************************************/
/*������
*���δ��أ�ÿ���в�ͬ�������50��������boss
* ע��ʹ��EasyXͼ�ο�
**/
/*������־��
* 5/19 
* ��˼���
* дHuman��
* Monster��
* 
* 5/20
* дHero��
* ��˼���
* дShield��
* Sword��
* Backpacking����
* 
* 5/22
* дShield��
* Sword��
* Backpacking��
* Boss��
* 
* 5/23
* дDungeon���
* 
* 5/24
* дDungeon���
* 
* 5/25
* дDungeon���
* 
* 5/26
* ��������ͼƬ��
* дdrawGraphDisplayPhotograph������
* д��ͨ����
* 
* 5/28
* д��ͨ����
* дnewFloorInformation����
* 
* 5/29
* дchangeThisFloodMonsterInformation����
* д��ͨ���ܼ�����
* 
* 5/30
* д��ͨ���ܺ�����,
* дgoToTheShop����
* 
* 5/31
* �Ľ�Hero��
* дhitTheMonster����
* �Ľ���ͨ������
* �Ľ�main������monster����
* 
* 6/1
* д��ͨ������
* ɾ��дdrawGraphDisplayPhotograph������
* �Ľ���ͨ����ʾ����
* 
* 6/2
* ����ͼƬ
* ������ͨ����ʾ
* boos����ʾ
* дcheckPlayer����
* 
* 6/5
* ��˼��ʾϸ��
* дshowAttribute����
* дclickBackpacking����
* 
* 6/6
* ���̵�ͱ���չʾ��Ʒ�ϲ�Ϊһ��shopAndBackpackingShowMoneyAndGoods����
* 
* 6/10
* дshowMonsterInformation����
* �����ͨ��
* ��˼boss��
* 
* 6/11
* дboss��,
* дshowBoss����
* дhitBoss����
* 
* 6/13
* ����boss��
* д��Ϸ��β
* ���ԸĴ�
* 
* 7/13
* ���������λ�ô���
* δ��ɸ���
* 
* 7/14
* ����������������ֵ�һϵ�д���
* �����µĵ��һ����귭�������ذ壬
* �����ذ����������ڻ�Ϊת�þ���
***/
#include<iostream>
#include"Backpacking.h"
#include"Boss.h"
#include"Hero.h"
#include"Human.h"
#include"Monster.h"
#include"Shield.h"
#include"Sword.h"
#include"HealthPot.h"
#include<graphics.h>
#include<string>
#include<Windows.h>
using namespace std;

const int X0 = 0;
const int Y0 = 0;
const int Width = 300;   //ͼ������
const int Hight = 650;   //ͼ����߶�

const int sideLength1 = 100;   //С����߳�, С�ֵ�ͼƬ�߳�

//��ʼ���濪ʼ�˳�����
const int beginLeftX = 100;			const int beginHighY = 350;
const int beginRightX = 200;		const int beginLowY = 425;
const int outLeftX = 100;			const int outHighY = 450;
const int outRightX = 100;			const int outLowY = 525;

//��ͨ������
//�������У���1��12
const int graphDisplay1X = 0;				const int graphDisplay2X = 100;			const int graphDisplay3X = 200;
const int graphDisplay1Y = 0;				const int graphDisplay2Y = 0;				const int graphDisplay3Y = 0;

const int graphDisplay4X = 0;				const int graphDisplay5X = 100;			const int graphDisplay6X = 200;
const int graphDisplay4Y = 100;			const int graphDisplay5Y = 100;			const int graphDisplay6Y = 100;

const int graphDisplay7X = 0;				const int graphDisplay8X = 100;			const int graphDisplay9X = 200;
const int graphDisplay7Y = 200;			const int graphDisplay8Y = 200;			const int graphDisplay9Y = 200;

const int graphDisplay10X = 0;			const int graphDisplay11X = 100;		const int graphDisplay12X = 200;
const int graphDisplay10Y = 300;		const int graphDisplay11Y = 300;		const int graphDisplay12Y = 300;

//�̵�ͱ���������ʾ��Ǯ
POINT moneyPolygon [4] = { { 225, 25 }, { 299, 25 }, { 299, 55 }, { 225, 55 } };

//����������ʾ�ȣ�����50
const int sideLength2 = 50;
const int bloodX = 75;							const double bloodY = 437.5;
const int attackX = 50;						const int attackY = 487.5;
const int defenceX = 50;						const int defenceY = 537.5;
const int expX = 75;							const int expY = 612.5;
const int floorLevelX = 250;				const int floorLevelY = 437.5;
const int levelX = 250;							const int levelY = 487.5;
const int backpackingX = 175;			const int backpackingY = 525;
const int backpackingWidth = 75;		const int backpackingHight = 50;

//�̵ꡢ�������棬����100
const int shopAndBackpackingGoodsX = 100;							const int shopAndBackpackingSwordY = 50;
const int shopAndBackpackingShieldY = 150;							const int shopAndBackpackingHealthPotY = 250;
const int shopAndBackpackingButtonX = 25;							const int shopAndBackpackingButtonY = 300;
const int shopAndBackpackingButtonWidth = 25;						const int shopAndBackpackingButtonHight = 50;
const int shopAndBackpackingShowMoneyX = 225;					const int shopAndBackpackingShowMoneyY = 25;
const int shopAndBackpackingGoodsNumberX = 150;
const int shopAndBackpackingSwordNumberY = 125;
const int shopAndBackpackingShieldNumberY = 225;
const int shopAndBackpackingHealthPotNumberY = 325;

//��ͨ����ʾ������Ϣ
const int monsterInformationX = 110;					const int monsterInformationBloodY = 100;
const int monsterInformationAttackY = 150;			const int monsterInformationDefenceY = 200;

//boss
const int bossX = 25;							const int bossY = 2;
const int bossWidth = 175;					const int bossHigh = 225;
const int bossBloodX = 50;					const int bossBloodY = 225;
const int bossBeHittedTimesX = 50;		const int bossBeHittedTimesY = 250;

POINT clearBlood [4] = { { 75, 425 }, { 175, 425 }, { 175, 475 }, { 75, 475 } };
POINT clearFloorLevel [4] = { { 250, 425 }, { 294, 425 }, { 294, 475 }, { 250, 475 } };
POINT clearAttack [4] = { { 50, 475 }, { 150, 475 }, { 150, 525 }, { 50, 525 } };
POINT clearLevel [4] = { { 250, 475 }, { 294, 475 }, { 294, 525 }, { 250, 525 } };
POINT clearDefence [4] = { { 50, 525 }, { 150, 525 }, { 150, 575 }, { 50, 575 } };
POINT clearExp [4] = { { 100, 600 }, { 225, 600 }, { 225, 647 }, { 100, 647 } };
POINT clearBossBlood [4] = { { 50, 225 }, { 200, 225 }, { 200, 250 }, { 20, 250 } };
POINT clearBossBeHittedTimes [4] = { { 25, 250 }, { 100, 250 }, { 100, 275 }, { 25, 275 } };

//�Ľ�����
POINT displayPoint [4] = { { X0, Y0 }, { Width, Y0 }, { Width, Hight }, { X0, Hight } };

//��ʾҳ���ĸ��������꣨Χס12�����ӵĶ��ǣ�
POINT displayFourPoint [4] = { { X0, Y0 }, { Width, Y0 }, { Width, 4 * sideLength1 }, { X0, 4 * sideLength1 } };

//��ͨ��ÿ�����ӵ��Ľ�����
POINT displayEachGridPoint [4][3][4] = {
	//��1��
	{
		{ { X0, Y0 }, { X0 + sideLength1, Y0 }, { X0 + sideLength1, Y0 + sideLength1 }, { X0, Y0 + sideLength1 } },			//��1��
	{ { X0 + sideLength1, Y0 }, { X0 + 2 * sideLength1, Y0 }, { X0 + 2 * sideLength1, Y0 + sideLength1 }, { X0 + sideLength1, Y0 + sideLength1 } },			//��2��
	{ { X0 + 2 * sideLength1, Y0 }, { X0 + 3 * sideLength1, Y0 }, { X0 + 3 * sideLength1, Y0 + sideLength1 }, { X0 + 2 * sideLength1, Y0 + sideLength1 } },			//��3��
	},
	//��2��
	{
		{ { X0, Y0 + sideLength1 }, { X0 + sideLength1, Y0 + sideLength1 }, { X0 + sideLength1, Y0 + 2 * sideLength1 }, { X0, Y0 + 2 * sideLength1 } },			//��1��
	{ { X0 + sideLength1, Y0 + sideLength1 }, { X0 + 2 * sideLength1, Y0 + sideLength1 }, { X0 + 2 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + sideLength1, Y0 + 2 * sideLength1 } },			//��2��
	{ { X0 + 2 * sideLength1, Y0 + sideLength1 }, { X0 + 3 * sideLength1, Y0 + sideLength1 }, { X0 + 3 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 2 * sideLength1 } },			//��3��
	},
	//��3��
	{
		{ { X0, Y0 + 2 * sideLength1 }, { X0 + sideLength1, Y0 + 2 * sideLength1 }, { X0 + sideLength1, Y0 + 3 * sideLength1 }, { X0, Y0 + 3 * sideLength1 } },			//��1��
	{ { X0 + sideLength1, Y0 + 2 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + sideLength1, Y0 + 3 * sideLength1 } },			//��2��
	{ { X0 + 2 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + 3 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + 3 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 3 * sideLength1 } },			//��3��
	},
	//��4��
	{
		{ { X0, Y0 + 3 * sideLength1 }, { X0 + sideLength1, Y0 + 3 * sideLength1 }, { X0 + sideLength1, Y0 + 4 * sideLength1 }, { X0, Y0 + 4 * sideLength1 } },			//��1��
	{ { X0 + sideLength1, Y0 + 3 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 4 * sideLength1 }, { X0 + sideLength1, Y0 + 4 * sideLength1 } },			//��2��
	{ { X0 + 2 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + 3 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + 3 * sideLength1, Y0 + 4 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 4 * sideLength1 } },			//��3��
	}
};

//boss����
POINT bossInformationPoint [4] = { { 50, 225 }, { 200, 225 }, { 200, 275 }, { 50, 275 } };

//��ʼ����ͨ��С�֡���Ʒ����Ϣ
void newFloorInformation ( int graphInformation [ ][4] );

//����С�ֵ�������Ϣ
void changeThisFloorMonsterInformation ( Monster* monster, int level, int monsterKind );

//��ҹ���
void hitTheMonster ( Hero* hero, Monster* monster );

//�������Ƿ���������������
void checkPlayer ( Hero* player, int floorLevel );

//ȥ�̵�
void goToTheShop ( Backpacking* backpacking, HealthPot* healthPot, Shield* shield, Sword* sword );

//���������ť
void clickBackpacking ( Hero* hero, Backpacking* backpacking, Sword* sword, Shield* shield, HealthPot* healthPot );
//�̵�ͱ���չʾ��Ǯ����Ʒ
void shopAndBackpackingShowMoneyAndGoods ( Backpacking* backpacking );

//��ʾ������Ϣ
void showAttribute ( Hero* hero, int level );

//���㽣���ܺ�Ѫƿ������
void changeShieldSwordAndHealthPot ( Shield* shield, Sword* sword, HealthPot* healthPot, int level );

//չʾ�������ϸ��Ϣ
void showMonsterInformation ( IMAGE monsterImage, Monster* monster );

//����boss
void hitBoss ( Hero* hero, Boss* boss );

//չʾboss����
void showBoss ( Boss* boss );

int main ( ) {
	initgraph ( Width, Hight );   
	setbkcolor ( WHITE );
	settextcolor ( BLACK );
	cleardevice ( );
	settextstyle ( 25, 0, _T("����") );
	int graphInformation [3][4] = { 0 };			// 0Ϊ�� 1�����1, 2�����2, 3�����3��4Ѫ��5���飬6��/��(11)��7ͨ��/�̵�(10)��8��һ�㣬9���壨����10%Ѫ��
																	// ͨ����10%���֣�����ֱ��ǰ����51�㣨5%�����ߺ���10�㣨95%��
																	// �̵꣨90%���ֺ�ͨ�����⣩
																	// 5��С�֣�2��Ѫƿ��1������ƿ��1����һ�㣬1��װ����1�����壬1��ͨ��/�̵�
																	//1��1��2��2��2��3
	
		//ͼƬ����
	
	IMAGE firstPhotograph;				//��ʼ������Ϸ����
	IMAGE storyPhotograph;			//��Ϸ����˵������
	IMAGE winPhotography;				//ʤ������
	IMAGE losePhotography;			//ʧ�ܻ���

	IMAGE unOpenFloorPhotograph;		//δ�㿪�ĵذ�
	IMAGE monsterPhotograph [4];				//С��1,2,3,4
	IMAGE shopPhotograph;					//�̵�
	IMAGE shieldPhotograph;					//����
	IMAGE swordPhotograph;					//��
	IMAGE healthPotPhotograph;				//Ѫƿ
	IMAGE expPotPhotograph;					//����ƿ
	IMAGE travelPhotograph;					//ͨ��
	IMAGE trapPhotograph;						//����
	IMAGE nextFloorPhotograph;				//��һ��

	IMAGE graphDisplayPhotograph;		//��ͨ����ʾ����   
	IMAGE shopDisplayPhotograph;			//�̵����ʾ����
	IMAGE bossDisplayPhotograph;			//boss����ʾ����
	IMAGE backpackingPhotograph;		//������ʾ����

	//����
	Boss boss ( 1500, 1500, 500, 100 );
	Backpacking backpacking ( 0, 0, 0, 0 );
	HealthPot healthPot ( 15, 2 );
	Hero hero ( 100, 100, 10, 3, 0, 100, 1 );
	//����1��������0.2������2������50%��Ϊ�أ�����3Ѫ����0.5
	Monster monster [4];										//monster[0]����
	Shield shield ( 0, 0, 1 );
	Sword sword ( 0, 0, 1 );

	//���ñ���
	int floorLevel = 0;							//����
	int playerAttack;						//��ұ��㹥��
	int playerDefence;					//��ұ������
	int playerImmediateBlood;		//��Ҽ�ʱѪ��
	int playerImmediateExp;			//��Ҽ�ʱ���飬ֻ��ǰ����һ��ʱ��������	

	//���
	MOUSEMSG mouse;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//����ͼƬ   ͼƬ�ļ���D:\DungeonPhotograph��D:\\DungeonPhotograph\\ .png
	loadimage ( &firstPhotograph, _T ( "D:\\DungeonPhotograph\\firstPhotograph.png" ), Width, Hight );
	loadimage ( &storyPhotograph, _T ( "D:\\DungeonPhotograph\\storyPhotograph.png" ), Width, Hight );
	loadimage ( &winPhotography, _T ( "D:\\DungeonPhotograph\\winPhotography.png" ), Width, Hight );
	loadimage ( &losePhotography, _T ( "D:\\DungeonPhotograph\\losePhotography.png" ), Width, Hight );
	loadimage ( &unOpenFloorPhotograph, _T ( "D:\\DungeonPhotograph\\unOpenFloorPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &monsterPhotograph[1], _T ( "D:\\DungeonPhotograph\\monster1Photograph.png" ), sideLength1, sideLength1 );
	loadimage ( &monsterPhotograph[2], _T ( "D:\\DungeonPhotograph\\monster2Photograph.png" ), sideLength1, sideLength1 );
	loadimage ( &monsterPhotograph[3], _T ( "D:\\DungeonPhotograph\\monster3Photograph.png" ), sideLength1, sideLength1 );
	loadimage ( &shopPhotograph, _T ( "D:\\DungeonPhotograph\\shopPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &shieldPhotograph, _T ( "D:\\DungeonPhotograph\\shieldPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &swordPhotograph, _T ( "D:\\DungeonPhotograph\\swordPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &healthPotPhotograph, _T ( "D:\\DungeonPhotograph\\healthPotPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &expPotPhotograph, _T ( "D:\\DungeonPhotograph\\expPotPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &travelPhotograph, _T ( "D:\\DungeonPhotograph\\travelPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &trapPhotograph, _T ( "D:\\DungeonPhotograph\\trapPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &nextFloorPhotograph, _T ( "D:\\DungeonPhotograph\\nextFloorPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &graphDisplayPhotograph, _T ( "D:\\DungeonPhotograph\\graphDisplayPhotograph.png" ), Width, Hight );
	loadimage ( &shopDisplayPhotograph, _T ( "D:\\DungeonPhotograph\\shopDisplayPhotograph.png" ), Width, Hight );
	loadimage ( &bossDisplayPhotograph, _T ( "D:\\DungeonPhotograph\\bossDisplayPhotograph.png" ), Width, Hight );
	loadimage ( &backpackingPhotograph, _T ( "D:\\DungeonPhotograph\\backpackingPhotograph.png" ), Width, Hight );
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
	putimage ( 0, 0, &firstPhotograph );		//չʾ��ʼ�����滭��
 
	//�ж�����Ƿ�������ʼ��ʼ
	
	//bool nextYes = false;
	//while ( 1 ) {
	//	mouse = GetMouseMsg ( );
	//	if ( mouse.mkLButton ) {
	//		if ( mouse.x >= beginLeftX && mouse.x <= beginRightX && mouse.y <= beginLowY && mouse.y >= beginHighY ) {
	//			nextYes = true;
	//			break;
	//		} else if ( mouse.x >= outLeftX && mouse.x <= outRightX && mouse.y <= outLowY && mouse.y >= outHighY ) {
	//			nextYes = false;
	//			break;
	//		}
	//	}
	//}
	//if ( nextYes == false )		//���"�˳�"ֱ���˳�����
	//	return 0;
	

	//��Ϸ��ʼ
	putimage ( X0, Y0, &storyPhotograph );						//չʾ���»���
	bool playerDead = false;
	int mouseX, mouseY;
	do {

		playerImmediateBlood = hero.getImmediateBlood ( );
		playerAttack = hero.getBasicAttack ( );
		playerDefence = hero.getBasicDefence ( );
		playerImmediateExp = hero.getImmeditateExp ( );
		floorLevel++;
		checkPlayer ( &hero, floorLevel );
		changeShieldSwordAndHealthPot ( &shield, &sword, &healthPot, floorLevel );
		Sleep ( 2000 );
		clearpolygon ( displayPoint, 4 );

		if ( floorLevel < 50 ) {
			putimage ( X0, Y0, &graphDisplayPhotograph );		//��ͨ��չʾ
			showAttribute ( &hero, floorLevel );
			changeThisFloorMonsterInformation ( &monster [1], floorLevel, 1 );
			changeThisFloorMonsterInformation ( &monster [2], floorLevel, 2 );
			changeThisFloorMonsterInformation ( &monster [3], floorLevel, 3 );

			bool clickNextFloor = false;   //����Ƿ�������һ�㡱
			bool firstClickGraph [4][3] = { 0 };
			int graphNumberX = -1, graphNumberY = -1;		//���ڱ����������λ����ͨ��������ĸ�����
			newFloorInformation ( graphInformation );

			while ( clickNextFloor == false ) {
				clearpolygon ( displayFourPoint, 4 );
				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 0; j < 3; j++ ) {
						if ( firstClickGraph [i][j] == 0 ) {		//��û���� 
							putimage ( X0 + sideLength1 * j, Y0 + sideLength1 * i, &unOpenFloorPhotograph );
						} else {
							if ( graphInformation [i][j] < 4 && graphInformation [i][j] > 0 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &monsterPhotograph [graphInformation [i][j]] );
							} else if ( graphInformation [i][j] == 4 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &healthPotPhotograph );
							} else if ( graphInformation [i][j] == 5 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &expPotPhotograph );
							} else if ( graphInformation [i][j] == 6 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &swordPhotograph );
							} else if ( graphInformation [i][j] == 7 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &travelPhotograph );
							} else if ( graphInformation [i][j] == 8 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &nextFloorPhotograph );
							} else if ( graphInformation [i][j] == 10 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &shopPhotograph );
							} else if ( graphInformation [i][j] == 11 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &shieldPhotograph );
							}
						}
					}
				}
				
				do {
					mouse = GetMouseMsg ( );
					mouseX = mouse.x;
					mouseY = mouse.y;
				} while ( !mouse.mkLButton && !mouse.mkRButton );
				
				/*mouse.mkLButton = 1;
				mouseX = 32;
				mouseY = 320;*/
				if ( mouse.mkLButton ) {

					//2021.10.20��graphNumberX��graphNumberY��ֵ����
					graphNumberX = ( int ) ( mouseX / 100 );
					graphNumberY = ( int ) ( mouseY / 100 );

					showAttribute ( &hero, floorLevel );		//ÿ��ˢ���������ֵ
					if ( mouseY < 400 ) {							//���������12�����ڲ�
						if ( firstClickGraph [graphNumberY][graphNumberX] == 0 ) {
							firstClickGraph [graphNumberY][graphNumberX] = 1;
							Sleep ( 100 );
							clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );	//�������ĸ����ϵ�ͼƬ
							if ( graphInformation [graphNumberY][graphNumberX] > 0 && graphInformation [graphNumberY][graphNumberX] < 4 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &monsterPhotograph [graphInformation [graphNumberY][graphNumberX]] );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 4 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &healthPotPhotograph );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 5 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &expPotPhotograph );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 6 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &swordPhotograph );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 7 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &travelPhotograph );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 8 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &nextFloorPhotograph );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 9 ) {   //��������������Ѫ
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &trapPhotograph );
								playerImmediateBlood -= ( hero.getBasicTotalBlood ( ) * 0.9 );
								hero.newImmediateBlood ( playerImmediateBlood );
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
								graphInformation [graphNumberY][graphNumberX] = 0;
							} else if ( graphInformation [graphNumberY][graphNumberX] == 10 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &shopPhotograph );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 11 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &shieldPhotograph );
							}
						} else {
							if ( graphInformation [graphNumberY][graphNumberX] < 4 && graphInformation [graphNumberY][graphNumberX] > 0 ) {		//���
								hitTheMonster ( &hero, &monster [graphInformation [graphNumberY][graphNumberX]] );
								playerImmediateBlood = hero.getImmediateBlood ( );
								if ( monster [graphInformation [graphNumberY][graphNumberX]].getImmediateBlood ( ) <= 0 ) {			//��һ��ܹ���
									hero.changeImmeditateExp ( monster [graphInformation [graphNumberY][graphNumberX]].getExp ( ) );
									graphInformation [graphNumberY][graphNumberX] = 0;				//������ӱ�Ϊ��
									Sleep ( 100 );
									clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
									if ( monster [graphInformation [graphNumberY][graphNumberX]].getDeadLeft ( ) == 1 ) {					//�ɷ��뱳����Ѫƿ
										Sleep ( 10 );
										putimage ( sideLength1 * graphNumberX, sideLength1 * graphNumberY, &healthPotPhotograph );
										Sleep ( 1000 );
										clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
										backpacking.changeHealthPotNumber ( 1 );
									} else {
										int randNumber = 0;
										randNumber = rand ( ) % 2;
										if ( randNumber == 1 ) {									//��
											Sleep ( 10 );
											putimage ( sideLength1 * graphNumberX, sideLength1 * graphNumberY, &swordPhotograph );
											Sleep ( 1000 );
											clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
											backpacking.changeSwordNumber ( 1 );
										} else {																//��
											Sleep ( 10 );
											putimage ( sideLength1 * graphNumberX, sideLength1 * graphNumberY, &shieldPhotograph );
											Sleep ( 1000 );
											clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
											backpacking.changeShieldNumber ( 1 );
										}
									}
									changeThisFloorMonsterInformation ( &monster [graphInformation [graphNumberY][graphNumberX]], floorLevel, graphInformation [graphNumberY][graphNumberX] );
								} else if ( playerImmediateBlood <= 0 ) {				//�������
									playerDead = true;
									break;
								}
							} else if ( graphInformation [graphNumberY][graphNumberX] == 4 ) {						//ֱ�Ӽ�Ѫ
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
								playerImmediateBlood += healthPot.getBlood ( );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 5 ) {						//ֱ�ӼӾ���
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
								playerImmediateExp += monster [1].getExp ( );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 6 ) {						//��
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
								backpacking.changeSwordNumber ( 1 );
							} else if ( graphInformation [graphNumberY][graphNumberX] == 7 ) {						//ͨ��
								int randNumber = 0;
								randNumber = rand ( ) % 100;
								if ( randNumber > 5 ) {   //����10��
									if ( floorLevel > 10 ) {
										floorLevel -= 11;
										clickNextFloor = true;
									} else {
										floorLevel = 0;
										clickNextFloor = true;
									}
								} else {								//ֱ��50��
									floorLevel = 50;
									clickNextFloor = true;
								}
							} else if ( graphInformation [graphNumberY][graphNumberX] == 8 ) {					//��һ��
								clickNextFloor = true;
							} else if ( graphInformation [graphNumberY][graphNumberX] == 10 ) {					//�̵�
								clearpolygon ( displayPoint, 4 );			
								putimage ( X0, Y0, &shopPhotograph );
								showAttribute ( &hero, floorLevel );
								goToTheShop ( &backpacking, &healthPot, &shield, &sword );

								clickNextFloor = true;
							} else if ( graphInformation [graphNumberY][graphNumberX] == 11 ) {					//��
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberY][graphNumberX], 4 );
								backpacking.changeShieldNumber ( 1 );
							}
						}

					} else if ( mouseX >= backpackingX && mouseX <= backpackingX + backpackingWidth&& mouseY >= backpackingY && mouseY <= backpackingY + backpackingHight ) {
					
						clearpolygon ( displayPoint, 4 );
						putimage ( X0,Y0, &backpackingPhotograph );
						showAttribute ( &hero, floorLevel );
						clickBackpacking ( &hero, &backpacking, &sword, &shield, &healthPot );
					
					}

				} else if ( mouse.mkRButton ) {					//�鿴2s�������ϸ��Ϣ

					graphNumberX = ( int ) mouseX / 100;
					graphNumberY = ( int ) mouseY / 100;
					int row = graphNumberY;
					int column = graphNumberX;
					graphNumberX = row;
					graphNumberY = column;
					if ( mouseY < 400 ) {			//�����12�����ӷ�Χ��
						if ( graphInformation [graphNumberX][graphNumberY] < 4 && graphInformation [graphNumberX][graphNumberY] > 0 ) {		//���ͣ���ڹ�����
							clearpolygon ( displayFourPoint, 4 );
							showMonsterInformation ( monsterPhotograph [graphInformation [graphNumberX][graphNumberY]], &monster [graphInformation [graphNumberX][graphNumberY]] );
							clearpolygon ( displayFourPoint, 4 );
						}
					}

				}

			}


		} else if ( floorLevel == 50 ) {    //�����̵�

			goToTheShop ( &backpacking, &healthPot, &shield, &sword );
			
		}else	{   //boss
			//const int bossX = 25;							const int bossY = 2;
			//const int bossWidth = 175;					const int bossHigh = 225;
			//const int bossBloodX = 50;					const int bossBloodY = 225;
			//const int bossBeHittedTimesX = 50;		const int bossBeHittedTimesY = 250;
			bool bossDead = false;
			clearpolygon ( displayPoint, 4 );
			putimage ( X0, Y0, &bossDisplayPhotograph );
			
			while ( ( bossDead == false ) && ( playerDead == false ) ) {
				
				mouse = GetMouseMsg ( );
				mouseX = mouse.x;
				mouseY = mouse.y;
				if ( mouseX > bossX && mouseX < bossX + bossWidth && mouseY > bossY && mouseY < bossY + bossHigh ) {		//��boss
					hitBoss ( &hero, &boss );
					playerDead = ( hero.getImmediateBlood ( ) > 0 ) ? false : true;
					bossDead = ( boss.getImmediateBlood ( ) > 0 ) ? false : true;
				}else if ( mouseX >= backpackingX && mouseX <= backpackingX + backpackingWidth && mouseY >= backpackingY && mouseY <= backpackingY + backpackingHight ) {

					clearpolygon ( displayPoint, 4 );
					putimage ( X0, Y0, &backpackingPhotograph );
					showAttribute ( &hero, floorLevel );
					clickBackpacking ( &hero, &backpacking, &sword, &shield, &healthPot );
					clearpolygon ( displayPoint, 4 );
					putimage ( X0, Y0, &bossDisplayPhotograph );
				}
			}

		}
	} while ( ( playerDead == false ) && floorLevel < 52 );
	clearpolygon ( displayPoint, 4 );
	if ( playerDead == false )
		putimage ( X0, Y0, &winPhotography );
	else
		putimage ( X0, Y0, &losePhotography );
	Sleep ( 3000 );
	closegraph ( );
	return 0;
}

void newFloorInformation ( int graphInformation [3][4] ) {
	// 0Ϊ�� 1�����1, 2�����2, 3�����3��4Ѫ��5���飬6��/��(11)��7ͨ��/�̵�(10)��8��һ�㣬9���壨����10%Ѫ��
	// ͨ����10%���֣�����ֱ��ǰ����51�㣨5%�����ߺ���10�㣨95%��
	// �̵꣨90%���ֺ�ͨ�����⣩
	// 5��С�֣�2��Ѫƿ��1������ƿ��1����һ�㣬1��װ����1�����壬1��ͨ��/�̵�
	//1��1��2��2��2��3
	int information [10] = { 0, 1, 2, 2, 2, 1, 1, 1, 1, 1 };
	int total = 12;
	int i = 0;
	int r = 0;
	int c = 0;
	for ( ; total; ) {
		i = rand ( ) % 9 + 1;
		if ( information [i] > 0 ) {
			graphInformation [r][c++] = i;
			information [i]--;
			if ( i == 6 ) { 
				i = rand ( ) % 2;
				if( i ==1 )
					graphInformation [r - 1][c] = 11;
			} else if ( i == 7 ) {			//�ж���ͨ�������̵�
				i = rand ( ) % 100;
				if ( i > 4 )
					graphInformation [r - 1][c] = 10;
			}
			if ( c == 2 ) {
				c= 0;
				r++;
			}
			total--;
		}
	}
}
void changeThisFloorMonsterInformation ( Monster* monster, int level, int monsterKind ) {
	monster->newBasicDefence ( 0 );
	int randNumber = 0;
	randNumber = rand ( ) % 4 - 2;
	double blood = ( ( double ) level / 10 + 1 ) * 1.5 * ( ( double ) 100 + randNumber );
	if ( monsterKind == 3 )
		blood *= 1.5;
	monster->newBasicTotalBlood ( blood );
	monster->newImmediateBlood ( monster->getBasicTotalBlood ( ) );
	randNumber = rand ( ) % 20 - 10;
	double attack = ( ( double ) level / 10 + 1 ) * 0.1 * ( ( double ) 100 + randNumber );
	if ( monsterKind == 1 ) 
		attack *= 1.2;
	else if ( monsterKind == 2 ) {
		attack *= 0.5;
		monster->newBasicDefence ( attack );
	}
	monster->newBasicAttack ( attack );
	monster->newExp ( level / 10 + 10 );
	randNumber = rand ( ) % 2 + 1;
	monster->newDeadLeft ( randNumber );
}

void goToTheShop ( Backpacking* backpacking, HealthPot* healthPot, Shield* shield, Sword* sword ) {
	bool clickNext = false;
	MOUSEMSG mouse;
	int mouseX, mouseY;
	while ( clickNext == false ) {
		shopAndBackpackingShowMoneyAndGoods ( backpacking );
		mouse = GetMouseMsg ( );
		mouseX = mouse.x;
		mouseY = mouse.y;
		if ( mouseX >= shopAndBackpackingGoodsX && mouseX <= shopAndBackpackingGoodsX + sideLength1 ) {				//���������ܡ�Ѫƿ
			if ( mouseY >= shopAndBackpackingSwordY && mouseY <= shopAndBackpackingSwordY + sideLength1 ) {
				if ( mouse.mkLButton ) {														//�����
					if ( backpacking->getMoney ( ) >= 2 * sword->getValue ( ) ) {
						backpacking->changeMoney ( -2 * sword->getValue ( ) );
						backpacking->changeSwordNumber ( 1 );
					}
				} else if ( mouse.mkRButton ) {											//�Ҽ���
					if ( backpacking->getSwordNumber ( ) > 0 ) {
						backpacking->changeSwordNumber ( -1 );
						backpacking->changeMoney ( sword->getValue ( ) );
					}
				}
			}else if ( mouseY >= shopAndBackpackingShieldY && mouseY <= shopAndBackpackingShieldY + sideLength1 ) {
				if ( mouse.mkLButton ) {
					if ( backpacking->getMoney ( ) >= shield->getValue ( ) * 2 ) {
						backpacking->changeMoney ( -2 * shield->getValue ( ) );
						backpacking->changeShieldNumber ( 1 );
					}
				} else if ( mouse.mkRButton ) {
					if ( backpacking->getSwordNumber ( ) > 0 ) {
						backpacking->changeShieldNumber ( -1 );
						backpacking->changeMoney ( shield->getValue ( ) );
					}
				}
			}else if ( mouseY >= shopAndBackpackingHealthPotY && mouseY <= shopAndBackpackingHealthPotY + sideLength1 ) {
				if ( mouse.mkLButton ) {
					if ( backpacking->getMoney ( ) > 3 ) {
						backpacking->changeMoney ( -4 );
						backpacking->changeHealthPotNumber ( 1 );
					}
				} else if ( mouse.mkRButton ) {
					if ( backpacking->getHealthPotNumber ( ) > 0 ) {
						backpacking->changeHealthPotNumber ( -1 );
						backpacking->changeMoney ( 2 );
					}
				}
			}
		} else if ( mouseX <= shopAndBackpackingButtonX && mouseX >= shopAndBackpackingButtonX + shopAndBackpackingButtonWidth
			&& mouseY >= shopAndBackpackingButtonY && mouseY <= shopAndBackpackingButtonY + shopAndBackpackingButtonHight && mouse.mkLButton )		
			//�����һ��
			clickNext = true;
	}
}

void changeShieldSwordAndHealthPot ( Shield* shield, Sword* sword, HealthPot* healthPot, int level ) {
	if ( level < 10 )
		healthPot->newBlood ( 15 );
	else if ( level < 20 )
		healthPot->newBlood ( 50 );
	else
		healthPot->changeBlood ( 50 );
	if ( level < 20 ) {
		shield->newAttack ( 6 );
		shield->newDefence ( 1 );
		shield->newAttack ( 1 );
		shield->newDefence ( 4 );
	} else if ( level < 40 ) {
		shield->newAttack ( 15 );
		shield->newDefence ( 2 );
		shield->newAttack ( 2 );
		shield->newDefence ( 10 );
	} else if ( level < 50 ) {
		shield->newAttack ( 30 );
		shield->newDefence ( 5 );
		shield->newAttack ( 5 );
		shield->newDefence ( 20 );
	} else {
		shield->newAttack ( 50 );
		shield->newDefence ( 10 );
		shield->newAttack ( 10 );
		shield->newDefence ( 30 );
	}
}

void hitTheMonster ( Hero* hero, Monster* monster ) {
	int decreaseBlood;
	decreaseBlood = monster->getBasicAttack ( ) - hero->getBasicDefence ( );
	hero->changeImmediateBlood ( -decreaseBlood );
	decreaseBlood = hero->getBasicAttack ( ) - monster->getBasicDefence ( );
	monster->changeImmediateBlood ( -decreaseBlood );
}
void checkPlayer ( Hero* player, int floorLevel ) {
	if ( player->getImmeditateExp ( ) >= player->getTotalExp ( ) ) {				//��������
		player->changeBasicAttack ( ( 1 + floorLevel / 20 ) * 5 );
		player->changeBasicDefence ( ( 1 + floorLevel / 20 ) * 2 );
		player->changeBasicTotalBlood ( ( 1 + floorLevel / 20 ) * 20 );
		player->newImmediateBlood ( player->getBasicTotalBlood ( ) );
		player->changeImmeditateExp ( player->getImmeditateExp ( ) - player->getTotalExp ( ) );
		player->newTotalExp ( );
	}
}
void clickBackpacking ( Hero* hero, Backpacking* backpacking, Sword* sword, Shield* shield, HealthPot* healthPot ) {
	MOUSEMSG mouse;
	bool clickReturn = false;
	shopAndBackpackingShowMoneyAndGoods ( backpacking );
	int mouseX, mouseY;
	while ( clickReturn == false ) {
		mouse = GetMouseMsg ( );
		mouseX = mouse.x;
		mouseY = mouse.y;
		if ( mouseX >= shopAndBackpackingGoodsX && mouseX <= shopAndBackpackingGoodsX + sideLength1 ) {
			if ( mouseY >= shopAndBackpackingSwordY && mouseY <= shopAndBackpackingSwordY + sideLength1 ) {
				if ( backpacking->getSwordNumber ( ) > 0 ) {						//������������0
					if ( mouse.mkLButton ) {												//�����
						if ( hero->getWithSword ( ) == 0 ) {
							hero->changeBasicAttack ( sword->getAttack ( ) );
							hero->changeBasicDefence ( sword->getDefence ( ) );
							backpacking->changeSwordNumber ( -1 );
							hero->changeWithSword ( );
						}
					}
				}
			} else if ( mouseY >= shopAndBackpackingShieldY && mouseY <= shopAndBackpackingShieldY + sideLength1 ) { 
				if ( backpacking->getShieldNumber ( ) > 0 ) {
					if ( mouse.mkLButton ) {												//�����
						if ( hero->getWithShield ( ) == 0 ) {
							hero->changeBasicAttack ( shield->getAttack ( ) );
							hero->changeBasicDefence ( shield->getDefence ( ) );
							backpacking->changeShieldNumber ( -1 );
							hero->changeWithShield ( );
						}
					}
				}
			}else  if ( mouseY >= shopAndBackpackingShieldY && mouseY <= shopAndBackpackingShieldY + sideLength1 ) {
				if ( backpacking->getHealthPotNumber ( ) > 0 ) {
					if ( mouse.mkLButton ) {												//�����Ѫƿ
						hero->changeImmediateBlood ( healthPot->getBlood ( ) );
					}
				}
			}
		} else if ( mouseX >= shopAndBackpackingButtonX && mouseX <= shopAndBackpackingButtonX + shopAndBackpackingButtonWidth ) 
			if ( mouseY >= shopAndBackpackingButtonY && mouseY <= shopAndBackpackingButtonY + shopAndBackpackingButtonHight ) 
				clickReturn = true;
	}
}

void showAttribute ( Hero* hero, int level ) {
	clearpolygon ( clearBlood, 4 );
	clearpolygon ( clearAttack, 4 );
	clearpolygon ( clearDefence, 4 );
	clearpolygon ( clearExp, 4 );
	clearpolygon ( clearLevel, 4 );
	TCHAR number [20];
	swprintf_s ( number, _T ( "%d/%d" ), hero->getImmediateBlood ( ), hero->getBasicTotalBlood ( ) );
	outtextxy ( bloodX, bloodY, number );
	swprintf_s ( number, _T ( "%d" ), hero->getBasicAttack ( ) );
	outtextxy ( attackX, attackY, number );
	swprintf_s ( number, _T ( "%d" ), hero->getBasicDefence ( ) );
	outtextxy ( defenceX, defenceY, number );
	swprintf_s ( number, _T ( "%d/%d" ), hero->getImmeditateExp ( ), hero->getTotalExp ( ) );
	outtextxy ( expX, expY, number );
	swprintf_s ( number, _T ( "%d" ), level );
	outtextxy ( floorLevelX, floorLevelY, number );
	swprintf_s ( number, _T ( "%d" ), hero->getLevel ( ) );
	outtextxy ( levelX, levelY, number );
}

void shopAndBackpackingShowMoneyAndGoods ( Backpacking* backpacking ) {
	TCHAR s [20];
	clearpolygon ( moneyPolygon, 4 );
	_stprintf_s ( s, _T ( "%d" ), backpacking->getMoney ( ) );
	outtextxy ( shopAndBackpackingShowMoneyX, shopAndBackpackingShowMoneyY, s );
	_stprintf_s ( s, _T ( "%d" ), backpacking->getHealthPotNumber ( ) );
	outtextxy ( shopAndBackpackingGoodsNumberX, shopAndBackpackingHealthPotNumberY, s );
	_stprintf_s ( s, _T ( "%d" ), backpacking->getShieldNumber ( ) );
	outtextxy ( shopAndBackpackingGoodsNumberX, shopAndBackpackingShieldNumberY, s );
	_stprintf_s ( s, _T ( "%d" ), backpacking->getSwordNumber ( ) );
	outtextxy ( shopAndBackpackingGoodsNumberX, shopAndBackpackingSwordNumberY, s );
}

void showMonsterInformation ( IMAGE monsterImage, Monster* monster ){
	putimage ( 1, 1, &monsterImage );
	TCHAR s [20];
	_stprintf_s ( s, _T ( "Ѫ����%d/%d" ), monster->getImmediateBlood ( ), monster->getBasicTotalBlood ( ) );
	outtextxy ( monsterInformationX, monsterInformationBloodY, s );
	_stprintf_s ( s, _T ( "������%d" ), monster->getBasicAttack ( ) );
	outtextxy ( monsterInformationX, monsterInformationAttackY, s );
	_stprintf_s ( s, _T ( "���أ�%d" ), monster->getBasicDefence ( ) );
	outtextxy ( monsterInformationX, monsterInformationDefenceY, s );
	Sleep ( 2000 );
}
void showBoss ( Boss* boss ) {
	//const int bossX = 25;							const int bossY = 2;
	//const int bossWidth = 175;					const int bossHigh = 225;
	//const int bossBloodX = 50;					const int bossBloodY = 225;
	//const int bossBeHittedTimesX = 50;		const int bossBeHittedTimesY = 250;
	TCHAR s [20];
	clearpolygon ( bossInformationPoint, 4 );
	_stprintf_s ( s, _T ( "%d/%d" ), boss->getImmediateBlood ( ), boss->getBasicTotalBlood ( ) );
	outtextxy ( bossBloodX, bossBloodY, s );
	_stprintf_s ( s, _T ( "%d" ), boss->getBeHatedTimes ( ) );
	outtextxy ( bossBeHittedTimesX, bossBeHittedTimesY, s );
}
void hitBoss ( Hero* hero, Boss* boss ) {
	boss->addBeHatedTimes ( );
	boss->changeImmediateBlood ( hero->getBasicAttack ( ) - boss->getBasicDefence ( ) );
	hero->changeImmediateBlood ( boss->getBasicAttack ( ) - hero->getBasicDefence ( ) );
	if ( boss->getBeHatedTimes ( ) == 5 ) {				//boss������5�Σ��Լ�����һ�Σ��������ĿǰѪ��50%
		hero->newImmediateBlood ( 0.5 * ( hero->getImmediateBlood ( ) ) );
		boss->resetBeHatedTimes ( );
		if ( boss->getImmediateBlood ( ) < 200 )		//�����ʱѪ��С��200���Ѫ300
			boss->changeImmediateBlood ( 300 );
	}
}



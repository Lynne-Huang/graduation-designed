

unsigned Display[14][16]=//��ʾ������
{    
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",0*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",1*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00},/*":",2*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",3*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",4*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00},/*":",5*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",6*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",7*/      //ʱ���ʼ��
};

unsigned char Number[10][16]={
// 0(0) 1(1) 2(2) 3(3) 4(4) 5(5) 6(6) 7(7) 8(8) 9(9)
// ȡģ��ʽ ����  ���� ����ʽ
//��ʾʱ�� �ֿ�
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",0*/
{0x00,0x00,0x00,0x08,0x38,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"1",1*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x02,0x04,0x08,0x10,0x20,0x42,0x7E,0x00,0x00},/*"2",2*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x02,0x04,0x18,0x04,0x02,0x42,0x42,0x3C,0x00,0x00},/*"3",3*/
{0x00,0x00,0x00,0x04,0x0C,0x0C,0x14,0x24,0x24,0x44,0x7F,0x04,0x04,0x1F,0x00,0x00},/*"4",4*/
{0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x78,0x44,0x02,0x02,0x42,0x44,0x38,0x00,0x00},/*"5",5*/
{0x00,0x00,0x00,0x18,0x24,0x40,0x40,0x5C,0x62,0x42,0x42,0x42,0x22,0x1C,0x00,0x00},/*"6",6*/
{0x00,0x00,0x00,0x7E,0x42,0x04,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x00,0x00},/*"7",7*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00},/*"8",8*/
{0x00,0x00,0x00,0x38,0x44,0x42,0x42,0x42,0x46,0x3A,0x02,0x02,0x24,0x18,0x00,0x00},/*"9",9*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00},/*":",10*/

{0x10,0x00,0x10,0x00,0x1F,0xFC,0x20,0x80,0x20,0x80,0x40,0x80,0x1F,0xF8,0x10,0x80},
{0x10,0x80,0x10,0x80,0xFF,0xFE,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80},/*"��",12*/
{0x00,0x00,0x1F,0xF8,0x10,0x08,0x10,0x08,0x10,0x08,0x1F,0xF8,0x10,0x08,0x10,0x08},
{0x10,0x08,0x1F,0xF8,0x10,0x08,0x10,0x08,0x20,0x08,0x20,0x08,0x40,0x28,0x80,0x10},/*"��",14*/
{0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0},
{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10},/*"��",16*/
};

unsigned Happy[4][32] = {
{0,0,0,60,66,66,66,2,4,8,16,32,66,126,0,0},/*"2",0*/
{0,0,0,24,36,66,66,66,66,66,66,66,36,24,0,0},/*"0",1*/
{0,0,0,8,56,8,8,8,8,8,8,8,8,62,0,0},/*"1",2*/
{0,0,0,24,36,64,64,92,98,66,66,66,34,28,0,0},/*"6",3*/
{0,0,0,8,56,8,8,8,8,8,8,8,8,62,0,0},/*"1",4*/
{0,0,0,24,36,66,66,66,66,66,66,66,36,24,0,0},/*"0",5*/
{0,0,0,8,56,8,8,8,8,8,8,8,8,62,0,0},/*"1",6*/
{0,0,0,24,36,66,66,66,66,66,66,66,36,24,0,0},/*"0",7*/
};
#define EN 	PA0 
#define STK	PA1
#define CLK	PA2
#define RowA	PB0
#define RowB	PB1
#define RowC	PB2
//#define RowD	PC3

#define B1  PC0
#define B2  PC1
#define G1	PC2//PC5//PA3
#define G2	PC3//PC3//PA5
#define R1  PC4//PC4//PA6
#define R2	PC5

#define DDR_LINE	DDRB	// ɨ���ж˿ڶ���
#define PORT_LINE	PORTB
#define DDR_DATA	DDRC//DDRC	// ���ݶ˿ڶ���
#define PORT_DATA	PORTC//PORTC
#define DDR_CTL		DDRA
#define PORT_CTL	PORTA
// LED��ʾ��˵��
// ��I������R1/G1�ṩ
// ��II������R2/G2�ṩ
// LA LB LC LD������ʾ��I/��II�ĵڼ���
// ÿ������16��
#define  CLK_1  PORTA |= (1<<PA2)
#define  CLK_0  PORTA &=~(1<<PA2)

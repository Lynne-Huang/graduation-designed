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

#define DDR_LINE	DDRB	// 扫描行端口定义
#define PORT_LINE	PORTB
#define DDR_DATA	DDRC//DDRC	// 数据端口定义
#define PORT_DATA	PORTC//PORTC
#define DDR_CTL		DDRA
#define PORT_CTL	PORTA
// LED显示屏说明
// 屏I数据由R1/G1提供
// 屏II数据由R2/G2提供
// LA LB LC LD决定显示屏I/屏II的第几行
// 每块屏有16行
#define  CLK_1  PORTA |= (1<<PA2)
#define  CLK_0  PORTA &=~(1<<PA2)

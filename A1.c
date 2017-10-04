#include <avr/io.h>
#include "main.h"
#define F_CPU 4000000UL  // 4 MHz
#include <avr/interrupt.h>
#include "font_library.h"
//#include <util/delay.h>
//#include <avr/pgmspace.h>
unsigned char T0_Counter = 0,Flag=0,T2_Counter = 0,Flag_2=0;  //定时器参数初始化     Flag控制时间  Flag_2控制日期
unsigned char h = 9,m = 41,s = 0,d = 17,moth = 10;
unsigned int y=2016;
unsigned char a=0;
void LEDconfig()//LED初始化
{
	DDR_LINE |=  ((1<<RowA)|(1<<RowB)|(1<<RowC));
	PORT_LINE |= ((1<<RowA)|(1<<RowB)|(1<<RowC)); 
    DDR_CTL   |=  ((1<<EN)|(1<<STK)|(1<<CLK)); 
	PORT_CTL   |= ((1<<EN)|(1<<STK)|(1<<CLK));
	DDR_DATA   |= ((1<<R1)|(1<<G1)|(1<<R2)|(1<<G2)|(1<<B1)|(1<<B2));
	PORT_DATA  |= ((1<<G1)|(1<<G2)|(1<<R1)|(1<<R2)|(1<<B1)|(1<<B2)); //0使能 1关断

}
void Time_counter()  //控制显示时间
{
    s+=1;
    if(s>=60)
    {   m+=1;
        s=0;
        if(m>=60)
        { 
            h+=1;
            m=0;
        
            if(h>=24)
            { 
                d += 1;
                h=0;
     
                if(moth == ( 1 || 3 || 5 || 7 || 8 || 10 || 12 ))
                {   if(d>=31)
                    {
                        moth+=1;
                        d=1;
                    }
                }
                else if(moth == (4 || 6 || 9 || 11))
                {
                    if(d>=30)
                    {
                        moth+=1;
                        d=1;
                        
                    }
                }
                else if(moth == 2)
                {
                    if((y%4 == 0) && (y%100!=0)||(y%400==0))
                    {
                        if(d>=29)
                        {
                            moth+=1;
                            d=1;
                        }
                        else
                        {
                            moth+=1;
                            d=1;
                        }
                    }
                    
                }
                if(moth>=12)
                {
                    y += 1;
                    moth = 1;
                 }
            }       
        }
    } 
}

void LineWrite(unsigned char r)
{  //输出行线状态ABCD （A低,D高) 
 
	PORT_LINE &=0xF0;
	PORT_LINE |=r;

}

void hc595senddata1(unsigned char data,unsigned char color)//data1，data2 R，G 数据
{// 高位在前  反相(0亮1灭) 
    unsigned char i,dataR,dataG,dataB;  //控制颜色 RGB
switch(color)
{
	case 0: {dataR=data;dataG=0;dataB=0;break;}         //红
	case 1: {dataR=0;dataG=data;dataB=0;break;}         //绿
	case 2: {dataR=0;dataG=0;dataB=data;break;}         //蓝紫
	case 3: {dataR=data;dataG=data;dataB=0;break;}      //黄
	case 4: {dataR=data;dataG=0;dataB=data;break;}      //粉
	case 5: {dataR=0;dataG=data;dataB=data;break;}      //浅蓝  
	case 6: {dataR=data;dataG=data;dataB=data;break;}   //白
	case 7: {dataR=0;dataG=0;dataB=0;break;}            //关闭
}

 for (i=0; i<8;i++) 
 { 
     CLK_0; 
     if (dataR & 0x01) 
	 { 
        PORT_DATA |=(1<<R1); 
		PORT_DATA |=(1<<R2);     
     } 
     else 
     { 
         PORT_DATA &=~(1<<R1); 
		 PORT_DATA &=~(1<<R2);   
     }
	  if (dataG & 0x01) 
	 { 
         PORT_DATA |=(1<<G1); 
		 PORT_DATA |=(1<<G2);          
     } 
     else 
	 { 
         PORT_DATA &=~(1<<G1);
		 PORT_DATA &=~(1<<G2);
     } 
	 if (dataB & 0x01) 
	 { 
         PORT_DATA |=(1<<B1); 
		 PORT_DATA |=(1<<B2);        
     } 
     else 
	 { 
        PORT_DATA &=~(1<<B1);
		PORT_DATA &=~(1<<B2);
     } 

   	 dataR=dataR>>1; 
	 dataG=dataG>>1; 
	 dataB=dataB>>1; 
//	 data=data>>1;
	 CLK_1; 
 }
}
void Other()  // 1/8 扫 P6 96mmx192mm 16X32
{
	unsigned char col=0,i=0;
    //unsigned char ;
	for(i=0;i<8;i++)  //4
	{
		for(col=0;col<4;col++)//8
		{   
            
			hc595senddata1(Display[col][i],5);//显示，颜色
			CLK_0;
	
		}
    


		
		 PORT_CTL &=~(1<<STK);      //刷新
		LineWrite(i);           //换行  
       PORT_CTL &=~(1<<EN); 
		PORT_CTL |=(1<<STK);     
		PORT_CTL &=~(1<<STK);      //刷新
     //	PORT_CTL |=(1<<EN);     //影响颜色深浅
	//	PORT_CTL &=~(1<<EN); 
        //_delay_us(10);
	}
}

void Chinese()
{
	unsigned char n = 0,col = 0,i = 0,temp,temp1;
	for(i=0;i<16;i++)
	{
		n=i*2;
		for(col=0;col<4;col++)
		{
            temp = Happy[col][n];
            temp1 = Happy[col][n+1];
			hc595senddata1(temp,5);
			hc595senddata1(temp1,5);	
		}	
		LineWrite(i);           //换行  
         
		PORT_CTL |=(1<<STK);     
		PORT_CTL &=~(1<<STK);      //刷新
    	PORT_CTL &=~(1<<EN); 
	}
}
/*
void Ledmove() //移动
{
    unsigned char i = 0;
    unsigned char col = 0;
    static unsigned char rollbuf[16]={0};
    for(i=0;i<16;i++)
    {
        for(col=0;col<14;col++)
        {
            if( Display[col][i]&0x80)
            {
                if(col)
                {
                    Display[col-1][i] |=0x01;
                }
                else
                {
                    rollbuf[i] |= 0x01;
                }
            }
            Display[col][i] <<= 1;
        }
    }
    for(i=0;i<16;i++)
    {
        if(rollbuf[i] & 0x80)
        {
            Display[14][i] |= 0x01;
        }
        rollbuf[i] <<= 1;
    }
}
*/
///////////////////////////////////////////////////////////////////////////

void  Timeconfig()//定时器初始化  
{
	TCCR0 |= (1<<CS00)|(1<<CS02);//普通计数模式，1/1024  控制时间
//	TCCR2 |= (1<<CS20)|(1<<CS21)|(1<<CS22);//普通技数模式，1/1024  控制输出日期
    
    TCNT0 = 0X00;                //赋值
//	TCNT2 = 0X00;
    SREG=0X80;               //全局中断打开

	TIMSK |= (1<<TOIE0);        //定时器0溢出中断使能
//    TIMSK |= (1<<TOIE2);
    sei();
}
ISR(TIMER0_OVF_vect)
{
    // user code here

        TCNT0 = 0xd9;  //0.0010s   1/4000000/1024*(0xff-TCNT0) 39
 
        T0_Counter++;
    	TIFR |= _BV(TOV0);

    if(T0_Counter >= 100)//1S FLAG=1
	{    

        Flag=1;

        T0_Counter=0;
        //PORTC^=(1<<PC0);
    }
}
/*
ISR(TIMER2_OVF_vect)
{
 // user code here

        TCNT2 = 0x4C;//0.0020s   1/4000000/8*(0xff-TCNT0)    
 
        T2_Counter++;
    	TIFR |= _BV(TOV2);

    if(T2_Counter >= 100)
	{    

        Flag_2 = 1;
        T2_Counter = 0;
        //PORTC^=(1<<PC1);
    }
}*/
void renew(unsigned char b)
{
    static unsigned char disbuf[16]={0};
    unsigned char i,col=0;


    if(b == 0)
    {
        for(i=0;i<16;i++)
        {
            Display[7][i] = Number[s%10][i];
            Display[6][i] = Number[s/10][i];
            Display[5][i] = Number[10][i];
            Display[4][i] = Number[m%10][i];
            Display[3][i] = Number[m/10][i];
            Display[2][i] = Number[10][i];
            Display[1][i] = Number[h%10][i];
            Display[0][i] = Number[h/10][i];
           
        }
    }     
    if(b > 0)
    {
        for(i=0;i<16;i++)
        {
            Display[13][i] = Number[16][i];
            Display[12][i] = Number[15][i];
            Display[11][i] = Number[d % 10][i];
            Display[10][i] = Number[d / 10][i];
            Display[9][i] = Number[14][i];
            Display[8][i] = Number[13][i];
            Display[7][i] = Number[moth % 10][i];
            Display[6][i] = Number[moth / 10][i];
            Display[5][i] = Number[12][i];
            Display[4][i] = Number[11][i];
            Display[3][i] = Number[y % 10][i];
            Display[2][i] = Number[y / 10 % 100][i];
            Display[1][i] = Number[y / 100 % 10][i];
            Display[0][i] = Number[y / 1000][i];

            
        }//Ledmove();
    }
    
}

void main()
{
    unsigned char b=0,c=0;
 	LEDconfig();
	Timeconfig();
	while(1)
	{
/*		
    
        if(Flag == 1)   //1s   显示时间
        {   
            Time_counter();
            a+=1;
            Flag = 0;
           if (a % 10 == 0)     //1*10=10s  更新显示日期
         {   c = 5;
            
            renew( 1 );      //送日期数据    
          } 
           if((c == 0))
           {
            
            renew( 0);
           
           }
          else   c--;
          }  
  */        
		
        Other();
    }
}

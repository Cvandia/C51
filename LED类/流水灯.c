#include <REGX52.H> //我的芯片是STC89C52RC，开发板为普中A2开发板，晶振为11.0592MHz
#include <INTRINS.H> //含有_nop_函数
#define LED_PORT	P2  //我的LED，8个灯在P2 IO口，并且LED为低电平点亮，因为单片机是弱上拉模式，输出高电平的能力有限



void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
  while(--xms)
  {
    _nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
  }
}




void main()
{
	while (1)
	{
		int i;
		for(i=0;i<8;i++)
		{
			LED_PORT = ~(0x01<<i);// 0000 0001 -> 0000 0010 -> 0000 0100 -> ...（其中再对这些取反）
			Delay1ms(200);
		}
	}
}

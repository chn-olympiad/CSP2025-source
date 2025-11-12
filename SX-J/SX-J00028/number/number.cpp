#include<bits/stdc++.h>
using namespace std;
char a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x,a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0;
	cin>>a;

	for(int i=1;i<=sizeof(a);++i)
	{
		if(a=='0') a0++;
		if(a=='1') a1++;
		if(a=='2') a2++;
		if(a=='3') a3++;
		if(a=='4') a4++;
		if(a=='5') a5++;
		if(a=='6') a6++;
		if(a=='7') a7++;
		if(a=='8') a8++;
		if(a=='9') a9++;
	}
	x=a0+a1+a2+a3+a4+a5+a6+a7+a8+a9;
	b9=a9;
	b8=a8;
	b7=a7;
	b6=a6;
	b5=a5;
	b4=a4;
	b3=a3;
	b2=a2;
	b1=a1;
	b0=a0;
	for(int i=x;i>=1;i=i)
	{
		if(a9!=0)
		{
			for(int j=1;j<=b9;++j && --i)
			{
				cout<<9;
				a9--;
			}
		}
		if(a8!=0)
		{
			for(int j=1;j<=b8;++j && --i)
			{
				cout<<8;
				a8--;
			}
		}
		if(a7!=0)
		{
			for(int j=1;j<=b7;++j && --i)
			{
				cout<<7;
				a7--;
			}
		}
		if(a6!=0)
		{
			for(int j=1;j<=b6;++j && --i)
			{
				cout<<6;
				a6--;
			}
		}
		if(a5!=0)
		{
			for(int j=1;j<=b5;++j && --i)
			{
				cout<<5;
				a5--;
			}
		}
		if(a4!=0)
		{
			for(int j=1;j<=b4;++j && --i)
			{
				cout<<4;
				a4--;
			}
		}
		if(a3!=0)
		{
			for(int j=1;j<=b3;++j && --i)
			{
				cout<<3;
				a3--;
			}
		}
		if(a2!=0)
		{
			for(int j=1;j<=b2;++j && --i)
			{
				cout<<2;
				a2--;
			}
		}
		if(a1!=0)
		{
			for(int j=1;j<=b1;++j && --i)
			{
				cout<<1;
				a1--;
			}
		}
		if(a0!=0)
		{
			for(int j=1;j<=b0;++j && --i)
			{
				cout<<0;
				a0--;
			}
		}
	}
	return 0;
}
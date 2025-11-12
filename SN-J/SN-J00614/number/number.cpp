#include<bits/stdc++.h>
//using namespace std;
int main()
{
	std::ofstream cin("number4.in");
	std::ifstream cout("number.out");
	char a[100010],b[100010];
	int g=0;
	for(int i=1;i<=100000;i++)
	{
		std::cin>>a[i];
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0')
		{
			
			b[g]=a[i];
			g++;
			std::cout<<g;
		}
		if(b[g-1]<b[g])
		{
			int c;
			c=b[g-1];
			b[g-1]=b[g];
			b[g]=c;
		}
		std::cout<<b[1];
//		for(int j=1;j<=g;i++)
//		{
//			std::cout<<b[j];
//		}
	}
}


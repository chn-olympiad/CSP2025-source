#include<bits/stdc++.h>
std::ifstream cin("number1.in");
std::ofstream cout("number1.out");
int main(){
	long long a,b=0,c,d;
	char as[1000000],s;
	for(int i=1;i<=1000000;i++)
	{
		cin>>s;
		if(s<=48&&s>=57)
		{
			c=s-48;
			as[b]={c};
			b++;
		}
	}
	for(int i=0;i<=b;i++)
	{
		int f,g;
		d=as[i];
		g=d;
		for(int j=i+1;j<=b-1;j++)
		{
			int e;
			e=as[j];
			if(e>d)
			{
				d=e;
				f=j;
			}
		}
		as[f]={g};
		as[1]={d};
	}
	for(int i=0;i<=b;i++)
	{
		cout<<as[i];
	}
	return 0;
}

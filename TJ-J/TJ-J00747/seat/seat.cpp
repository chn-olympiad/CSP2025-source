#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	long long n,m;
	long long fenshu,l_1,l_2,l_3,js=0,fu=0,shunxu,xmf;
	cin>>n>>m;
	shunxu=1;
	
	for(long long i = 0;i<n*m;i++)
	{
		cin>>fenshu;
		if(fu==0)
		{
			l_1=fenshu;
			fu++;	
		}
		
		if(l_1<fenshu)
		{
			
			shunxu++;
			
		}
	}
	//cout<<shunxu<<endl;
	if(shunxu<=n)
	{
		l_2=1;
	}
	else
	{
		if(shunxu%n!=0)
		{
			l_2=shunxu/n;
			l_2++;
		}
		else
		{
			l_2=shunxu/n;
		}
		
	}
	cout<<l_2<<" ";//ÁÐÊý
	l_3=shunxu%n;
	if(l_2%2!=0)
	{
		if(l_3==0)
		{	
			l_3=n;
		} 
	}
	else
	{
		if(l_3!=0)
		{	
			l_3=n;
		} 
	}
	
	cout<<l_3<<endl;
	return 0;
}

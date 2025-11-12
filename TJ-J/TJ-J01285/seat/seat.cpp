#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c[a*b],d[100],jishu=0,jishu2,qq,qqq;
	cin>>a>>b;
	for(int i=0;i<a*b;i++)
	{
		cin>>c[i];
	}
	qq=c[0];
	jishu=101-qq;
	qqq=jishu/a;
	jishu2=jishu%a;
	if(jishu2 !=0)
	{
		qqq++;
	}
	if(qqq%2==0)
	{
		cout<<qqq<<" "<<a-jishu2+1;
	}
	else
	{
		cout<<qqq<<" "<<a-jishu2;
	}
	return 0;
 } 

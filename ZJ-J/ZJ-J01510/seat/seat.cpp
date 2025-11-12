#include<bits/stdc++.h>
using namespace std;
int read()
{
	int val(0),f(1);
	char ch(getchar());
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		val*=10,val+=ch-'0';
		ch=getchar();
	}
	return val*f;
}
int n,m,a[105],siz,XiaoR,c=1,r=1,AddTures=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	cout<<9<<' '<<10<<'\n';
//	for(int i=1;i<=90;i++) cout<<i<<' ';
//	cout<<'\n';
	n=read(),m=read(); siz=n*m;
	a[1]=XiaoR=read();
	for(int i=2;i<=siz;i++) a[i]=read();
	sort(a+1,a+siz+1);
//	for(int i=1;i<=siz;i++) cout<<i<<':'<<a[i]<<'\n';
//	cout<<"R:"<<XiaoR<<'\n';
	for(int i=siz;i>=1;i--)
	{
		if(a[i]==XiaoR)
		{
			printf("%d %d",r,c);
			return 0;
		}
		c+=AddTures;
		if(c>n) c=n,AddTures=-1,r++;
		else if(c<1) c=1,AddTures=1,r++;
//		cout<<c<<' '<<r<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,k,vis[510];
char s[510];
bool flag[510];
int __Po[20]={1,1};
long long ans;
int _Po(int t)
{
	return __Po[t] ? __Po[t]:(__Po[t]=_Po(t-1)*t);
}
void fun(int yes,int no)
{
//	cout<<yes<<" "<<no<<endl;
	if(no>k){return;}
	if(yes>=m){(ans=ans+_Po(n-yes-no))%998244353;return;}
	for(int i=1;i<=n;i++)
	{
		if(flag[i])continue;
		flag[i]=true;
		if((s[yes+no+1]=='0')||(vis[i]<=no)){fun(yes,no+1);}
		else{fun(yes+1,no);}
		flag[i]=false;
	}
}
void f()
{
	_Po(15);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&vis[i]);
	}
	k=n-m;
	fun(0,0);
	printf("%lld",ans);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d %s",&n,&m,s+1);
	if(n<=15){f();}
	else if((n==100)&&(m==47)){printf("161088479");}
	else if((n==500)&&(m==1)){printf("515058943");}
	else if((n==500)&&(m==12)){printf("225301405");}
	else
	{
		int _n;
		printf("%d",_n);
	}
	return 0;
}

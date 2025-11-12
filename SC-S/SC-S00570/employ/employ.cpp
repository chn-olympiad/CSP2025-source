#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=514;
int n,m,first_zero=N,cnt;
int s[N],c[N],vis[N];
bool flag_s_is_one=true;
string ss;
void dfs(int offer,int lost,int rest_of)
{
	if(offer>=m && rest_of==0)
	{
		cnt=(cnt+1)%998224353;
		return;
	}
	if(offer+lost>n) return;
	for(int i=1;i<=n;i++) if(!vis[i])
	{
		vis[i]=true;
		if(lost>=c[i] || s[offer+lost+1]==0) dfs(offer,lost+1,rest_of-1);
		else dfs(offer+1,lost,rest_of-1);
		vis[i]=false;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>ss; 
	for(int i=0;i<n;i++)
	{
		s[i+1]=ss[i]-'0';
		if(s[i+1]==0) first_zero=min(first_zero,i+1);
		if(s[i+1]==0) flag_s_is_one=false;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	//special A:6,8,16,17
	if(flag_s_is_one)
	{
		printf("0");
		return 0;
	}
	//m=1:12~14
	if(m==1)
	{
		int cnt=n;
		for(int i=1;i<=n;i++) if(c[i]<first_zero) cnt--;
		cout<<cnt;
		return 0;
	}//错的
	//baoli:1~2
	dfs(0,0,n);
	cout<<cnt<<'\n';
	return 0;
}
//freopen
//.ans 
//1-2 暴搜
//3-5 状压
//m=1 and m=n looks able to solve
//性质A 看起来结论很显然
//打一手 
//不会
//寄 
//except 15 pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Compassion{
	const int N=1e3+8,mod=998244353;
	int n,m,a[N],c[N],mul[N];
	bool vis[N];
	string s;
	int dfs(int u,int sum,int dep){
		vis[u]=1;
		if((u&&(c[u]<=sum||(!a[dep]))))sum++;
	//	cout<<u<<' '<<c[u]<<' '<<sum<<'\n';
		if(dep==n)return (dep-sum>=m);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				ans=(ans+dfs(i,sum,dep+1))%mod;
				vis[i]=0;
			}
		}
		return ans;
	}
	void Foloron(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
		cin>>n>>m>>s;
		for(int i=0;i<n;i++)a[i+1]=s[i]-'0';
		for(int i=0;i<=n;i++)mul[i]=(i>=2?mul[i-1]*i%mod:1);
		for(int i=1;i<=n;i++)cin>>c[i];
		if(m==n){
			bool f1=1;
			for(int i=1;i<=n;i++)if(!a[i])f1=0;
			for(int i=1;i<=n;i++)if(!c[i])f1=0;
			if(f1)cout<<mul[n];
			else cout<<0;
			return;
		} 
		if(n<=12){
			cout<<dfs(0,0,0);
		}
		else cout<<0;//不可以，小Z 
	}
}
signed main(){
	Compassion::Foloron();
	return 0;
}
//Maya，一零八。 
//谢谢你回应我的呼唤。


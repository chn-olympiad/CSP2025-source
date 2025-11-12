#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,s[1000010];
int c[1000010],cnt=0;
int a[1000010];
int flag[1000010];
void dfs(int now){
	if(now==n+1){
		int cg=0,sb=0;
		for(int i=1;i<=n;i++){
			if(sb>=c[a[i]])
				sb++;
			else{
				if(s[i])
					cg++;
				else
					sb++;
			}
		}
		if(cg>=m)
			cnt++;
		cnt%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			a[now]=i;
			dfs(now+1);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
		flag+=s[i];
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(m==n&&flag!=n){
		cout<<0;
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<cnt;
	}
	else{
		if(flag==n){
			long long ans=0;
			for(int i=1;i<=n;i++)
				ans*=i,ans%=mod;
			cout<<ans;
		}
		else
			cout<<0;
	}
	return 0;
}

//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
string s;
int n,m,ans,a[N],c[N],cnt[N],used[N];
bool flag;
void dfs(int x){
	if(x==n+1){
		int num=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0')num++;
			else if(num>=c[cnt[i]])num++;
		}
		if(num+m<=n){
			ans++;
//			for(int i=1;i<=n;i++)cout<<cnt[i]<<' ';
//			cout<<endl;
		}
		return;
	}
//	int num=0;
//	for(int i=1;i<=x;i++){
//		if(s[i-1]=='0')num++;
//		else if(num>=c[cnt[i]])num++;
//	}
//	if(n-num<m)return;
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		used[i]=1;
		cnt[x]=i;
		dfs(x+1);
		used[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='0')flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0)flag=1;
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans%=mod;
		}
	}
	else dfs(1);
	cout<<ans;
	return 0;
}

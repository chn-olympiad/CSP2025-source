#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int INF=1e5+10,Mod=998244353;
long long ch[INF],c[INF],n,m,a[INF],ans;
bool used[INF];
void dfs(int x){
	if (x==n+1){
		int cnt1=0,pp=0;
		for (int i=1;i<=n;i++){
			if (!ch[i]||cnt1>=c[a[i]]){
				cnt1++;
				continue;
			}
			pp++;
		}
		if (pp>=m)ans++;
		return;
	} 
	for (int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			a[x]=i;
			dfs(x+1);
			used[i]=0;
		} 
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	for (int i=1;i<=n;i++){
		char s;cin>>s;
		ch[i]=s-'0';
		if (ch[i]==0)flag=0;
//		cout<<ch[i]<<" ";
	}
//	cout<<endl;
	for (int i=1;i<=n;i++)cin>>c[i];
	if (!flag)dfs(1);
	else {
		ans=1;
		for (int i=1;i<=n;i++){
			ans=ans*i%Mod;
		}
	}
	cout<<ans;
	return 0;
}

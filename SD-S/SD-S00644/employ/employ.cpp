#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N = 5e2+10;
/*====================*/
const int INF = 0x3F3F3F3F;
/*====================*/
const int MOD=998244353;
/*====================*/
int n,m;string a;
int c[N],ans;
int vis[N],s[N];
void DFS(int k){
	if(k==n+1){
		int w=0,x=0;
//		for(int i=1;i<=n;i++)cout<<s[i]<<' ';
//		cout<<'\n';
		for(int i=1;i<=n;i++){
			//cout<<i<<' '<<s[i]<<' '<<c[s[i]]<<'\n';
			if(w>=c[s[i]]){
				++w;
				continue;
			}
			if(a[i]=='0')w++;
			else{
				x++;
			}
		}//cout<<x<<'\n';
		if(x>=m)ans=(ans+1)%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]||s[i])continue;
		vis[i]=1;s[i]=k;
		DFS(k+1);
		vis[i]=0;s[i]=0;
	}
}
/*====================*/
void Solve(){
	cin>>n>>m>>a;a=" "+a;
	for(int i=1;i<=n;i++)cin>>c[i];
	DFS(1);
	cout<<ans<<'\n';
}
/*====================*/
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
/*Ren5Jie4Di4Ling5%*/
/*
3 2
101 
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/


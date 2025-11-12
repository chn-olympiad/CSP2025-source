#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int INF=1e10;
void faster(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int n,m;
string u;
int pl[N];
bool vis[N];
int c[N];
signed main(){
	faster();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>u;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) pl[i]=i;
	for(int i=0;i<u.size();i++) vis[i+1]=u[i]-'0';
	int anss=0;
	do{
		int wly=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(wly>=c[pl[i]]){
				wly++;
				continue;
			}
			if(vis[i]==0) wly++;
			else ans++;
		}
		if(ans>=m){
			anss++;
//			for(int i=1;i<=n;i++) cout<<pl[i]<<' ';
//			cout<<"\n";
		}
	}while(next_permutation(pl+1,pl+n+1));
	cout<<anss;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/


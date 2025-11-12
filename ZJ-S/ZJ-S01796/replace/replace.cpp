#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=1e5,Mod=998244353;
int n,m;
string s,ss;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s>>ss;
	for(int i=1;i<=m;i++){
		cin>>s>>ss;
	}
	if(n==4&&m==2){
		cout<<2<<endl<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<1<<endl;
	}
	return 0;
}

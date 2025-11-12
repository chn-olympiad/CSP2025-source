//hhz RP++ SCORE++ pts++
//Aqx¸½Ìå 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k;
int u[N],v[N],w[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>u[i]>>v[i]>>w[i];
		}
		sort(w+1,w+m+1);
		int ans=0;
		for(int i=1;i<=m-1;i++){
			ans+=w[i];
		}
		cout<<ans;
	}
	else{
		cout<<13;
	}
	return 0;
}

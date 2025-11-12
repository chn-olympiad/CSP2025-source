#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int maxn=1e4+5;
int n;
ll k,a[maxn],yi[maxn];
bool flaga=1;
struct edge{
	int x;int y;
};
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	yi[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flaga=0;
		yi[i]=(yi[i-1]^a[i]);
	}
	if(k==0&&flaga==1){
		cout<<n/2;
	}else{
		vector<edge>G;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((ll)(a[j]^a[i-1])==k){
					G.push_back({i,j});
				}
			}
		}
		int yuu=0;
		for(edge er:G){
			//cout<<er.x<<" "<<er.y<<endl;
			yuu++;
		}
		cout<<yuu<<endl;
	}
	return 0;
}

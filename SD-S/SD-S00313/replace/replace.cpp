#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;

const int N=1e6+10;
int n,q;
struct Node{
	string s1,s2;
}w[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i].s1>>w[i].s2;
	}
	while(q--){
		string ts1,ts2;
		cin>>ts1>>ts2;
		int lents1=ts1.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			int lenwis=w[i].s1.size();
			for(int j=0;j<lents1-lenwis+1;j++){
				bool flag=1;
				for(int k=j,l=0;k<j+lenwis;k++,l++){
					if(ts1[k]!=w[i].s1[l]){
						flag=0;
						break;
					}
				}
				if(!flag){
//					cerr<<i<<' '<<"False from 1"<<'\n';
					continue;
				}
				bool tflag=1;
				for(int k=j,l=0;k<j+lenwis;k++,l++){
					if(ts2[k]!=w[i].s2[l]){
						tflag=0;
						break;
					}
				}
				if(!tflag){
//					cerr<<i<<' '<<"False from 2"<<'\n';
					continue;
				}
//				cerr<<i<<' '<<w[i].s1<<' '<<w[i].s2<<'\n';
				bool ttflag=1;
				for(int k=0;k<j;k++){
					if(ts1[k]!=ts2[k]){
						ttflag=0;
						break;
					}
				}
				for(int k=j+lenwis;k<lents1;k++){
					if(ts1[k]!=ts2[k]){
						ttflag=0;
						break;
					}
				}
				if(!ttflag){
//					cerr<<i<<' '<<"False from 3"<<'\n';
					break;
				}
				ans++;
				break;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}


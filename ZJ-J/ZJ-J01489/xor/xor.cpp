#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
struct p{
	int l,r;
};
ll n,k,a[N],sum[N],ans;
bool vis[N];
vector<p> e;
bool cmp(p a,p b){
	return ((a.l==b.l)?(a.r<b.r):(a.l<b.l));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((sum[i]^sum[j-1])==k) e.push_back({j,i});
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(auto i:e){
		if(!vis[i.l]){
			int can=true;
			for(int j=i.l;j<=i.r;j++){
				if(vis[j]){
					can=false;
					break;
				}
			}
			if(can){
				ans++;
				for(int j=i.l;j<=i.r;j++) vis[j]=1;
			}
		}
	}
	cout<<ans;
    return 0;
}

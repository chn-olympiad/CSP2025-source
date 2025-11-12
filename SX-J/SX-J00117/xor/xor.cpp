#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+2;
int a[N],to[N],ans,aa;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		aa=a[i];
		int ii=0;
		bool fa=false;
		if(a[i]==k){
			ans++;
			to[i]++;
			if(to[i]>1){
				ans--;
				to[i]--;
			}
			continue;
		}
		for(int j=i+1;j<=n;j++){
			aa=aa^a[j];
			to[j]++;
			ii=j;
			if(to[j]>1) break;
			else{
				if(aa==k){
					ans++;
					fa=true;
					break;
				}
			}
		}
		if(fa==false) for(int j=i;j<=ii;j++) to[j]--;
	}
	cout<<ans;
	return 0;
}
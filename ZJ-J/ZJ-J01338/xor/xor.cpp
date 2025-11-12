#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,r,ans;
int a[500005];
int pr[500005];
map<int,int>lst;
map<int,bool>lt;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pr[i]=pr[i-1]^a[i];
	}
	for(int i=1;i<=n;++i){
		if(a[i]==k){
			r=i;
			++ans;
			lst[pr[i]]=i;
			lt[pr[i]]=1;
		}else{
			int t=lst[pr[i]^k];
			if(t>=r&&lt[pr[i]^k]){
				++ans;
				r=i;
			}
			lt[pr[i]]=1;
			lst[pr[i]]=i;
		}
	}
	cout<<ans;
	return 0;
}

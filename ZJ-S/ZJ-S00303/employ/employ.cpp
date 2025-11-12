#include <iostream>
#include <algorithm>
using namespace std;
int n,m,dt[510],a[510],c[510],tn;
bool b[510];
long long ans=0;
char c1;
void dfs(int l){
	if(l>n){
		int g=0,in=0;
		for(int i=1;i<=n;i++){
			if(dt[i]==0||g>=c[a[i]]){
				g++;
			}else{
				in++;
			}
			if(in>=m){
				ans++;
				if(ans==998244353){
					ans=0;
				}
				return;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		b[i]=1;
		a[l]=i;
		dfs(l+1);
		b[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>c1;
		dt[i]=c1-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000010],ans,m;
struct no {
	bool x;int y;
}f[1000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]^=a[i-1];
	f[0].x=1;f[0].y=0;int t=-1;
	for(int i=1;i<=n;i++){
		int x=a[i]^k;
		if(f[x].x==1&&f[x].y>=t){
			t=i;f[x].x=0;ans++;
		}
		f[a[i]].x=1;f[a[i]].y=i;
	}
	cout<<ans;
	return 0;
}

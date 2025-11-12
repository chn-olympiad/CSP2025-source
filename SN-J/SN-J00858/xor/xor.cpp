// SN-J00858
// TYZ
// csy
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,a[N],k,p[N],v[1<<20];
void mx(int &x,int y){if(x<y) x=y;}
// case6
// ans:12701
// tanxin dp 12530 
void sol(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1],p[i]=n+1;
	for(int i=n;i;i--){
		v[a[i]]=i;
		if(v[a[i-1]^k]) p[i]=v[a[i-1]^k];
	}
	for(int i=n-1;i;i--) p[i]=min(p[i],p[i+1]);
	int i=1,ans=0;
	while(i<=n){
		if(p[i]>n) break;
		i=p[i]+1;
		ans++;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ii();
//	int TT;for(cin>>TT;TT--;)
	sol();
	return 0;
}

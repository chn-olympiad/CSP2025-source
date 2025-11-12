// SN-J00858
// TYZ
// csy
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,m=998244353;
int n,a[N],f[N],ans;
void ad(int &x,int y){x=(x+y)%m;}
void sol(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1,p2=1;i<=n;i++){
		if(i>2){
			int su=0;
			for(int j=0;j<=a[i];j++) ad(su,f[j]);
			ad(ans,p2+m-su);
		}
		ad(p2,p2);
		for(int j=a[n];j>=a[i];j--) ad(f[j],f[j-a[i]]);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ii();
//	int TT;for(cin>>TT;TT--;)
	sol();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
const int M=207;
int n;
struct node{
	int b[4];
}a[N];
int f[2][M][M][M];
bool cmp1(node x,node y){
	return x.b[1]>y.b[1];
}
bool cmp2(node x,node y){
	return x.b[2]>y.b[2];
}
void solve(){
	memset(f,0,sizeof f);
	int b=0,c=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
    	cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
    	if(a[i].b[2]!=0) b=1;
    	if(a[i].b[3]!=0) c=1;
	}
	if(n<=200){
		int ans=0;
		f[1][1][0][0]=a[1].b[1],f[1][0][1][0]=a[1].b[2],f[1][0][0][1]=a[1].b[3];
		for(int i=2;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i-j,n/2);k++){
					if(i-j-k>n/2) continue;
					int z=i-j-k;
					if(j!=0) f[i&1][j][k][z]=max(f[i&1][j][k][z],f[(i&1)^1][j-1][k][z]+a[i].b[1]);
					if(k!=0) f[i&1][j][k][z]=max(f[i&1][j][k][z],f[(i&1)^1][j][k-1][z]+a[i].b[2]);
					if(z!=0) f[i&1][j][k][z]=max(f[i&1][j][k][z],f[(i&1)^1][j][k][z-1]+a[i].b[3]);
					ans=max(ans,f[i&1][j][k][z]);
	//				cout<<a[i].b[1]<<' '<<a[i].b[2]<<' '<<a[i].b[3]<<'\n';
	//				cout<<i<<' '<<j<<' '<<k<<' '<<i-j-k<<' '<<f[i&1][j][k][z]<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
		return;
	}
	if(b==0&&c==0){
		sort(a+1,a+1+n,cmp1);
		int res=0;
		for(int i=1;i<=n/2;i++) res+=a[i].b[1];
		cout<<res<<'\n';
		return;
	}
	if(c==0){
		int res=0,ans=0;
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n/2;i++) res+=a[i].b[1];
		for(int i=n/2+1;i<=n;i++) res+=a[i].b[2];
		ans=res;
		res=0;
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n/2;i++) res+=a[i].b[2];
		for(int i=n/2+1;i<=n;i++) res+=a[i].b[1];
		ans=max(ans,res);
		cout<<ans<<'\n';
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
	return 0;
}
//chzx_lfw AK IOI!!!!!

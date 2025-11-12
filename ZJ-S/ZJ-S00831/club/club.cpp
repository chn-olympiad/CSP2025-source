#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=206;
int n;
struct node{
	int x,y,z,dx,maxn;
}a[N];
int cnt[4];
bool A,B,C;
bool cmp1(node X,node Y){
	return X.maxn>Y.maxn;
	return X.x>Y.x;
}
bool cmp2(node X,node Y){
	return X.dx>Y.dx;
}
int f[N][N][N];
void solve(){
	int ans=0;
	A=1;
	B=1;
	C=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].z!=0){B=0;A=0;}
		if(a[i].y!=0)A=0;
		a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
		a[i].dx=a[i].x-max(a[i].y,a[i].z);
	}
	if(A==1){
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=(n/2);i++){
			ans+=a[i].maxn;
		}
	}else if(B==1){
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(i<=n/2)
				ans+=a[i].x;
			else{
				ans+=a[i].y;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2);k++){
					if(i-j-k>n/2||i-j-k<0)continue;
					if(j!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].x);
					if(k!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].y);
					if(i-j-k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j>n/2)continue;
				ans=max(ans,f[n][i][j]);
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		solve();
	}
	return 0;
}

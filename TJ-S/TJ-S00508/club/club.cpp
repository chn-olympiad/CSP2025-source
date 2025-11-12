/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


f[i][j][k]表示第一个部门分配i个，第二个部门分配j个，第3个部门分配k个的最大值
f[i][j][k] = max(f[i-1][j][k]+a[i][1], f[i][j-1][k]+a[i][2], f[i][j][k-1]+a[i][3])

*/

#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long
const ll maxn=100010;
ll n;
ll a[maxn][4];
ll f[210][210][210];
ll t;
ll read(){
	ll x=0,f=1ll;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void work(){
	n=read();
	memset(f,0ll,sizeof(f));
	memset(a,0ll,sizeof(a));
	for(int i=1;i<=n;i++){
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
	}
	ll ans=0ll;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i+j+k>n) break;
				if(i>=1) f[i][j][k]=f[i-1][j][k]+a[i+j+k][1];
				if(j>=1) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[i+j+k][2]);
				if(k>=1) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[i+j+k][3]);
//				cout<<i<<" "<<j<<" "<<k<<" : "<<f[i][j][k]<<"\n";
				if(i+j+k==n) ans=max(ans,f[i][j][k]);
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	t=read();
	while(t--){
		work();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0,f[5010][5010];
bool p=1;
template<typename tp>void read(tp &x){
	x=0;
	bool f=1;char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())(ch==45)&&(f=0);
	for(;ch>=48&&ch<=57;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x=(f?x:-x);
}
void dfs(int h,int w,int maxx,int zye){
	if(h==n){
		if(zye<3||w<=maxx*2)return;
		ans++;
		ans%=998244353;
		return;
	}
	dfs(h+1,w+a[h+1],max(maxx,a[h+1]),zye+1);
	dfs(h+1,w,maxx,zye);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]>1)p=0;
	}
	if(p==1){
		f[1][1]=1;
		for(int i=2;i<=n+1;i++){
			f[i][1]=f[i][i]=1;
			for(int j=2;j<i;j++)f[i][j]=f[i-1][j-1]+f[i-1][j];
		}
		ans=0;
		for(int i=3;i<=n;i++)ans+=f[n+1][i+1];
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
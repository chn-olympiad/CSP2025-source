#include<bits/stdc++.h>
using namespace std;
#define int long long
struct no{
	int x,y;
}z[100100];
bool cmp(no q,no h){
	return q.x<h.x;
}
int n,k,i,j,a[1010100],f[1010][1010],ans,t,kk,ma;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	int lsx=0,fl=1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) fl=0;
	}
	if(fl){
		int lsy=0;
		for(i=1;i<=n;i++)
			lsy+=a[i];
		if(k) cout<<lsy;
		else cout<<lsy/2;
		return 0;
	}
	for(i=1;i<=n;i++) f[1][i]=f[1][i-1]^a[i];
	for(i=n;i>=1;i--) f[i][n]=f[i+1][n]^a[i];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if(k==((f[1][n]^f[1][i-1])^f[j+1][n]))
				++t,z[t].x=i,z[t].y=j;
	sort(z+1,z+t+1,cmp);
	for(i=1;i<=t;i++){
		ans=1;
		kk=z[i].y;
		for(j=i+1;j<=t;j++){
			if(kk<z[j].x) ans++,kk=z[j].y;
		}
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}
/*
4 3
2 1 0 3

*/

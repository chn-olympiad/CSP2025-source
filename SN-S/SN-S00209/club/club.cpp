#include<bits/stdc++.h>
#define ll long long
#define lb(x) ((x)&-(x))
using namespace std;
const int N=1e5,inf=1e9;
int n,mxid,a[N][3],b[N],c[3],id[N],m,ans;
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	ans=mxid=c[0]=c[1]=c[2]=m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		id[i]=0;
		if(a[i][1]>a[i][0]) id[i]=1;
		if(a[i][2]>a[i][id[i]]) id[i]=2;
		ans+=a[i][id[i]],c[id[i]]++;
	}
	if(c[1]>c[0]) mxid=1;
	if(c[2]>c[mxid]) mxid=2;
	if(c[mxid]<=n/2){
		cout<<ans<<"\n";
		return;
	}
	for(int i=1;i<=n;i++)if(id[i]==mxid){
		b[++m]=-inf;
		for(int j=0;j<3;j++)
			if(mxid!=j)b[m]=max(b[m],a[i][j]-a[i][mxid]);
	}sort(b+1,b+1+m,cmp);
	for(int i=1;i<=c[mxid]-n/2;i++) ans+=b[i];
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
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

*/

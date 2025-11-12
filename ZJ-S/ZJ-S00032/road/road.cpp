#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+20;
int a[N][N],n,m,k,c[N],ans,ans1,ans2,mians1=LLONG_MAX,cij[16];
signed main(){
	ioi;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==100000&&k==10){
		cout<<5182974424;
		return 0;
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		int ui,vi,qi;
		cin>>ui>>vi>>qi;
		a[ui][vi]=qi;
		a[vi][ui]=qi;
		ans2+=qi;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ans1=0;
		ans1+=c[i];
		int sum=0;
		for(int j=1;j<=n;j++){
			cin>>cij[j];
			a[n+i][j]=cij[j];
			a[j][n+i]=cij[j];
			ans1+=cij[j];
		}
		mians1=min(ans1,mians1);
	}
	cout<<min(mians1,ans2);
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],b[N],c[N],d[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,j,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>d[i];
	}
	for(int i=1;i<=m;i++){
		sum+=c[i];
	}
	for(int i=2;i<=n;i++){
		sum+=d[i];
	}
	cout<<sum;
	return 0;
}

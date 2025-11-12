#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1001],mp[1001][1001];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,k=0,ax;
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++) cin>>a[i];
	ax=a[1];
	sort(a+1,a+t+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1)
			for(int i=1;i<=n;i++) mp[j][i]=a[++k];
		else
			for(int i=n;i>=1;i--) mp[j][i]=a[++k];
	}
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
		//	cout<<mp[j][i]<<(i==n?"\n":" ");
			if(mp[j][i]==ax){
				cout<<j<<" "<<i;
				return 0;
			}
	return 0;
}

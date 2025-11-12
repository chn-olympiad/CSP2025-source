#include<bits/stdc++.h>
using namespace std;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],mp[110][110],cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1)
			for(int j=1;j<=n;j++) mp[i][j]=a[++cnt];
		else
			for(int j=n;j>=1;j--) mp[i][j]=a[++cnt];
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j]==f) cout<<i<<" "<<j;
	return 0;
}
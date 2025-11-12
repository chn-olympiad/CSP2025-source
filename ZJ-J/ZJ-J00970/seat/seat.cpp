#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100100],i,j,f[1010][1010],t;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	int k=n*m;
	for(i=1;i<=k;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+k+1,cmp);
	for(i=1;i<=m;i++){
		if(i%2==1){
			for(j=1;j<=n;j++)
				++t,f[j][i]=a[t];
		}
		else if(i%2==0){
			for(j=n;j>=1;j--)
				++t,f[j][i]=a[t];
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(f[i][j]==x)
				cout<<j<<" "<<i;
	return 0;
}


#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m;
pii a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*m+j].first,a[(i-1)*m+j].second=(i-1)*m+j;
	sort(a+1,a+1+n*m);
	int now=n*m;
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++){
			if(a[now].second==1){
				if(j&1) cout<<j<<' '<<i;
				else cout<<j<<' '<<n-i+1;
			}
			now--;
		}
	return 0;
}

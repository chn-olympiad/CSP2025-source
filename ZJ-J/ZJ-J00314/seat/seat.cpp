#include<bits/stdc++.h>
#define int long long
#define N 10010
using namespace std;
int n,m,i,j,lie,hang,x,a[N];
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)cin>>a[(i-1)*m+j];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++){
		lie=(i-1)/n+1;
		if(lie%2==1){
			hang=i-(lie-1)*n;
		}
		else{
			hang=(n+1)-(i-(lie-1)*n);
		}
		if(a[i]==x){
			cout<<lie<<" "<<hang;
			return 0;
		}
	}
	return 0;
}
//8:54 tongguoyangyi1--3
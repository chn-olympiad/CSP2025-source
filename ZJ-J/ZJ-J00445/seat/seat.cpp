#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,n1,i,a[110],j,s,f[110][110],t,t1;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	n1=n*m;
	for(i=1;i<=n1;i++)cin>>a[i];
	s=a[1]; 
	sort(a+1,a+n1+1,cmp);	
	for(i=1;i<=m;i++)
		if(i%2==1){
			for(j=1;j<=n;j++)
				if(i==1)f[i][j]=a[j];
				else t++,f[i][j]=a[t*2*n+j];
		}
		else {
			for(j=n;j>=1;j--)
				if(i==2)f[i][j]=a[2*n-j+1];
				else t1++,f[i][j]=a[2*n-j+1+t1*2*n];
		}
	for(i=1;i<=m;i++)
		if(i%2==1){
			for(j=1;j<=n;j++)
				if(f[i][j]==s)cout<<i<<" "<<j;
		}
		else {
			for(j=n;j>=1;j--)
				if(f[i][j]==s)cout<<i<<" "<<j;
		}
}
				
				
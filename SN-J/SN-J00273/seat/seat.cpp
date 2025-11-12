#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,q=0,ans=0;
	cin>>n>>m;
	long long a[n*m+1];
	long long b[n+1][m+1];
	for(long long i=0;i<=n*m;i++){
		cin>>a[i];
	}
	long long z=a[0];
	for(long long i=n*m;i>=0;i--){
		for(long long j=0;j<=i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	while(q<=n){
		for(long long i=0;i<=m;i++){
			b[q][i]=a[ans];
			ans++;
		}
		q++;
		for(long long j=m;j>=0;j--){
			b[q][j]=a[ans];
			ans++;
		}
		q++;
	}
	for(long long i=0;i<=n;i++){
		for(long long j=0;j<=m;j++){
			if(b[i][j]==z){
				cout<<i+1<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}

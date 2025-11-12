#include <bits/stdc++.h> 
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[105];
	for(long long i=1;i<=n*m;i++) cin>>a[i];
	long long ans=a[1],cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++) if(a[i]==ans) cnt=i;
	long long l=cnt/n,r=cnt%n;
	if(r==0&&l%2==1) cout<<l<<" "<<n;
	else if(l%2==0&&r==0) cout<<l<<" "<<1;
	else if(l%2==0&&r!=0) cout<<l+1<<" "<<r;
	else cout<<l+1<<" "<<n-r+1;
	return 0;
}

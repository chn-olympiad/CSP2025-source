#include<bits/stdc++.h>
using namespace std;
long long n,m,x,t,k,a[105];
bool cmp(long long a,long long b){
	return a>b;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++) if (a[i]==x){
		t=i;
		break;
	}k=t/n;t%=n;
	if (t==0){
		if (k%2==1) cout<<k<<" "<<n;
		else cout<<k<<" 1";
	}else{
		if (k%2==1) cout<<k+1<<" "<<n-t+1;
		else cout<<k+1<<" "<<t;
	}
}
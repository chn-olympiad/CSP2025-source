#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int sc=a[1],cnt=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]>sc){
			cnt++;
		}
		else break;
	}
	int a=(cnt)/n+1,b=(cnt)%n;
	if(a%2==0){
		b=n-b;
	}
	else{
		b++;
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}


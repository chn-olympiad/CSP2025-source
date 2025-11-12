#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[110],t,x,k;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			x=i;
			break;
		}
	}
	x=n*m-x+1;
	if(x%n==0){
		k=x/n;
		cout<<x/n<<" ";
	}else{
		k=x/n+1;
		cout<<x/n+1<<" ";
	}
	if(k%2==0){
		if(x%n==0){
			cout<<1;
		}else{
			cout<<n-(x%n)+1;
		}
	}else{
		if(x%n==0){
			cout<<n;
		}else{
			cout<<x%n;
		}
	}
	return 0;
}/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
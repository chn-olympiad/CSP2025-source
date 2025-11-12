#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n,m,a[N],t;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])t++;
	}
	t++;
	if(t%n==0){
		if(t/n%2==1){
			cout<<t/n<<" "<<n;
		}else{
			cout<<t/n<<" 1";
		}
	}else{
		cout<<t/n+1<<" ";
		if(t/n%2==0)cout<<t%n;
		else cout<<n-t%n+1;
	}
	return 0;
}

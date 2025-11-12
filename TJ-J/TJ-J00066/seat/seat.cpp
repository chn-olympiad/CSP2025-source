#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a,ans=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		int b;
		cin>>b;
		if(b>a){
			ans++;
		}
	}
	int q;
	int p;
	if(ans%n==0){
		q=ans/n;
		p=n;
	}
	else{
		q=ans/n+1;
		p=ans%n;
	}
	//cout<<ans<<endl;
	if(q%2==1){
		cout<<q<<" "<<p;
	}
	else{
		cout<<q<<" "<<n-p+1;
	}
	return 0;
}

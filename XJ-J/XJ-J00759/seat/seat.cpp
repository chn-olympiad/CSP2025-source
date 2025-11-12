#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,ans=0,a=0,b=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for (int i=2;i<=n*m;i++){
		cin>>b;
		if (b>a){
			ans++;
		}
	}
	ans+=1;
	cout<<(ans-1)/n+1<<" ";
	if (((ans-1)/n+1)%2==1){
		if (ans%n==0){
			cout<<n;
			return 0;
		}
		cout<<ans%n<<" ";
	}
	else{
		if (ans%n==0){
			cout<<1;
			return 0;
		}
		cout<<n-ans%n+1;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.in","r",stdin);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]>k) ans++;
		else break;
	}
	if(ans%n==0){
		cout<<ans/n<<" ";
		if((ans/n)%2==1) cout<<n;
		else cout<<1;
	}
	else{
		cout<<ans/n+1<<" ";
		if((ans/n+1)%2==1) cout<<ans-(ans/n)*n;
		else cout<<(ans/n+1)*n-ans+1;
	}
	return 0;
}

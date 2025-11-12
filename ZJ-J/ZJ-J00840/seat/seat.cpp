#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1000],x;
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	int ans;
	for(int i=n*m;i>0;i--){
		if(a[i]==x){
			ans=i;
			break;
		}
	}
	if(ans%n==0){
		if((ans/n)%2==1)cout<<ans/n<<" "<<n;
		else cout<<ans/n<<" "<<1;
	}
	else{
		if((ans/n+1)%2==0)cout<<ans/n+1<<" "<<n-(ans%n)+1;
		else cout<<ans/n+1<<" "<<ans%n;
	}
	return 0;
}
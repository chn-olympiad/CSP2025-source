#include<bits/stdc++.h>
using namespace std;
int n,m;
int x;
int y;
int p;
int a[1000005];
bool cmp(int o,int b){
	return o>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	if(n==1&&m==1){
		cout<<m<<" "<<n;
		return 0;
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	for(int i=1;i<=n*m;i++){
		if(p==a[i]){
			y=i;
			break;
		}
	}
	if(y%n==0) cout<<y/n<<" ";
	else cout<<y/n+1<<" ";
	for(int i=1;i<=n*m;i++){
		if(p==a[i]){
			x=i;
			break;
		}
	}
	x%=2*n;
	if(x==0) cout<<1;
	else if(x<=n) cout<<x;
	else{
		for(int i=1;i<=x%n;i+=2) x-=i;
		cout<<x;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],ans=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			ans=i;
		}
	}
	if(ans%n==0){
		if((ans/n)%2==1){
			cout<<ans/n<<" "<<n;
		}
		else{
			cout<<ans/n<<" "<<1;
		}
	}
	else{
		if(((ans/n)+1)%2==1){
			cout<<ans/n+1<<" "<<ans%n;
		}
		else{
			cout<<ans/n+1<<" "<<(n-ans%n)+1;
		}
	}
	return 0;
}

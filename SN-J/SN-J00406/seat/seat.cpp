#include<bits/stdc++.h> 
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=0,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]!=c){
			ans++;
		}else{
			break;
		}
	}
	if(ans<=n){
		cout<<"1"<<" "<<ans;
	}else if((ans/n+1)%2==0&&ans-ans/n*n==1){
		cout<<ans/n+1<<" "<<n;
	}else if((ans/n+1)%2==0){
		cout<<ans/n+1<<" "<<n-(ans-ans/n*n);
	}else{
		cout<<ans/n+1<<" "<<ans-ans/n*n;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int l;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) l=a[i];
	}
	
	sort(a+1,a+n*m+1);
	
	int maxxx=1;
	for(int i=1;i<=n*m;i++){
		if(l==a[i]){
			maxxx=n*m-i+1;
			break;
		}
	}
	int maxx;
	double ma=maxxx*1.0/n;
	maxx=ma;
	if(ma>maxx){
		maxx++;
	}
	if(maxx%2==1){
		int ans=0;
		ans=maxxx%n;
		
		if(ans==0){
			ans+=n;
		}
		
		cout<<maxx<<' '<<ans<<endl;
	}
	else{
		int ans=maxxx%n;
		if(ans==0){
			ans+=n;
		}
		cout<<maxx<<' '<<n-ans+1<<endl;
	} 
	return 0;
} 

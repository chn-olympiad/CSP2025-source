#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	int cj=a[1];
	sort(a+1,a+1+len,greater<int>());
	for(int i=1;i<=len;i++)
		if(a[i]==cj) ans=i;	
	if(n==1){
		cout<<ans<<" 1";
		return 0;
	}
	if(m==1){
		cout<<"1 "<<ans;
		return 0;
	}
	if(ans<=m){
		cout<<1<<" ";
		if(ans%m==0) cout<<m;
		else cout<<ans%m;
		return 0;
	}
	if(ans%m==0){
		cout<<ans/m<<" ";
		if((ans/m-1)%2==1) cout<<1;
		else cout<<m;
	} 
	else{
		cout<<ans/m+1<<" ";
		if((ans/m)%2==1) cout<<m-ans%m+1;
		else cout<<ans%m;
	} 
	return 0;
}

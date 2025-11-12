#include<bits/stdc++.h>
using namespace std;
   
int a[1000000];
int main()
{
	foropen("seat.in","r",stdin);
	foropen("seat.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	int cnt=a[0];
	int ans=1;
	for(int i=1;i<n*m;++i){
		if(cnt<a[i]){
			ans++;
		}
	}
	if(ans==n*m) cout<<ans/m<<" "<<ans/n-1;
	else if(ans%2==0) cout<<ans/m<<" "<<ans/n+1;
	else if(ans==3) cout<<ans/m+1<<" "<<ans%n+1;
	else cout<<ans/m+1<<" "<<ans%n;

	return 0;
} 

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,s=1,a;
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>k)s++;
	}
	int ans,ans1;
	if(s%n==0){
		ans=s/n;
		if(ans%2==0)ans1=1;
		else ans1=n;
	}
	else{
		ans=s/n+1;
		if(ans%2==0)ans1=n-s%n+1;
		else ans1=s%n;
	}
	cout<<ans<<' '<<ans1<<endl;
	return 0;
}

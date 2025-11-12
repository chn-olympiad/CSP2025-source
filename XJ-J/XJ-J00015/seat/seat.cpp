#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	int a[10000];
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	ans+=a[1];
	sort(a,a+(n*m)+1);
	int sum=0;
	for(int i=n*m;i>=1;i--){
		sum+=1;
		if(ans==a[i])
			break;
	}
	int x=0,y=0;
	if(0<=sum%(n*m)&&sum%(n*m)<=m){
		if(sum%m==0)
			cout<<(sum/m)<<" "<<m; 
		else
			cout<<(sum/m)+1<<" "<<(sum%m);
	}
	else{
		if(sum%m==0)
			cout<<(sum/m)<<" "<<1;
		else
			cout<<(sum/m)+1<<" "<<sum%m;
	}
	
	return 0;
	
} 

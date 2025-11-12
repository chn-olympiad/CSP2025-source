#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int a[N];
int ans=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])ans++;
	}
	int c,r;
	if(ans%m==0){
		c=ans/m;
		ans=ans%m+m;
	}
	else{
		c=ans/m+1;
		ans=ans%m;
	}
	if(c%2==1){
		r=ans;
	}
	else{
		r=m-ans+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

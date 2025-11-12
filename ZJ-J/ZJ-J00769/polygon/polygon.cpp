#include<bits/stdc++.h>
using namespace std;
int a[100003],m,ans=0;
int s(int i,int l,int mx,int sum){
	if(i>m)return 0;
	s(i+1,l+1,max(mx,a[i]),sum+a[i]);
	s(i+1,l,mx,sum);
	if(l>=3&&2*mx<sum){
		ans+=1;
		ans%=998224353;
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=0;i<m;i++)cin>>a[i];
	s(0,0,0,0);
	if(m<4)cout<<ans;
	else if(m=4)cout<<ans-1;
	else cout<<ans-2;
	return 0;
}


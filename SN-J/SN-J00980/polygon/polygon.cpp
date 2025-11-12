// SN-J00980 谈子航  西安经开第二中学 
#include<bits/stdc++.h>
using namespace std;
int n,d[5050],mx,cnt,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int k=1;k<=n;k++){
		mx=0;
		for(int i=1;i<=k;i++){
			mx=max(mx,d[i]);	
			ans+=d[i];
		}
		if(ans>=mx*2)cnt++;
	}
	cout<<cnt;
 return 0;
}


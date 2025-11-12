//SN-J01091 阮书凡 安康中学教育集团初中部
#include<bits/stdc++.h>
using namespace std;
int ans=0,n,a[5005];
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<ans+1;
	return 0;
}

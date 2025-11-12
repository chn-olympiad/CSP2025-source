#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,a[10005];
	int ans=-1,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(a[i],ans);
		cnt+=a[i];
	}
	if(ans*2<cnt){
		cout<<1;
	}
	else cout<<0;
	return 0;
}

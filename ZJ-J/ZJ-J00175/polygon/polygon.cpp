#include<bits/stdc++.h>
using namespace std;
int n,ans,Max,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i],Max=max(Max,a[i]);
	cout<<(n>=3&&ans>Max*2);
	return 0;
}		
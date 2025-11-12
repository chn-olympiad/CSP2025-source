#include<bits/stdc++.h>
using namespace std;
int x;
int n,m,ans=1;
int arr[105];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n;i++)cin>>arr[i];
	for(int i=2;i<=n;i++)ans*=i;
	cout<<ans;
	return 0;
}

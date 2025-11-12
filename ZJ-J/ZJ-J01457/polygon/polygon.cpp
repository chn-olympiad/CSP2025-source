#include<bits/stdc++.h>
using namespace std;
int n,a[5050],s=0;
void j(int x,int sum,int u,int ma)
{
	if(u>=3)if(sum>ma*2)s=(s+1)%998244353;
	for(int i=x+1;i<=n;i++){
		j(i,sum+a[i],u+1,a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)j(i,a[i],1,a[i]);
	cout<<s;
	return 0;
}


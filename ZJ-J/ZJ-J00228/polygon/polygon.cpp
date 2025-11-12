#include<bits/stdc++.h>
using namespace std;
int a[5140];
/*void sm(int t,int mx)
{
	int i;
	if(t==2){
		if(a[1]+a[2]>mx) ans++;
		return;
	}*/
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,mx,ans=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]>a[3]) cout<<1<<endl;
	else cout<<0<<endl;
	/*for(i=3;i<=n;i++)
	{
		mx=a[i];
		sm(i-1,mx);
	}*/
}

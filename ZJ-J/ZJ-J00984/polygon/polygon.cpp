#include<bits/stdc++.h>
using namespace std;
int n,i,s,a[5010];
void dg(int t,int k,long long zh,int mx)
{
	if(t==n+1)
	{
		if(zh>2*mx)
			s++;
		return;
	}
	dg(t+1,k+1,zh+a[t],max(mx,a[t]));
	dg(t+1,k,zh,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	dg(1,0,0,0);
	cout<<s;
}

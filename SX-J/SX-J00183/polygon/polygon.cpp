#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int n;
int xxx(int x,int y,int z,int w)
{
	if(y==1)
	{
		if(z>2*w) return 1;
		else return 0;
	}
	int sum=0;
  	for(int j=x+1;j<=n;j++)
	{
		w=max(w,a[j]);
		sum+=xxx(j,y-1,z+a[j],w);
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int t=3;
	long long atm=0;
	while(t<=n)
	{
		for(int i=1;i<=n;i++)
			atm+=xxx(i,t,a[i],a[i]);
		t++;
	}
	cout<<atm%998244353;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,op,ans,qq,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>op;
	ans=1;
	for(int i=2;i<=n*m;i++)
	{
		cin>>qq;
		if(qq>op)
		{
			ans++;
		}
	}
	l=(ans-1)/n+1;
	h=ans-((l-1)*n);
	if(l%2==0)
	{
		h=n-h+1;
	}
	cout<<l<<" "<<h;
	return 0;
}

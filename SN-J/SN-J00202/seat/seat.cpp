#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,k,s[10000],t,p,x,y;
	cin>>m>>n;
	k=m*n;
	for(int i=0;i<k;i++)
	{
		cin>>s[i];
		if(i==0)
		t=s[i];
		else
		t=t;
	}
	sort(s,s+k);
	for(int j=k;j>0;j--)
	{
		if(s[j]==t)
		p=k-j;
		else
		p=p;
	}
	if(p%2==0)
	y=m;
	else if((p/m)%2==0)
	y=p%m;
	else
	y=m-p%m+1;
	if(p%m==0)
	x=p/m;
	else
	x=p/m+1;
	cout<<x<<" "<<y;
	return 0;
}//想念三月七，白厄，虾米西ing 

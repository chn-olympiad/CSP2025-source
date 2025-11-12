#include<bits/stdc++.h>
using namespace std;
int n,m,s,k,t,h,l,a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
		if(a[i]==s)
		{
			t=i;
			break;	
		}
	for(int i=1;i<=t;i++)
	{
		if(i==1) h=1,l=1;
		else
		{
			if(l%2==1&&h!=n) h++;
			else if(l%2==0&&h!=1) h--;
			else if(l%2==1&&h==n) l++;
			else if(l%2==0&&h==1) l++;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
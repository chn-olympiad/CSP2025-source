#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,a[105],r,ans=0;
	string b[105],space=" ",s;
	char si,sj;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r=i;
			break;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(j=1;j<=n;j++)
			{
				s="";
				si=i+'0';
				sj=j+'0';
				s+=si+space+sj;
				b[++ans]=s;
			}
		}
		else
		{
			for(j=n;j>=1;j--)
			{
				s="";
				si=i+'0';
				sj=j+'0'; 
				s+=si+space+sj;
				b[++ans]=s;
			}
		}
	}
	cout<<b[r];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],cnt,sum,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++)
	{
		int c=0;
		for(int ii=0;ii<n*m;ii++)
		{
			if(c<a[ii])
			{
				c=a[ii];
				b[i]=ii;
			}
		}
		a[b[i]]=0;
//		cout<<b[i]<<" "<<c<<" ";
	}
	for(int i=0;i<n*m;i++)
	{
		if(b[i]==0)
		{
			cnt=i;
		}
	}
	cnt++;
//	cout<<cnt;

	if(cnt%n==0)
	{
	    if(cnt/n%2==1)cout<<cnt/n<<" "<<n;	   
		if(cnt/n%2==0)cout<<cnt/n<<" "<<1;
	    
		return 0;
	}
    cout<<cnt/n+1<<" ";
    if(cnt/n%2==0)cout<<cnt%n;
    if(cnt/n%2==1)cout<<m+1-cnt%n;
	return 0;
}

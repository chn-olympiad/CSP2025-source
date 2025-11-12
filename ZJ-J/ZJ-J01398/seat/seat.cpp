#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int m,n;
struct cheng
{
	int s,m;
	friend bool operator <(cheng x,cheng y)
	{
		return x.s>y.s;
	}
}a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i].s;
    	a[i].m=i;
	}
	sort(a+1,a+n*m+1);
	int l=0;
	 for(int i=1;i<=n*m;i++)
    {
    	if(a[i].m==1)
		{		
		
			if(i<=m)
			{
				cout<<1<<" "<<i;
			} 		
			else
			{
			     if(i%m==0)
			     {
			     	cout<<i/m<<" ";
			     	if((i/m)%2==0) cout<<1;
			        else cout<<m;
				 }
				 else
				 {
				 	cout<<i/m+1<<" ";
				 	if((i/m+1)%2!=0) cout<<i%m;
			        else cout<<n-i%m+1;
				 }
			} 
    		break;
		} 
	}
	return 0;
}

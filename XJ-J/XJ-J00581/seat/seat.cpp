#include<bits/stdc++.h>
using namespace std;
int n,m,s[101][101],a[1001],ans=1;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n*m;i++)
  {
  	int now=a[1];
  	cin>>a[i];
  	if(a[i]>a[1]) ans++;
  }
  //cout<<"ans="<<ans<<"  ";
  for(int i=1;i<=m;i++)
  {
  	if(i%2==1)
  	{
  	  for(int j=1;j<=n;j++)
	  {
	  	if(ans-1==0) 
	  	{
	  	  cout<<i<<" "<<j;	
	  	  return 0;
		}
	    ans--;		
	  }	
	}
	else
	{
	  for(int j=n;j>0;j--)
	  {
	  	if(ans-1==0) 
	  	{
	  	  cout<<i<<" "<<j;	
	  	  return 0;
		}
	    ans--;		
	  }	
	} 
  }
  return 0;
}

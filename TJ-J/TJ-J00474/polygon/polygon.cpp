#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int n;
int a[100001];
int s=0;
cin>>n;
for (int i=0;i<n;i++)
	{
	cin>>a[i];
  if(a[i]+a[i+1]<a[i+2]||a[i]+a[i+1]==a[i+2]||a[i]+a[i+2]<a[i+3]||a[i]+a[i+2]==a[i+3]||a[i]+a[i+3]<a[i+4]||a[i]+a[i+3]==a[i+4]||a[i]+a[i+1]<a[i+3]||a[i]+a[i+1]==a[i+3]||a[i]+a[i+1]<a[i+4]||a[i]+a[i+1]==a[i+4]||a[i]+a[i+2]<a[i+4]||a[i]+a[i+2]==a[i+4]) 
	{
 continue;
	}
	else if(a[i+1]+a[i+2]>a[i+3]||a[i+1]+a[i+3]>a[i+4]||a[i+1]+a[i+3]>a[i+4])
    {
    	s++;
    	}
	} 
	 cout<<s%998244353;
	return 0;
}

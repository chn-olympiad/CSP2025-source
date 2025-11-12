//SN-J00534 高新二中 李昊泽 
#include<bits/stdc++.h>
using namespace std;
int n,k; 
int a[1500000];
int s[1500000];
bool b[1000500];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int l=1,r=1;
	while(r<=n)
	{
		int xr=s[r]^s[l-1];
		if(xr==k)
		{
			ans++;
//			cout<<l<<" "<<r<<" "<<s[r]<<" "<<s[l-1]<<" "<<xr<<endl;
			r++;
			l=r;
			
		}
		else if(xr<k)
		{
			if(r==n) l++;
			else r++;
		}
		else
		{
			if(l!=r)
			{
				l++;
			}
			else
			{
				l++;
				r++;
			}
		}
	}
	cout<<ans;
	return 0;
	
}

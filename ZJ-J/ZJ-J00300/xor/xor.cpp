#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],res,cnt=0,ans;
bool f=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	
	for(int i=1;i<=n;)
	{
		for(int j=i;j<=n;j++)
		{
			cnt^=a[j];
			if(cnt==k) 
			{
				i=j+1;
				res++;
				f=1;
				break;
			}
		}  
		if(f==0) i++;
		f=0;
		cnt=0;
	}
	cout<<res;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500001];
int b[500001];
int c[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i-1]^a[i];
        c[i]=b[i-1]^b[i];
        if(c[i]==k&&c[i-1]==k||c[i]==k&&c[i+1]==k)
        {
        	cnt++;
		}
		if(b[i]==k&&b[i-1]==k||b[i]==k&&b[i+1]==k)
        {
        	cnt++;
		}
        if(a[i]==k)
		{
			cnt++;
		}
	}
	cout<<cnt;
}
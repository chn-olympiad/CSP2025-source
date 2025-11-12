#include <bits/stdc++.h>
using namespace std;
int n,k;
long long a[500010]={0};
long long s[500010]={0};
int ct=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=(a[i]^s[i-1]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((s[i]^s[j])==k)
			{
				ct++;
				i=j-1;
				break;
			}
		}
	}
	cout << ct;
	return 0;
}



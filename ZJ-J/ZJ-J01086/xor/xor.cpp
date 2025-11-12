#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],sum=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	long long l=1,r=1;
	while(r<=n)
	{
		int m=s[r]^s[l-1];
		if(m==k||a[r]==k)
			sum++,l=r+1,r++;
		else 
			r++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
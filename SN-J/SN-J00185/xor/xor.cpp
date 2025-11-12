#include<bits/stdc++.h>
using namespace std;
long long v[100000];
long long mxor(long long x,long long y)
{
	long long s = 0;
	for (long long i = 0;i <= 20;i++)
	{
		s = s << 1;
		if ((x >> i) % 2 != (y >> i) % 2) s++;
//		cout <<(x >> i) % 2 <<" "
//		<<(y >> i) % 2<<" "<<s<<endl;
	}
	long long r = 0;
	for (long long i = 0;i <= 20;i++)
	{
		r = r << 1;
		if ((s >> i) % 2) r++;
		
	}
	return r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for (long long i = 1;i <= n;i++) 
	{
		cin>>v[i];
		v[i] = mxor(v[i],v[i - 1]);
	}
	long long s = 0;
	for (long long l = 1;l <= n;l++)
	{
		for (long long r = l;r <= n;r++)
		{
			if (mxor(v[r],v[l - 1]) == k)
			{
				s ++;
				l = r + 1;
			}
		}
		
	}
	cout<<s;
	return 0;
}


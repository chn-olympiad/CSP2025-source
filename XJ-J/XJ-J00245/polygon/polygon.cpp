#include<bits/stdc++.h>
using namespace std;
long long a[5001];long long zz=0;
long long t(long long x)
{
	if((x==1)||(x==0)) return 1;
	else return x*t(x-1);
}
void wd(long long x)
{
	for(long long i=1;i<=x-1;i++)
	{
		if(a[i]+a[i-1]>a[x])
		{
			for(long long q=2;q<(x-i+1);q++)
				{
					zz+=(t(x-i)/(t(q)*t(x-i-q)));
				}
				break;
		}
		z-=2;
	}
	return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(long long j=n;j>=2;j--)
	{
		wd(j);
	}
	cout<<zz;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

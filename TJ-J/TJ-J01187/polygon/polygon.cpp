#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],l,r,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(l=1;l<=n;l++)
	{
		for(r=n;r>=l;r--)
		{
			int cnt=0;
			for(int i=l;i<=r;i++)
			{
				cnt+=a[i];
				cout<<a[i]<<" ";
			}
			cout<<endl;
			if(cnt>a[r]*2) sum++;
		}
	}
	cout<<(sum%998244353);
	return 0;
}

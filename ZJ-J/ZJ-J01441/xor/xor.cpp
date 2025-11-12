#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000005],ans=0,cnt=0;
bool f=false,flag=false,zhongji=false;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=true;
		}
		if(a[i]>1)
		{
			flag=true;
		}
		if(a[i]>255)
		{
			zhongji=true;
		}
	}
	if(f==false)
	{
		cout<<n/2;
		return 0;
	}
	else
	{
		if(flag==false)
		{
			cnt=0;
			if(k==0)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i]==k)
					{
						cnt+=ans/2;
						cnt++;
						ans=0;
					}
					else
					{
						ans++;
					}
				}
				cout<<cnt;
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i]==k)
					{
						cnt++;
					}
				}
				cout<<cnt;
			}
			return 0;
		}
		else
		{
			if(zhongji==false)
			{
				for(int i=1;i<=n;i++)
				{
					a[i]=a[i] xor a[i-1];
				}
				for(int i=1;i<=n;i++)
				{
					for(int j=0;j<=n-i;j++)
					{
						if((a[i+j] xor a[i-1])==k)
						{
							//cout<<a[i+j]<<" "<<a[i-1]<<" "<<(a[i+j] xor a[i-1])<<" "<<k<<"\n";
							cnt++;
							i=i+j;
							break;
						}
					}
				}
				cout<<cnt;
				return 0;
			}
		}
	}
	return 0;
}
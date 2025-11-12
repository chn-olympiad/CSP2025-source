#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long shu[500001],qian[500001];
long long last = 1;
long long num = 0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(long long i = 1;i<=n;i++)
	{
		cin>>shu[i];
		qian[i] = (qian[i-1]^shu[i]);
	}
	for(long long i = 1;i<=n;i++)
	{
		if(i == last)
		{
			for(long long j = i;j<=n;j++)
			{
				if((qian[j]^qian[i-1]) == k)
				{
					last = j+1;
					num+=1;
					break;
				}
			}
		}
	}
	cout<<num<<endl;
	return 0;
}
//cout<<(1^2)<<endl;
//x^y = z
//z^y = x,z^x = y;

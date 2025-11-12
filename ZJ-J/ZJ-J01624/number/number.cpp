#include<bits/stdc++.h>
using namespace std;
int a;
long long cnt,ans;
int x[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(a)
	{
		x[a%10]++;
		a/=10;
		cnt++;
	}
	long long s=cnt;
	for(int i=9;i>=0;i--)
	{
		if(x[i+1]>0)
		{
			i++;
			x[i]--;
			int o=1;
			while(s)
			{
				o=o*10;
				s--;
			}
			ans+=o*i/10;
			cnt--;
			s=cnt;
		}
	}
	cout<<ans;
	return 0;
}

#include <iostream>
using namespace std;
int n,k,cnt;
int s[5*100000+1];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}

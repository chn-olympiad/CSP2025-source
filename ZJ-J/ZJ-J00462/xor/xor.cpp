#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,k;
int a[N],vis[N],id;
bool f;
ll s[N],cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	vis[k]++;
	id=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[s[i]])
		{
			bool fl=0;
			for(int j=id;j<i;j++)
			{
				if(s[j]^s[i]==k)
				{
					cnt++;
					fl=1;
					break;
				}
			}
			if(fl)
			{
				for(int j=id;j<i;j++)
				{
					vis[s[j]^k]--;
				}
				id=i;
			}
		}
		vis[s[i]^k]++;
	}
	cout<<cnt<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
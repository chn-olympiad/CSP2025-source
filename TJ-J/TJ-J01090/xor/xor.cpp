#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector < pair<int,int> > v;
int n,k,a[500005],b[500005];
bool baoh(int l1,int r1,int l2,int r2)
{
	return (l2 <= l1 && r1 <= r2);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool ais1 = true,a10 = true;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i] = b[i-1]^a[i];
		ais1 &= (a[i]==1);
		a10 &= (a[i]<=1);
	}
	if(ais1 == true && k == 0)
	{
		cout << n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((b[j]^b[i-1]) == k)
			{
				v.push_back({i,j});
			}
		}
	}
	int len = v.size();
	map <int,bool> notfuh;
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(baoh(v[i].first,v[i].second,v[j].first,v[j].second))
			{
				notfuh[j] = true;
			}
			else if(baoh(v[j].first,v[j].second,v[i].first,v[i].second))
			{
				notfuh[i] = true;
			}
		}
	}
	cout << v.size()-notfuh.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
long long xpre[500001],a[500001];
int n,k;
vector<pair<int,int> > num;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		xpre[i] = xpre[i - 1] ^ a[i];
	}
//	for(int i = 1;i <= n;i++) cout << xpre[i] << " ";
//	cout << endl;
	for(int i = 1;i <= n;i++)
		for(int j = i;j <= n;j++)
		{
			if((xpre[i - 1] ^ xpre[j]) == k)
			{
				num.push_back({i,j});
//				cout << (xpre[i - 1] ^ xpre[j]) << endl;
			}
		}
	sort(num.begin(),num.end());
//	for(int i = 0;i < num.size();i++) cout << num[i].first << " " << num[i].second << endl;
	int pos = num[0].second,cnt = 1;
	for(int i = 1;i < num.size();i++)
	{
		if(num[i].first > pos)
		{
			pos = num[i].second;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

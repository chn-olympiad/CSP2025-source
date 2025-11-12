#include<bits/stdc++.h>
using namespace std;
string s;
int sum[1000001];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number,in","r",stdin);
	freopen("number,out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	int ans = 0;
	int k = 0;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			sum[k] = s[i] - '0';
			k++;
		}
	}
	sort(sum,sum + k,cmp);
	for(int i = 0;i < k;i++)
	{
		cout<<sum[i];
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int numlen=0;
short nums[N];
bool cmp(short a,short b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string S;
	cin>>S;
	for (int i=0;i<S.size();i++)
	{
		if (S[i]>=48 and S[i]<=57)
		{
			nums[numlen]=S[i]-48;
			numlen++;
		}
	}
	sort(nums,nums+numlen,cmp);
	for (int i=0;i<numlen;i++)
	{
		cout<<nums[i];
	}
	cout<<endl;
	return 0;
}

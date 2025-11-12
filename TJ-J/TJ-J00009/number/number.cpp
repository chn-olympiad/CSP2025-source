#include<bits/stdc++.h>
using namespace std;
string s;
int nums[1000010];
int k = 0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.size();
	for(int i = 0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k+=1;
			nums[k]=s[i]-'0';
		}
	}
	sort(nums+1,nums+k+1,cmp);
	for(int i = 1;i<=k;i++)
	{
		cout<<nums[i];
	}
	return 0;
}

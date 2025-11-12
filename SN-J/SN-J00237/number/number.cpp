//西安高新第二初级中学  姜璟烁  SN-J00237 
#include<bits/stdc++.h>
using namespace std;
string s;
const int maxn=1e7;
char a[maxn];
int cnt;
bool isnum(char c)
{
	if(c<=57&&c>=48)
	{
		return true;
	}
	else 
	return false;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isnum(s[i]))
		{
			a[cnt]=s[i];
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}

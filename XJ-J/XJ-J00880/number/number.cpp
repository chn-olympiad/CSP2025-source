#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int map[1001900];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l,k=0;
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			map[k++]=s[i]-'0';
		}
	}
	sort(map,map+k,cmp);
	for(int i=0;i<k;i++)
	{
		printf("%d",map[i]);
	}
	return 0;
}

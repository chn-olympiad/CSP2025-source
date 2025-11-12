//SN-J00833 白敬轩 西安高新一中沣东中学  
#include<bits/stdc++.h>
using namespace std;
string s;
int j=0,num[1000005];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			num[j]=s[i]-'0';
			j++;
		}
	}
	sort(num,num+j,cmp);
	for(int i = 0;i < j;i++) cout << num[i];
	return 0;
}

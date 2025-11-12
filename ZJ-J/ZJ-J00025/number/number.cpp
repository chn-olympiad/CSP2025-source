#include<bits/stdc++.h>
using namespace std;
int a[1000010],len;
string s,ans;
bool cmp(int xx,int yy)
{
	return xx>=yy;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i]>='0' && s[i]<='9')   ans+=s[i];
	}
	for(int i = 0; i < ans.size(); i++)    a[++len] = ans[i]-'0';
	sort(a+1,a+len+1,cmp);
	for(int i = 1; i <= len; i++)    printf("%d",a[i]);
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x, int y)
{
	return x>y;
}
string s,a="";
vector<long long>b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a+=s[i];
	}
	for(int i=0;i<a.size();i++)
	{
		b.push_back(a[i]-'0');
	}
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<a.size();i++)
	{
		cout<<b[i];
	}
	return 0; 
}


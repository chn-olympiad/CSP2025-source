#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int f=0;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9') {
			a[f]=s[i]-'0';
			f++;
		}
		else 
			continue;
	}
	sort(a,a+f,cmp);
	for(int i=0;i<f;i++) cout<<a[i];
	return 0;
}

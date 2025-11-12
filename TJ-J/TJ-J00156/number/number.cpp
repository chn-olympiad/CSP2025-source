#include<bits/stdc++.h>
using namespace std;

int a[1000100],cur=1,ans=0;
string s;
bool flag=false;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.size());i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cur]=s[i]-'0';
			cur++;
		}
	}
	sort(a+1,a+cur+1,cmp);
	for(int i=1;i<cur;i++)
	{
		if(a[i]==0&&!flag) continue;
		cout<<a[i];
		flag=true;
	}
	return 0;
}

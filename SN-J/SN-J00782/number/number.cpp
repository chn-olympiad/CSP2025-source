//考号:SN-J00782  姓名:王浩轩  学校:西安滨河学校
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s,n;
	int ns,ni,ss;
	cin>>s;
	ss=s.size();
	for(int i=0;i<ss;i++)
	{
		if(int(s[i])>='0' and int(s[i])<='9')
		{
			n+=s[i];
		}
	}
	ns=n.size();
	for(int i=0;i<ns;i++)
	{
		a[i]=n[i]-48;
	}
	sort(a,a+ns);
	for(int i=ns-1;i>=0;i--)
	{
		cout<<a[i];
	}
    return 0;
}


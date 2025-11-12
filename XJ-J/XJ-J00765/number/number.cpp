#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100000];
	cin>>s;
	int n[100000];
	for(int a=0;a<100000;a++)
		n[a]=-1;
	for(int a=0;s[a]!='\0';a++)
	{
		if(s[a]>='0'&&s[a]<='9')
			n[a]=s[a]-'0';
	}
	sort(n,n+100000); 
	for(int a=99999;n[a]!=-1;a--)
		cout<<n[a];
	return 0;
}


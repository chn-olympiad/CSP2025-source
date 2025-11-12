#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int qwq[1000010],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(s,'*',sizeof(s));
	cin>>s;
	for(int i=1;i<=1000010;i++){
		if(s[i]=='*') break;
		if(0<=s[i]-'0'&&s[i]-'0'<=9)
			qwq[++cnt]=s[i]-'0';          
	}
	sort(qwq+1,qwq+1+cnt);
	if(qwq[cnt]==0)
	{
		cout<<0<<endl;
		return 0;
	}
	else   
	{
		while(cnt>0)
		{
			printf("%d",qwq[cnt]);
			cnt--;
		}
	}
	return 0;
}
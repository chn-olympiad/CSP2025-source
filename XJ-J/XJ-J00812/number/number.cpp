#include<bits/stdc++.h>
using namespace std;
char numpart[100005],ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,k,num,cnt=0,ant=1,lend;
	string s;
	cin>>s;
	s+=' ';
	i=1;
	while(s[i]!=' ')
	{
		i++;
	}
	cnt=0;
	for(j=0;j<=i;j++)
	{
		if(s[j]=='9' or s[j]=='8' or s[j]=='7' or s[j]=='6' or s[j]=='5' or s[j]=='4' or s[j]=='3' or s[j]=='2' or s[j]=='1' or s[j]=='0')
		{
			cnt++;
			numpart[cnt]=s[j];
		}
	}
	sort(numpart+1,numpart+i+1);
	for(j=i;j>=1;j--)
	{
		cout<<numpart[j];
	}
	return 0;
} 

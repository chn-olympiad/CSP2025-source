#include<bits/stdc++.h>
using namespace std;
string str[200005][2];
string s,c;
string substr(string ch,int k,int j,int y)
{
	int o=0;
	for(int i=k;i<j;i++)
		ch[i]=str[y][1][o],o++;
	return ch;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>str[i][0]>>str[i][1];
	while(q--)
	{
		cin>>s>>c;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int w=s.find(str[i][0]);
			if(s.find(str[i][0])!=string::npos&&c.find(str[i][1])!=string::npos&&substr(s,w,w+str[i][0].size(),i)==c)
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}


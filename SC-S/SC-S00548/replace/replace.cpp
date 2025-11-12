#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[1001][2];
int p[1000101]={0},len2[1000101]={0},len3[1000101]={0}; 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(m--)
	{
		string a,b;
		cin>>a>>b;
		int j=0,len=a.size();
		for(int i=0;i<=len+10;i++)
		{
			p[i]=len2[i]=len3[i]=0;
		}
		int cnt=0;
		if(a[0]==b[0]) len2[0]=1;
		if(a[len-1]==b[len-1]) len3[len-1]=1;
		for(int i=1;i<len;i++)
		{
			len2[i]=len2[i-1];
			len3[len-i-1]=len3[len-i];
			if(a[i]==b[i]) len2[i]=len2[i-1]+1;
			if(a[len-i-1]==b[len-i-1]) len3[len-i-1]=len3[len-i]+1;
		}
		for(int l=1;l<=n;l++)
		{
			int j=0,lenn=s[l][0].size();
			for(int i=1;i<lenn;i++)
			{
				while(j>0&&s[l][0][j]!=s[l][0][i]) j=p[j-1];
				if(s[l][0][j]==s[l][0][i]) j++;
				p[i]=j;
			}
			j=0;
			for(int i=0;i<len;i++)
			{
			if(s[l][0][j]==a[i]) j++;
				else if(j>0) j=p[j-1];
				if(j==lenn)
				{
					int as=len3[i+1];
					if(i-lenn>=0)
					{
						as+=len2[i-lenn];
					}
					int e=0;
					for(int k=i-lenn+1;k<=i;k++)
					{
						if(s[l][1][e]==b[k]) as++;
						e++;
					}
					if(as==len) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
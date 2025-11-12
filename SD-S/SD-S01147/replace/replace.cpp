#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
int n,q;
string a1,a2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin >> a1 >> a2;
		int st=0,en=0,sa=0;
		int len=a1.size();
		int le2=a2.size();
		if(len!=le2)
		{
			cout << 0 << endl;
			continue;
		}
		for(int i=0;i<len;i++)
		{
			if(a1[i]!=a2[i]&&st==0&&sa==0)
			{
				st=i;
				sa=1;
			}
			if(a1[i]==a2[i]&&(st!=0||sa==1))
			{
				en=i;
			}
			if(a1[i]!=a2[i]&&en!=0)
			{
				st=0;
				break;
			}
		}
		if(st==0)
		{
			cout << 0 << endl;
			continue;
		}
		if(st==0&&en!=0)
		{
			en=len;
		}
		en--;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s1[i].size()<en-st+1)
			{
				continue;
			}
			for(int j=0;j<s1[i].size();j++)
			{
				int f=0;
				if(s1[i][j]==a1[st]&&s2[i][j]==a2[st])
				{
					f=1;
					for(int k=j;k<=j+en-st;k++)
					{
						if(s1[i][k]==a1[k-j+st]&&s2[i][k]==a2[k-j+st])
						{
							continue;
						}
						f=0;
						break;
					}
					if(f==1)
					{
						for(int k=0;k<s1[i].size();k++)
						{
							if(a1[st-j+k]==s1[i][k]&&a2[st-j+k]==s2[i][k])
							{
								continue;
							}
							f=0;
							break;
						}
						if(f==1)
						{
							ans++;
							break;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
4 2
xabcx xadex 
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

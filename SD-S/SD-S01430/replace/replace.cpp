//longlong? MLE? clear?
#include<bits/stdc++.h>
#define pb push_back
#define LOCAL
using namespace std;
int n,m;
vector<string> s,t;
int main()
{
	#ifdef LOCAL
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string ss,tt;
		cin>>ss>>tt;
		s.pb(ss);
		t.pb(tt);
	}
	for(int i=1;i<=m;i++)
	{
		string ss,tt;
		cin>>ss>>tt;
		if(ss.size()!=tt.size())
		{
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int j=0;j<n;j++)
		{
			if(ss.find(s[j])==string::npos)
			{
				continue;
			}
			else
			{
				int pos=-1;
				do
				{
					string ttt=ss;
					pos=ss.find(s[j],pos+1);
					for(int k=pos,l=0;l<=s[j].size()-1;k++,l++)
					{
						ttt[k]=t[j][l];
					}
					if(ttt==tt)ans++;
				}
				while(pos+1<=ss.size()-1&&ss.find(s[j],pos+1)!=string::npos);
			}
		}
		printf("%d\n",ans);
	}
	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
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

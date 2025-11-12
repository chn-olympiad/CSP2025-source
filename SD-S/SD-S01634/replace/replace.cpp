#include <bits/stdc++.h>

using namespace std;

string s1[200010];
string s2[200010];
string t1[200010];
string t2[200010];
int n,q;
void solve1()
{
	for (int i=0;i<q;++i)
	{
		int l1=min(t1[i].size(),t2[i].size());
		int front=l1,back=0;
		for (int j=0;j<l1;++j)
		{
			if(t1[i][j]!=t2[i][j])
			{
				front=min(front,j);
				back=max(back,j);
			}
		}
		int res=0;
		for (int j=0;j<n;++j)
		{
			int pos1=0;
			int pos2=0;
			int l2=s1[j].size();
			for (;pos1<l1-l2+1;++pos1)
			{
				for (int v=pos1;v<pos1+l2;++v)
				{
					if((t1[i][pos1]!=s1[j][v-pos1])||(t2[i][pos1]!=s2[j][v-pos1]))
						break;
					if((v=pos1+l2-1)&&(pos1<=front)&&(v>=back)) ++res;
				}
			}
		}
		cout<<res<<'\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=0;i<n;++i)
		cin>>s1[i]>>s2[i];
	for (int i=0;i<q;++i)
		cin>>t1[i]>>t2[i];
	solve1();
	return 0;
}


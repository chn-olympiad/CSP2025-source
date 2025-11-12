#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],t1,t2,t3;
bool x;
bool check(int d)
{
	for(int i=0;i<=t1.size()-s1[d].size();++i)
	{
		t3=t1;
		x=true;
		for(int j=i;j<=i+s1[d].size()-1;++j)
			if(t3[j]!=s1[d][j-i])
			{
				x=false;
				break;
			}
		if(!x)continue;
		for(int j=i;j<=i+s1[d].size()-1;++j)
			t3[j]=s2[d][j-i];
		if(t3==t2)return true;
	}
	return false;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)cin>>s1[i]>>s2[i];
	while(q--)
	{
		cin>>t1>>t2;
		ans=0;
		for(int i=1;i<=n;++i)
			if(check(i))
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}

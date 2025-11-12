#include<bits/stdc++.h>
using namespace std;
int n,q;
int l[200001];
string s1[200001],s2[200001];
string t1,t2;
int ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],l[i]=s1[i].length();
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t1>>t2;
		if(t1.length()!=t2.length())
		{
			putchar('0');
			putchar('\n');
			continue;
		}
		for(int j=1;j<=n;j++)
			{
				int k=t1.find(s1[j]);
				if(t1.substr(0,k)+s2[j]+t1.substr(k+l[j],t1.length()-k-l[j])==t2) ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}

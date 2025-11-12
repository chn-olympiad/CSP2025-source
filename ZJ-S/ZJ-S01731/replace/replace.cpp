#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int a[maxn];
struct node
{
	string s[2];
};
bool cmp(node xx,node yy)
{
	return xx.s[0].length()<yy.s[0].length();
}
node sp[maxn];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>sp[i].s[0]>>sp[i].s[1];
	}
	sort(sp+1,sp+n+1,cmp);
	for(int i=1;i<=q;i++)
	{
		string ti,tj;
		cin>>ti>>tj;
		int posl=ti.length()-1,posr=0;
		for(int l=0;l<ti.length();l++)
		{
			if(ti[l]==tj[l])
				continue;
			posr=l;
			if(l<=posl)
				posl=l;
		}
		ll ans=0;
		for(int j=1;j<=n;j++)
		{
			if(sp[j].s[0].length()<posr-posl+1)
				continue;
			for(int k=posr-sp[j].s[0].length()+1;k<=posl;k++)
			{
				int flag=1;
				for(int t=0;t<sp[j].s[0].length();t++)
				{
					if(sp[j].s[0][t]!=ti[t+k]||sp[j].s[1][t]!=tj[t+k])
					{
						flag=0;
						break;
					}
				}
				if(flag)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



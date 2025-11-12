#include<bits/stdc++.h>
using namespace std;
long long n,q,x[100005],ans,ll,l[200005],r[200005],f;
string s1[200005],s2[200005],ss1,ss2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].size();
		for(int j=0;j<l[i];j++)
		if(s1[i][j]!=s2[i][j])
			r[i]++;
	}
	while(q--)
	{
		ans=0;
		cin>>ss1>>ss2;
		ll=ss1.size();
		x[0]=0;
		for(int i=0;i<ll;i++)
		{
			if(i>0)
				x[i]=x[i-1];
			if(ss1[i]!=ss2[i])
			x[i]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(r[i]!=x[ll-1])
				continue;
			for(int j=0;j<=ll-l[i];j++)
			{
				f=0;
				if(ss1[j]==s1[i][0])
				{
					if(j>0)
					{
						if(x[j+l[i]-1]-x[j-1]!=r[i])
						{
							continue;
						}
						for(int k=j;k<j+l[i];k++)
						if(ss1[k]!=s1[i][k-j]||ss2[k]!=s2[i][k-j])
						{
							f=1;
							break;
						}
						if(!f)
							ans++;
					}
					else
					{
					if(x[j+l[i]-1]!=r[i])
						{
								continue;
						}
						for(int k=j;k<j+l[i];k++)
						if(ss1[k]!=s1[i][k-j]||ss2[k]!=s2[i][k-j])
						{
							f=1;
							break;
						}
						if(!f)
							ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

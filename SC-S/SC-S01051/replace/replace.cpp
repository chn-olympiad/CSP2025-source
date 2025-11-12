#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
int n,q,z[3]={0,-1,-1},ans;
string s[200010][2],t[200010][2];
bool flag;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	I AK CSP
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][0]>>t[i][1];
		ans=0; z[1]=-1,z[2]=-1; flag=false;
		if((int)t[i][0].size()!=(int)t[i][1].size()) 
		{
			cout<<"0"<<'\n';
			continue;
		}
		int l=t[i][0].size();
		for(int j=0,k=l-1;j<=k;j++,k--)
		{
			if(t[i][0][j]!=t[i][1][j]&&z[1]==-1) z[1]=j;
			if(t[i][0][k]!=t[i][1][k]&&z[2]==-1) z[2]=k;
			if(z[1]!=-1&&z[2]!=-1) break;
		}
		if(z[1]!=-1&&z[2]!=-1) z[0]=z[2]-z[1]+1;
		else if(z[1]==-1&&z[2]==-1)
		{
			cout<<"0"<<'\n';
			continue;
		}
		else z[0]=1;
		for(int j=1;j<=n;j++)
		{
			int r=s[i][0].size();
			if(r<z[0]) continue;
			else
			{
				for(int k=0;k<=r-z[0];k++)
				{
					for(int o=z[1]+k;o<=z[2];o++) if(t[i][0][o]!=s[i][0][k]||t[i][1][o]!=s[i][1][k]) flag=true;
					if(!flag) ans++;
					flag=false;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
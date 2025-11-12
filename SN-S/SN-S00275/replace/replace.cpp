#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+10,P=998244353;

int n,q;
string s1[N],s2[N];

ll ha1[N],ha2[N];
ll has1[2010][2010],has2[2010][2010];

map<pair<int,int>,int> mp;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) 
	{
		cin>>s1[i]>>s2[i];
		for (int j=0;j<s1[i].size();j++)
		{
			ha1[i]=(ha1[i]*37+s1[i][j]-'a'+1)%P;
			ha2[i]=(ha2[i]*37+s2[i][j]-'a'+1)%P;
		}	
		mp[{ha1[i],ha2[i]}]++;
	}
	
	while (q--)
	{
		string t1,t2; cin>>t1>>t2; int m=t1.size(); t1='0'+t1; t2='0'+t2;
		if (t1.size()!=t2.size()) {cout<<"0\n"; continue;}
		
		for (int l=1;l<=m;l++) for (int r=l;r<=m;r++)
		{
			has1[l][r]=(has1[l][r-1]*37+t1[r]-'a'+1)%P;
			has2[l][r]=(has2[l][r-1]*37+t2[r]-'a'+1)%P;
		}
		
		ll ans=0;
		for (int l=1;l<=m;l++) for (int r=1;r<=m;r++)
		{
			if (r==m || has1[r+1][m]==has2[r+1][m])
			{
				if (l==1 || has1[1][l-1]==has2[1][l-1])
				if (mp.count({has1[l][r],has2[l][r]}))
				{
					ans+=mp[{has1[l][r],has2[l][r]}];
				}
			}
		}
		
		cout<<ans<<"\n";
	}

	return 0;
}





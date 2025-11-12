#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define ull unsigned long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
int c[101];
int p[101];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do
	{
		int no=0,ly=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||no>=c[p[i]])
			{
				no++;
				continue;
			}
			ly++;
		}
		if(ly>=m) ans++;
		//for(int i=1;i<=n;i++) cerr<<p[i]<<" ";
	}
	while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
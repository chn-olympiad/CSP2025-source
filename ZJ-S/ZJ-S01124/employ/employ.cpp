#include<bits/stdc++.h>
using namespace std;
const int N=505;
char s[N];
int a[N],id[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>a[i],id[i]=i;
	sort(a+1,a+n+1);
	if(m==n)
	{
		if(!a[1]) cout<<"0\n";
		else
		{
			bool flag=1;
			for(int i=1;i<=n;i++) if(s[i]=='0') flag=0;
			cout<<flag<<"\n";
		}
		return 0;
	}
	int ans=0;
	do
	{
		int c=0,x=0;
		for(int i=1;i<=n;i++)
		{
			if(a[id[i]]<=c||s[i]=='0') c++;
			else x++;
		}
		if(x>=m) ans++;
	}while(next_permutation(id+1,id+n+1));
	cout<<ans<<"\n";
	return 0;
}

// AVENGER_M & sanyueyetu
// zhu wo bu yao gua fen

// I MISS HER

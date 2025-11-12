#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=2e5+10;

int len[N],n,m;
ull val1[N],val2[N],hsh1[N],hsh2[N],pw[N];
string s1,s2;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
	{
		cin >> s1 >> s2;
		len[i]=s1.length();
		for(int j=0;j<len[i];j++) val1[i]=val1[i]*29+s1[j]-'a'+1;
		for(int j=0;j<len[i];j++) val2[i]=val2[i]*29+s2[j]-'a'+1;
    }
    pw[0]=1;
    for(int i=1;i<=2e3;i++) pw[i]=pw[i-1]*29;
    for(int i=1;i<=m;i++)
    {
        cin >> s1 >> s2;
    	int t1=s1.length(),t2=s2.length();
    	s1=" "+s1,s2=" "+s2;
    	if(t1!=t2)
    	{
    		cout << 0 << '\n';
    		continue;
		}
		for(int i=1;i<=t1;i++) hsh1[i]=hsh1[i-1]*29+s1[i]-'a'+1;
		for(int i=1;i<=t2;i++) hsh2[i]=hsh2[i-1]*29+s2[i]-'a'+1;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k+len[j]-1<=t1;k++)
			{
				if(hsh1[k-1]==hsh2[k-1]&&hsh1[t1]-hsh1[k+len[j]-1]*pw[t1-k-len[j]+1]==hsh2[t2]-hsh2[k+len[j]-1]*pw[t2-k-len[j]+1]&&hsh1[k+len[j]-1]-hsh1[k-1]*pw[len[j]]==val1[j]&&hsh2[k+len[j]-1]-hsh2[k-1]*pw[len[j]]==val2[j])
					ans++;
			}
		}
		cout << ans << '\n';
    }
    return 0;
}
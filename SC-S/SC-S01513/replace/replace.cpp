#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read()
{
	LL w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
} 
string s1[200005],s2[200005];
LL n,q;
string replace(string x,LL y)
{
    string p=s1[y],m=x;
	for(LL i=0;i<=m.size()-p.size()+1;i++)
	{
		for(LL j=0;j<p.size();j++)
		{
			if(m[i+j]!=p[j])
			{
				break;
			}
			if(j==p.size()-1)
			{
				for(LL z=0;z<p.size();z++)
				{
					m[i+z]=s2[y][z];
				}
				return m;
			}
		}
	}
}
void solve()
{
	string a,b;
	LL ans=0;
    cin>>a>>b;
	for(int i=1;i<=n;i++)
	{
		if(replace(a,i)==b)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(LL i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
    while(q--)
	{
     	solve();
	}
    fclose(stdin);
    fclose(stdout);
}
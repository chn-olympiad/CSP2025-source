#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string t1,t2;
string s1,s2;
string cha1[10010],cha2[10010];
void solve()
{
	int ans=0;
	string chayi1="",chayi2="";
	int l=-1,r=-1;
	int len1=t1.size(),len2=t2.size();
	if(len1!=len2)
	{
		cout<<0<<endl;
		return;
	}
	for(int i=0;i<len1;i++)
	{
		if(t1[i]!=t2[i])
		{
			l=i;
			break;
		}
	}
	for(int i=len1-1;i>=0;i--)
	{
		if(t1[i]!=t2[i])
		{
			r=i;
			break;
		}
	}
	if(l==-1)
	{
		cout<<0<<endl;
		return;
	}
	for(int i=l;i<=r;i++)
	{
		chayi1+=t1[i];
		chayi2+=t2[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(cha1[i]==chayi1&&cha2[i]==chayi2)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int L=-1,R=-1,Len=s1.size();
		for(int j=0;j<Len;j++)
		{
			if(s1[j]!=s2[j])
			{
				L=j;
				break;
			}
		}
		for(int j=Len-1;j>=0;j--)
		{
			if(s1[j]!=s2[j])
			{
				R=j;
				break;
			}
		}
		cha1[i]="",cha2[i]="";
		for(int j=L;j<=R;j++)
		{
			cha1[i]+=s1[j];
			cha2[i]+=s2[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		solve();
	}
	return 0;
}
/*
4 2
xabcx xadex
abfcd abecd
bcc dec
aaa bba
xabcx xadex
aaaa bbbb
*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int l,mid,r;
};
vector<Node> tt;
bool check(string s1,string s2,string s3)
{
	int l=s1.size();
	for(int i=0;i<l;i++)
	{
		if(!((s1[i]=='$'&&s1[i]==s3[i])||s1[i]==s2[i]))
			return false;
	}
	return true;
}
int fid(string s1,string s2)
{
	int l=s1.size();
	int i,j;
	for(i=0,j=s2.size()-1;j<l;i++,j++)
	{
		bool flag=true;
		int x;
		for(int k=i;k<=j;k++)
		{
			if(s2[k-i]!=s1[k])
			{
				flag=false;
				break;
			}
		}
		if(flag)
			return i;
	}
	return -1;
}
void repla(string &s,int p,string s1)
{
	for(int i=p;i<p+s1.size();i++)
	{
		s[i]=s1[i-p];
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2;
	int n,q,i,j;
	cin>>n>>q;
	if(n<=100&&q<=100)
	{
		string t1[105],t2[105];
		for(i=1;i<=n;i++)
			cin>>t1[i]>>t2[i];
		while(q--)
		{
			cin>>s1>>s2;
			int l1=s1.size(),l2=s2.size();
			int ans=0;
			if(l1!=l2)
			{
				cout<<0<<'\n';
				continue;
			}
			for(i=1;i<=n;i++)
			{
				string ab=s1;
				while(fid(ab,t1[i])!=-1)
				{
					string sbc=ab;
					repla(ab,fid(ab,t1[i]),t2[i]);
					if(check(ab,s2,s1))
					{
						ans++;
						break;
					}
					else
					{
						ab=sbc;
						ab[fid(ab,t1[i])]='$';
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size(),ll1,rr1,ll2,rr2,xx1,xx2,dl,dr,dm;
		for(j=0;j<l1;j++)
		{
			if(s1[j]=='b')
			{
				ll1=j;
				rr1=l1-j-1;
				xx1=j;
			}
		}
		for(j=0;j<l2;j++)
		{
			if(s2[j]=='b')
			{
				ll2=j;
				rr2=l2-j-1;
				xx2=j;
			}
		}
		if(xx1<xx2)
			dl=ll1,dr=rr2,dm=xx2-xx1;
		else
			dl=ll2,dr=rr1,dm=xx2-xx1;
		tt.push_back({dl,dm,dr});
	}
	int pp=tt.size();
	for(i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		int ans=0;
		int l1=s1.size(),l2=s2.size();
		if(l1!=l2)
		{
			cout<<0<<'\n';
			continue;
		}
		int ll1,rr1,ll2,rr2,xx1,xx2,dl,dm,dr;
		for(j=0;j<l1;j++)
		{
			if(s1[j]=='b')
			{
				ll1=j;
				rr1=l1-j-1;
				xx1=j;
			}
		}
		for(j=0;j<l2;j++)
		{
			if(s2[j]=='b')
			{
				ll2=j;
				rr2=l2-j-1;
				xx2=j;
			}
		}
		if(xx1<xx2)
			dl=ll1,dr=rr2,dm=xx2-xx1;
		else
			dl=ll2,dr=rr1,dm=xx2-xx1;
		for(j=0;j<pp;j++)
		{
			if(dm==tt[j].mid&&dl>=tt[j].l&&dr>=tt[j].r)
				ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}//Meow.Bad.
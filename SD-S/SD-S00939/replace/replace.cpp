#include <bits/stdc++.h>
using namespace std;
//const int bas=1331;
//const int mod=1e9+7;
string s[200005][2];
struct nod
{
	int x,p1,pp,id;
}a[200005];
int cmp(nod a,nod b)
{
	return a.x<b.x;
}
int b[500005],c[500005],fl,tt[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0];
		for(int j=0;j<s[i][0].length();j++)	
		{
			if(s[i][0][j]!='a'&&s[i][0][j]!='b')
			{
				fl=1;
				break;
			}
		}
		int p=s[i][0].find('b');
		cin>>s[i][1];
		for(int j=0;j<s[i][1].length();j++)	
		{
			if(s[i][1][j]!='a'&&s[i][1][j]!='b')
			{
				fl=1;
				break;
			}
		}
		int p2=s[i][1].find('b');
		a[i].x=p2-p,a[i].p1=p,a[i].pp=p2,a[i].id=i;
		tt[i]=p2-p;
	}
	sort(tt+1,tt+n+1);
	sort(a+1,a+n+1,cmp);
	while(q--)
	{
		int ans=0;
		string u,v;
		cin>>u>>v;
//		for(int )
		if(u.length()!=v.length())
		{
			cout<<0<<"\n";
			continue;
		}
		int uu=u.find('b'),vv=v.find('b'),k=vv-uu;
		if(n<=100&&q<=100)
		{
				for(int i=1;i<=n;i++)
			{
	//			for(i)
				int p=0,q=u.find(s[i][0],p);
				while(q!=-1)
				{
					string ww=u;
					int rr=s[i][0].length();
					for(int j=q;j<=q+rr-1;j++)
						ww[j]=s[i][1][j-q];
	//					cout<<ww<<"\n";
					if(ww==v)
						ans++;
	//				for(int i=1)
					p=q+rr;
					q=u.find(s[i][0],p);
				}
			}
			cout<<ans<<"\n";
		}
		int d=lower_bound(tt+1,tt+n+1,k)-tt;
		if(tt[d]!=k)
		{
			cout<<0<<"\n";
			continue;
		}
		while(tt[d]==k)
		{
			if(a[d].p1<=uu&&s[a[d].id][0].length()-a[d].p1+1<=u.length()-uu+1)
				ans++;
			d++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	string x,y;
	bool sm;
	string st,md,mdd,ed;
}a[200010];
bool cmp(node xx,node yy)
{
	if(xx.md !=yy.md )return xx.md <yy.md;
	if(xx.mdd!=yy.mdd)return xx.mdd<yy.mdd;
	if(xx.ed !=yy.ed )return xx.ed <yy.ed;
	return xx.st<yy.st;
}
int find1(string str,int l,int r) // left md
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid].md<str)l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int find11(string str,int l,int r) // right md
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid].md<=str)l=mid+1;
		else r=mid-1;
	}
	return l-2;
}
int find2(string str,int l,int r) // left mdd
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid].mdd<str)l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int find22(string str,int l,int r) // right mdd
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid].mdd<=str)l=mid+1;
		else r=mid-1;
	}
	return l-2;
}
int find3(string st,string ed,int l,int r) // left ed
{
	int s=0;
	for(int i=l;i<=r;i++)
		if(a[i].st==st.substr(0,a[i].st.size())
		 &&a[i].ed==ed.substr(0,a[i].ed.size()))s++;
	return s;
}
bool pd(int l,int r)
{
	return (l<=r&&l>0);
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		if(a[i].x==a[i].y)a[i].sm=1;
		else
		{
			int len=a[i].x.size();
			int l=0,r=len-1;
			for(int j=0;j<len;j++)
				if(a[i].x[j]!=a[i].y[j]){l=j;break;}
			for(int j=len-1;j>=0;j--)
				if(a[i].x[j]!=a[i].y[j]){r=j;break;}//cout<<'!'<<endl;
			a[i].st =a[i].x.substr(0,l);//cout<<'!'<<endl;
			reverse(a[i].st.begin(),a[i].st.end());//cout<<'!'<<endl;
			a[i].md =a[i].x.substr(l,r-l+1);//cout<<'!'<<endl;
			a[i].mdd=a[i].y.substr(l,r-l+1);//cout<<'!'<<endl;
			a[i].ed =a[i].x.substr(r+1,len-r);//cout<<'!'<<endl;
		}
	}
	sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++)
//			cout<<"* "<<i<<" : "<<a[i].st<<' '<<a[i].md<<'('<<a[i].mdd<<')'<<' '<<a[i].ed<<'\n';
	while(k--)
	{
		string x,y;
		int s=0;
		cin>>x>>y;
		if(x==y)
		{
			for(int i=1;i<=n;i++)
				if(x.find(a[i].x)&&a[i].sm)s++;
			cout<<s<<'\n';
			continue;
		}
		int len=x.size();
		int l=0,r=len-1;
		for(int i=0;i<len;i++)
			if(x[i]!=y[i]){l=i;break;}
		for(int i=len-1;i>=0;i--)
			if(x[i]!=y[i]){r=i;break;}
		string st= x.substr(0,l);reverse(st.begin(),st.end());
		string now=x.substr(l,r-l+1);
		string str=y.substr(l,r-l+1);
		string ed =x.substr(r+1,len-r);
		//cout<<"* "<<st<<' '<<now<<'('<<str<<')'<<' '<<ed<<'\n';
		int ll=find1 (now,1,n+1);
		int rr=find11(now,1,n+1);				//	cout<<"**      "<<ll<<' '<<rr<<'\n';
		if(!pd(ll,rr)){cout<<"0\n";continue;}
		int lll=find2 (str,ll,rr);
		int rrr=find22(str,ll,rr);			//	cout<<"***     "<<lll<<' '<<rrr<<'\n';
		if(!pd(lll,rrr)){cout<<"0\n";continue;}
		int ans=find3(st,ed,lll,rrr);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

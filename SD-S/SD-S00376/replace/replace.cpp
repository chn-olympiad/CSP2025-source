#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define fori(x) for(ll i=1;i<=(x);i++)
#define forj(x) for(ll j=1;j<=(x);j++)
struct node
{
	string s1,s2;
};
string getss(string sl1,ll fr,ll ba)
{
	string a;
	ll tt=0;
	while(tt<ba-fr)	a[tt]=sl1[fr+tt],tt++;
	return a;
}

bool cms(string sl1,string sl2,ll len)
{
	while(len>=0)	{if(sl1[len-1]!=sl2[len-1])	return 0;len--;}
	return 1;
}

void print(string sl)
{
	fori(sl.length()+1)
	{
		printf("%c",sl[i-1]);
	}
	printf("\n");
	return;
}

node t[200007],s[200007];
map<string,string> k;
string use;
ll n,q,cnt;
int main()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	fori(n)	cin>>s[i].s1>>s[i].s2,k[s[i].s1]=s[i].s2;
	ll rq=q;
	while(q--)	{
	cin>>t[rq-q].s1>>t[rq-q].s2;
	cnt=0;
	for(ll i=0;i<t[rq-q].s1.length();i++)
	{
		for(ll j=t[rq-q].s1.length()-1;j>=i;j--)
		{ 
		string kk=getss(t[rq-q].s1,i,j);
		if(k[kk].length())
		{
		
		string a1=k[kk];
		string a2=getss(t[rq-q].s2,i,j);
		//cout<<kk[1]<<",,,"<<a1[1]<<"..."<<a2[1]<<";;;"<<endl;
			if(  cms(  a1,a2  ,  j-i  )  )
				cnt++;}
		}
	}
	printf("%lld\n",cnt);
	}
	
	/*
	string a="abcdefg";
	string b=a;
	print(b);
	if(cms(a,b,7))	cout<<1;*/
	return 0;
}
//果然文化课比OI简单的多 0PTS

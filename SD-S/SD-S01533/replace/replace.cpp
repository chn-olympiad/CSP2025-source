#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define M 2500010

int T1[M][26];int tot1;map<int,int>mp1;vector<int>q1[N];int mm1;
int T2[M][26];int tot2;map<int,int>mp2;vector<int>q2[N];int mm2;
set<int>sss;
queue<int>qqq;
void Find1(string s)
{
	int now=0;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		char str=s[i];
		if(T1[now][str-'a']==0)
		{
			return;
		}
		else
		{
			now=T1[now][str-'a'];
		}
	}
	int mm=mp1[now];
	int mmn=q1[mm].size();
	for(int i=0;i<q1[mm].size();i++)
	{
//		printf("!Find`1  ",q1[mm][i]);
		sss.insert(q1[mm][i]);
	}
}
void Find2(string s)
{
	int now=0;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		char str=s[i];
		if(T2[now][str-'a']==0)
		{
			return;
		}
		else
		{
			now=T2[now][str-'a'];
		}
	}
	int mm=mp2[now];
	int mmn=q2[mm].size();
	for(int i=0;i<q2[mm].size();i++)
	{
		if(sss.count(q2[mm][i])==1)
		{
			qqq.push(q2[mm][i]);
		}
	}
}


void Add1(string s,int ii)
{
	int now=0;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		char str=s[i];
		if(T1[now][str-'a']==0)
		{
			T1[now][str-'a']=++tot1;
			now=tot1;
		}
		else
		{
			now=T1[now][str-'a'];
		}
//		cout<<now<<endl;
	}
	if(mp1[now]==0)
	{
//		cout<<"whyyyy?";
		mp1[now]=++mm1;
	}
	q1[mp1[now]].push_back(ii);
//	cout<<mm1<<" "<<ii<<" "<<s<<"-----------"<<endl;
}
void Add2(string s,int ii)
{
	int now=0;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		char str=s[i];
		if(T2[now][str-'a']==0)
		{
			T2[now][str-'a']=++tot2;
			now=tot2;
		}
		else
		{
			now=T2[now][str-'a'];
		}
	}
	if(mp2[now]==0)
	{
		mp2[now]=++mm2;
	}
	q2[mp2[now]].push_back(ii);
}

int sl[N];
int sr[N];
int ql,qr;
string cha(string s1,string s2,int flag,int flag2)
{
	int l=0,r=-1;
	int n=s1.size();
	for(int i=0;i<n;i++)
	{
		if(s1[i]!=s2[i])
		{
			l=i;
			break;
		}
	}
	for(int j=n-1;j>=l;j--)
	{
		if(s1[j]!=s2[j])
		{
			r=j;
			break;
		}
	}
	string ans;
	for(int i=l;i<=r;i++)
	{
		if(flag==0)
		{
			ans+=s1[i];
		}
		else
		{
			ans+=s2[i];
		}
	}
	if(flag2>0)
	{
		sl[flag2]=l;
		sr[flag2]=r;
	}
	else
	{
		ql=l;
		qr=r;
	}
//	cout<<s1<<" "<<s2<<l<<" "<<r<<" "<<" "<<n<<ans<<endl;
	return ans;
	
}
bool check(string s1,string s2,int lq,int rq,int ls,int rs)
{
	int m=s2.size();
	int j=lq-1;
//	cout<<"weishenmebuxianyan  "<<s1<<"   "<<s2<<endl;
//	printf("%d %d %d %d  %d\n\n",lq,rq,ls,rs,m);
	for(int i=ls-1;i>=0;i--)
	{
		if(s1[j]!=s2[i])
		{
//			printf("What can i say");
			return false;
		}
		j--;
	}
	j=rq+1;
	for(int i=rs+1;i<m;i++)
	{
		if(s1[j]!=s2[i])
		{
//			printf("What can i sa!@#y");
			return false;
		}
		j++;
	}
	return true;
}
int n,q;
string s1[N];
string s2[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		Add1(cha(s1[i],s2[i],0,i),i);
		Add2(cha(s1[i],s2[i],1,i),i);
//		cout<<endl;
	}
//	for(int i=0;i<=20;i++)
//	{
//		for(int j=0;j<26;j++)
//		{
//			printf("%d ",T1[i][j]);
//		}
//		printf("\n");
//	}
	for(int i=1;i<=q;i++)
	{
		string w1,w2;
		cin>>w1>>w2;
		int m=w1.size();
		string del1=cha(w1,w2,0,0);
		string del2=cha(w1,w2,1,0);
		Find1(del1);
		Find2(del2);
		sss.clear();
		int ans=0;
		while(!qqq.empty())
		{
			int qq=qqq.front();
			qqq.pop();
			if(s1[qq].size()>m)
			{
//				cout<<"??";
				continue;
			}
//			printf("!@#!@#!@$!@#$@!%d  ",qq);
			if(check(w1,s1[qq],ql,qr,sl[qq],sr[qq])&&check(w2,s2[qq],ql,qr,sl[qq],sr[qq]))
			{
				ans++;
			}
		}
//		printf("\n");
		cout<<ans<<endl;
	}
	return 0;
}

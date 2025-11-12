#include<bits/stdc++.h>
using namespace std;
int n,T;
bool mp[5000010];
string s1[200010],s2[200010];
string t1,t2;
struct point{
	int l1,r1,l2,r2;
}spe[200010];
bool check(string a1,string a2,string b1,string b2)
{
	int la=a1.size();
	int lb=b1.size();
	if(la>lb)	return 0;
	string cnt1="";
	for(int i=0;i<la;i++)
		cnt1+=b1[i];
	memset(mp,0,sizeof(mp));
	if(a1==cnt1)	mp[la-1]=1;
	for(int i=la;i<lb;i++)
	{
		cnt1.erase(cnt1.begin());
		cnt1+=b1[i];
		if(a1==cnt1)	mp[i]=1;
	}
	string cnt2="";
	for(int i=0;i<la;i++)
		cnt2+=b2[i];
	if(a2==cnt2&&mp[la-1]==1)	return 1;
	for(int i=la;i<lb;i++)
	{
		cnt2.erase(cnt2.begin());
		cnt2+=b2[i];
		if(a2==cnt2&&mp[i]==1)	return 1;
	}
	return 0;
}
int special(string x)
{
	int cnt=0,pos=0,lx=x.size();
	for(int i=0;i<lx;i++)
	{
		if(x[i]=='a')		continue;
		else if(x[i]=='b')	cnt++,pos=i;
		else				return -1;
	}
	if(cnt==1)	return pos;
	else		return -1;
}
bool check1(string x,int l,int r,int id)
{
	int la=spe[id].l1,ra=spe[id].r1,lb=spe[id].l2,rb=spe[id].r2;
	int len=r-l;
	if(!(ra==lb&&la==rb))	return 0;
	if(la>l||ra>n-r-1||lb>)			return 
}
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&T);
	bool sp=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int pp=special(s1[i]),qq=special(s2[i]);
		int len=strlen(s1[i]);
		if(pp==-1||qq==-1)	sp=0;
		else sc[i]={pp-1,len-pp-1,qq-1,len-qq-1};
	}
	while(T--)
	{
		cin>>t1>>t2;
		int l=t1.size();
		int l2=t2.size();
		if(l!=l2)
		{
			printf("0\n");
			continue;
		}
		int p=0,q=l-1,ans=0;
		while(t1[p]==t2[p])	p++;
		while(t1[q]==t2[q])	q--;
		string x1="",x2="";
		for(int i=p;i<=q;i++)	x1+=t1[i];
		for(int i=p;i<=q;i++)	x2+=t2[i];
		for(int i=1;i<=n;i++)
		{
			bool f1=0,f2=0;
			if(sp==0)
			{
				f1=check(x1,x2,s1[i],s2[i]);
				f2=check(s1[i],s2[i],t1,t2);
			}
			else
			{
				f1=check1(x1,p,q,i);
				f2=check1(x1,p,q,i);
			}
			if(f1&&f2)	ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
//O(qL1)
//只可以替换一次
//要求:包含被替换字符串在内字符串与上面字符串的其中之一匹配 
//看出该字串在所有字串中的定位,并向左进行 
//定义差异部分为x1,x2
//则在x1是s1的子串,x2是s2的子串且位置一一对应 
//s1是t1的子串,s2是t2的子串且位置一一对应 
//才能进行一次修改
//aabaa
//aaaba
//ab ba

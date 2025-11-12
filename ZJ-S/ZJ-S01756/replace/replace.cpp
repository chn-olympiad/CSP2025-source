#include<bits/stdc++.h>
using namespace std;
const int MAX=5e6+20,N=2e5+10;
int n,q;int ans;
struct pfnode
{
	int b1,b2,len;
}pfstr[N],pfstr1;
void pfwork()
{
	for(int i=1;i<=n;i++)
		if(pfstr1.len>=pfstr[i].len)
			if(pfstr1.b1>=pfstr[i].b1&&pfstr1.b2>=pfstr[i].b2)
				if((pfstr1.len-pfstr1.b1)>=(pfstr[i].len-pfstr[i].b1))
					if((pfstr1.len-pfstr1.b2)>=(pfstr[i].len-pfstr[i].b2))
						if((pfstr1.b1-pfstr1.b2)==(pfstr[i].b1-pfstr[i].b2))
							ans++;
}
void pfoutput()
{
	cout<<ans<<endl;
}
void init2()
{
	for(int i=1;i<=n;i++)
	{
		string str1,str2;
		cin>>str1>>str2;
		pfstr[i].b1=str1.find('b');
		pfstr[i].b2=str2.find('b');
		pfstr[i].len=str1.length();
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		if(t1.length()!=t2.length())
		{
			cout<<0<<endl;
			return;
		}
		pfstr1.b1=t1.find('b');pfstr1.len=t1.length();pfstr1.b2=t2.find('b');
		pfwork();
		pfoutput();
	}
}
struct node
{
	int hash_num1,hash_num2;
	int len;
}str[N];
int CBL_hash(string str)
{
	long long hash=0;
	for(int i=0;i<str.length();i++)
	{
		hash=(hash*10+(str[i]-'a'))%102030405060708;
	}
	return hash;
}
//int hash_list[N][3]={0},len_list[N][3];
string t1,t2;
bool test(int i,int s,int l)
{
	if(t1.substr(0,s)==t2.substr(0,s))
		if(CBL_hash(t1.substr(s,l))==str[i].hash_num1)
			if(CBL_hash(t2.substr(s,l))==str[i].hash_num2)
				if(t1.substr(s+l)==t2.substr(s+l))
					return 1;
	return 0;
}
void work()
{
	cin>>t1>>t2;
	if(t1.length()!=t2.length())
		return;
	int L,l;
	L=t1.length();
	for(int i=1;i<=n;i++)
	{
		l=str[i].len;
		for(int j=0;j+l<=L;j++)
			if(test(i,j,l))
				ans++;
	}
}
void output()
{
	printf("%d\n",ans);
}
bool cmp(node a,node b)
{
	return a.len<b.len;
}
void init()
{
	scanf("%d %d",&n,&q);
	if(n>=10000)
	{
		init2();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		string str1,str2;
		cin>>str1>>str2;
		str[i].hash_num1=CBL_hash(str1);
		str[i].hash_num2=CBL_hash(str2);
		str[i].len=str1.length();
	}
	sort(str+1,str+n+1,cmp);
	for(int i=1;i<=q;i++)
	{
		ans=0;
		work();
		output();
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

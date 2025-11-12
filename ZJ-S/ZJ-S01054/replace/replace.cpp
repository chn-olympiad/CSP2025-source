#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=2e5+10;

string s1[N],s2[N];
int ss[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		string str1,str2;
		cin>>str1>>str2;
		int ns,ne;
		for(int j=0;j<=str1.size()-1;j++)
			if(str1[j]!=str2[j])
			{
				ns=j;
				break;
			}
		for(int j=str1.size()-1;j>=0;j--)
			if(str1[j]!=str2[j])
			{
				ne=j;
				break;
			}
		string st1="",st2="";
		for(int j=ns;j<=ne;j++)
			st1=st1+str1[j],st2=st2+str2[j];
		int f=1;
		for(int j=1;j<=num&&f;j++)
			if(st1==s1[j]&&st2==s2[j])
				ss[j]++,f=0;
		if(f) s1[++num]=st1,s2[num]=st2,ss[num]++;
	}
	while(q--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int ans=0;
		int ns,ne;
		for(int i=0;i<=str1.size()-1;i++)
			if(str1[i]!=str2[i])
			{
				ns=i;
				break;
			}
		for(int i=str1.size()-1;i>=0;i--)
			if(str1[i]!=str2[i])
			{
				ne=i;
				break;
			}
		string sstr1="",sstr2="";
		for(int i=ns;i<=ne;i++)
			sstr1=sstr1+str1[i],sstr2=sstr2+str2[i];
		for(int i=1;i<=num;i++)
			if(s1[i]==sstr1&&s2[i]==sstr2) ans+=ss[i];
		cout<<ans<<endl;
	}
	return 0;
}

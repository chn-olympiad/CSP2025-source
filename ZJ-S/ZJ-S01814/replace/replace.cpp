#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;
int n,T,ans,flag;
string s1,s2,s3,s5;
map<string,int>mp;
map<string,string>ch;
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();T=read();
	for (int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		ch[s1]=s2;
		ch[s2]=s1;
		mp[s1]++;
		mp[s2]++;
	}
	while (T--)
	{
		cin>>s1>>s2;
		ans=0;
		for (int i=0;i<s1.size();i++)
			for (int j=i;j<s1.size();j++)
			{
				s3="";
				for (int k=i;k<=j;k++)	s3+=ch[s1][k];
				flag=1;s5="";
				for (int k=i;k<=j;k++)	s5+=s2[k];
				if (s3==s5 && mp.find(s3)!=mp.end())ans+=mp[s3];
			}
		cout<<ans<<"\n";
	}
	return 0;
}

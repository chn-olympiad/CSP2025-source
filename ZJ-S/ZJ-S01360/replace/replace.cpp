#include<bits/stdc++.h>
using namespace std;
const int slen=2e5+10;
map<string,string>m;
string s1[slen],s2[slen];
int main()
{
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
  	cin>>s1[i]>>s2[i];
  	m[s1[i]]=s2[i];
  }
  for(int k=1;k<=q;k++)
  {
  	string s3,s4;
  	long long ans=0;
  	cin>>s3>>s4;
    for(int i=0;i<s3.size();i++)
  	{
  	  string s="",ss="",c1="",c2="",cc1="",cc2="";
  	  for(int j=0;j<i;j++)c1=c1+s3[j];
  	  for(int j=0;j<i;j++)c2=c2+s4[j];
  	  for(int j=i;j<s3.size();j++)
  	  {
  	  	cc1="";cc2="";
  	  	for(int o=j+1;o<s3.size();o++)cc1=cc1+s3[o];
  	  	for(int o=j+1;o<s3.size();o++)cc2=cc2+s4[o];
  	  	s=s+s3[j];
  	  	ss=ss+s4[j];
  	  	if(m.find(s)!=m.end()) 
  	  	{
  	  	  string sss=m[s];
  	  	  if(sss==ss&&c1==c2&&cc2==cc1)ans++;
		}
		
	  }
	}
	cout<<ans<<endl;
	ans=0;
  }
  return 0;
}
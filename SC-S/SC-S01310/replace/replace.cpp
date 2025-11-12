#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,q;
string s1[N],s2[N];
int ps1[N],ps2[N];
int main()
{
  freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i];
		cin>>s2[i];
		for(int j=0;j<s1[i].size();++j) if(s1[i][j]=='b') {ps1[i]=j;break;}
		for(int j=0;j<s2[i].size();++j) if(s2[i][j]=='b') {ps2[i]=j;break;}
	}
	for(int i=1;i<=q;++i)
	{
		string t1,t2;
		int pt1=0,pt2=0,tot1=0,tot2=0;
		cin>>t1;
		cin>>t2;
		for(int j=0;j<t1.size();++j) if(t1[j]=='b') {pt1=j;break;}
		for(int j=0;j<t2.size();++j) if(t2[j]=='b') {pt2=j;break;}
		for(int j=1;j<=n;++j) if(ps1[j]!=pt1&&ps1[j]!=ps2[j]) tot1++;
		cout<<tot1<<endl;
	}
    return 0;
} 

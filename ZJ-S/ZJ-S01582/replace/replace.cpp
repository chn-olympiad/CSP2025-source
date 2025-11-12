#include<bits/stdc++.h>
using namespace std;
int n,q,idx;
struct R{
	int l,r,ju;
}s[1000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		int k,j;
		cin>>s1>>s2;
		for(k=0;k<s1.size();k++)if(s1[k]=='b')break;
		for(j=0;j<s1.size();j++)if(s2[j]=='b')break;
		s[i].l=k;
		s[i].r=s1.size()-k;
		s[i].ju=j-k;
	}
	for(int i=1;i<=q;i++)
	{
		int cnt=0;
		string start,end;
		cin>>start>>end;
		int j=0,k=0;
		for(k=0;k<start.size();k++)if(start[k]=='b')break;
		for(j=0;j<end.size();j++)if(end[j]=='b')break;
		int u=j-k;
		for(int j=1;j<=n;j++)
		{
			if(s[j].l<=k && s[j].r<=start.size()-k && s[j].ju==u)
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

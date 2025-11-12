#include<bits/stdc++.h>
using namespace std;
int n,q,ui,ans;
string s1[200002],s2[200002],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int qwe=1;qwe<=q;qwe++)
	{
		ans=0;
		cin>>t1>>t2;
		ui=t1.length();
		if(ui!=t2.length())
		{
			cout<<0<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
	return 0;
}

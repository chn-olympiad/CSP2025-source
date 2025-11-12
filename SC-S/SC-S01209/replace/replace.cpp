#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::freopen;
using std::string;
using std::vector;
vector<string> find(string a,string b)
{
	string ans0,ans1;
	int sub=0;
	while(a[sub]==b[sub]) sub++;
	while(a[sub]!=b[sub]&&sub<a.size()){
		ans0+=a[sub];
		ans1+=b[sub];
		sub++;
	}
	return {ans0,ans1};
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<vector<string>> s(n,vector<string>(2));
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
		s[i]=find(s[i][0],s[i][1]);
	}
	vector<string> t(2);
	int ans=0;
	for(int i=0;i<q;i++){
		ans=0;
		cin>>t[0]>>t[1];
		t=find(t[0],t[1]);
		for(int j=0;j<n;j++)
			if(t[0]==s[j][0]&&t[1]==s[j][1])
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}
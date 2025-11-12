#include<bits/stdc++.h>
using namespace std;
int n,q,a[200005],b[200005];
string s1[200005],s2[200005],c1[200005],c2[200005],t1,t2,w1,w2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int l=0,r=s1[i].size()-1;
		while(s1[i][l]==s2[i][l])	l++;
		while(s1[i][r]==s2[i][r])	r--;
		for(int j=l;j<=r;j++)	c1[i].push_back(s1[i][j]),c2[i].push_back(s2[i][j]);
		a[i]=l;
		b[i]=r;
	}
	while(q--){
		w1=w2="";
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l=0,r=t1.size()-1;
		while(t1[l]==t2[l])	l++;
		while(t1[r]==t2[r])	r--;
		for(int i=l;i<=r;i++)	w1.push_back(t1[i]),w2.push_back(t2[i]);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c1[i]==w1&&c2[i]==w2&&a[i]<=l&&s1[i].size()-b[i]<=t1.size()-r){
				bool fl=1;
				for(int j=a[i]-1;j>=0;j--)	if(s1[i][j]!=t1[l+j-a[i]])	fl=0;
				for(int j=b[i]+1;j<s1[i].size();j++)	if(s1[i][j]!=t1[r+j-b[i]])	fl=0;
				if(fl)	cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

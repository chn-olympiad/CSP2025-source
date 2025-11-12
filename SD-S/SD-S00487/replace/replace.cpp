#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1[200005],t2[200005];
int Replace[200005];
string subs(string s,int begin,int len){
	string st="";
	for(int i=begin;i<begin+len;i++)st+=s[i];
	return st;
}
int found(string s,string t){
	for(int i=0;i<=t.size()-s.size();i++){
		if(subs(t,i,s.size())==s)return i;
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			if(found(s1[j],t1[i])==found(s2[j],t2[i])&&found(s1[j],t1[i])>=0)Replace[i]++;
		}
		cout<<Replace[i]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,q;
map<string,string>a;
string s,s1;
int dfs(string p,string o){
	string op="",po="";
	int cnt=0;
	int kt=-1,jw=0;
	for(int i=0;i<p.size();i++){
		if(p[i]!=o[i]&&kt==-1){
			kt=i;
			jw=i;
		}
		if(p[i]!=o[i]&&kt!=-1){
			jw=i;
		}
	}
	for(int i=0;i<p.size()-1;i++){
		for(int j=i+1;j<p.size();j++){
			if(kt<i||j<jw)continue;
			for(int k=i;k<=j;k++){
				op+=p[k];
				po+=o[k];
			}
			if(a[op]==po)cnt++;
			op="",po="";
		}
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>s1;
		a[s]=s1;
	}
	for(int i=1;i<=q;i++){
		cin>>s>>s1;
		cout<<dfs(s,s1)<<"\n";
	}
	return 0;
}


#include<bits/stdc++.h>

const int N=5e6+3;

using namespace std;

bool check(string s1,string s2,string t1,string t2){
	for(int i=0;i<t1.size();++i){
		string tmp=t1;
		for(int j=0;j<s1.size();++j){
			int p=i+j;
			if(t1[p]!=s1[j]) goto nxt;
		}
		for(int j=0;j<s1.size();++j) tmp[i+j]=s2[j];
		if(tmp==t2) return true;
		nxt:;
	}
	return false;
}

int n,q;
string s1[N],s2[N];
string t1,t2;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;++i){
		int res=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;++j) 
			if(check(s1[j],s2[j],t1,t2))
				res++;
		cout<<res<<'\n';
	}
	return 0;
}
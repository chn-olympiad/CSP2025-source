#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,mod=998244353;
#define ll long long
int qread(){
	int ret=0;
	char c;
	do{
		c=getchar();
	}while(!isdigit(c));
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while(isdigit(c));
	return ret;
}
int n,q;
vector<pair<int,int>> s[N*2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=qread();q=qread();
	for(int k=1;k<=n;k++){
		string s1,s2;cin>>s1>>s2;
		int pos1,pos2;
		int l=s1.size();
		for(int i=0;i<l;i++){
			if(s1[i]=='b')pos1=i;
			if(s2[i]=='b')pos2=i;
		}
		int x=pos2-pos1;
		if(x>=0)s[x].push_back(make_pair(pos1,l-pos1));
		else s[x+n].push_back(make_pair(pos1,1-pos1));
	}
	for(int k=1;k<=q;k++){
		string t1,t2;cin>>t1>>t2;
		int pos1,pos2;
		int l=t1.size();
		for(int i=0;i<l;i++){
			if(t1[i]=='b')pos1=i;
			if(t2[i]=='b')pos2=i;
		}
		int x=pos2-pos1;
		int ans=0;
		if(x>=0){
			for(auto v:s[x]){
				if(pos1>=v.first&&l-pos1>=v.second)ans++;
			}
		}else{
			for(auto v:s[x+n]){
				if(pos1>=v.first&&l-pos1>=v.second)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
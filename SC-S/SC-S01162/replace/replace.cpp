#include<bits/stdc++.h>
using namespace std;
#define rep(i,k,n) for(int i=(k);i<=(n);i++)
#define srep(i,n,k) for(int i=(n);i>=(k);--i)
const int N=1e3+5;
int fail[2][N][2001];
int n,qu;
string s1[N],s2[N],t1,t2;
int tmp;
void build(int now,string s,int i){
	int j=0,k=-1;
	fail[now][i][0]=-1;
	while(j<(int)s.size()){
		if(k==-1||s[j]==s[k]) fail[now][i][++j]=++k;
		else k=fail[now][i][k];
	}
}
vector<pair<int,int>>a1,a2;
void fin1(string s){
	rep(q,1,n){
		if((int)s1[q].size()<tmp ) continue;
		int i=0,j=0;
		while(i<(int)s.size()){
			if(j==-1||s[i]==s1[q][j]) i++,j++;
			else j=fail[0][q][j];
			if(j==(int)s1[q].size()) a1.push_back({i,q});
		}
	}
}
void fin2(string s){
	rep(q,1,n){
		if((int)s1[q].size()<tmp ) continue;
		int i=0,j=0;
		while(i<(int)s.size()){
			if(j==-1||s[i]==s2[q][j]) i++,j++;
			else j=fail[0][q][j];
			if(j==(int)s2[q].size()) a2.push_back({i,q});
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>qu;
	rep(i,1,n) cin>>s1[i]>>s2[i],build(0,s1[i],i),build(1,s2[i],i);
	rep(i,1,qu){
		a1.clear();a2.clear();
		cin>>t1>>t2;
		tmp=0;
		rep(i,0,(int)t1.size()-1)
			tmp+=t1[i]!=t2[i];
		fin1(t1);fin2(t2);
		sort(a1.begin(),a1.end());
		sort(a2.begin(),a2.end());
		int ans=0;
		for(auto v1:a1)for(auto v2:a2){
			if(v1.first==v2.first&&v1.second==v2.second&&(int)s1[v1.second].size()>=tmp) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
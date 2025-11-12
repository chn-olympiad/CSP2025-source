#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
map<string,string> m;
string str(int l,int r,string s){
	string w="";
	if(l>=0&&r<s.size()){
		for(int i=l;i<=r;i++){
			w+=s[i];
		}
	}
	return w;
}
void dfs(int l,int r,string s,string s2){
	string e;
	if(m[str(l,r,s)]!=""){
		e=str(0,l-1,s)+m[str(l,r,s)]+str(r+1,s.size()-1,s);
		if(e==s2){
			cnt++;
		}
	}
	
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		m[s1]=s2;
	}
	while(q>0){
		cnt=0;
		string qustion1,qustion2;
		cin>>qustion1>>qustion2;
		int L=0,R=qustion1.size()-1;
		for(int i=0;i+L<=n;i++){
			for(int j=0;R-j>=0;j++)
				dfs(i,j,qustion1,qustion2);
		}
		
		cout<<cnt<<"\n";
		q--;
	}
	
	return 0;
}


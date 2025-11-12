#include<bits/stdc++.h>
#include<string>
using namespace std;
//n<2*1e5
//q<2*1e5
//L1,L2<5*1e6
struct sss{
	string s1;
	string s2;
}s[100005];
int n,q;
string t1,t2;
string ss;
void dfs(int k,int time){
	if(k==t1.size()){
		if(ss==t2){
			cout<<time<<endl;
		}
		return ;
	}
	if(ss[k]!=t2[k]){
		for(int i=1;i<=n;i++){
			if(s[i].s2==t2.substr(k,k+s[i].s2.size()-1)){
				string tmp=ss;
				ss=ss.substr(0,k-1)+s[i].s2+ss.substr(k+s[i].s1.size(),ss.size()-1);
				dfs(k+s[i].s1.size(),time+1);
				ss=tmp;
			}
		}
	}
	
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i].s1>>s[i].s2;
	while(q--){
		cin>>t1>>t2;
		dfs(0,0);
		
		
	}
	
	
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx
xadex
aaaa bbbb
*/

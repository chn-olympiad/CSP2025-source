#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+12;
int n,q,r = 0;
struct node{
	string s,t;
}k[N];
int vis[5000005];
int find(string kk,string yy){
	
	for(int i=1;i<=kk.size()-yy.size()+1;i++){
		int r = 0;
		for(int j=i;j<=yy.size();j++){
			if(kk[j] != yy[j]) r = 1;
		}
		if(r == 0) return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>k[i].s>>k[i].t;
	}
	while(q--){
		r = 0;
		string s1,s2,s5,s6;
		cin>>s1>>s2;
		int o = 0,bg,en;
		for(int i=0;i<s1.size();i++){
			if(s1[i] != s2[i]){
				if(o == 0) bg = i;
				o=1;
				vis[i] = 1;
				en = i;
			}
		}
		for(int i=bg;i<=en;i++){
			s5 +=s1[i];
			s6 +=s2[i]; 
		}
		for(int i=1;i<=n;i++){
			if(find(k[i].s,s5) == 1 && find(k[i].t,s6) == 1) r++;
		}
		for(int i=1;i<=n;i++){
			if(k[i].s == s1 && k[i].t == s2) r++;
		}
		cout<<r<<endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int s=0;char c=getchar();bool f=0;
	while(c<'0'||c>'9'){f=(f||(c=='-'));c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c^48);c=getchar();}
	if(f) s=-s;
	return s;
}


int n,m;
string s1[10005],s2[10005];
string p1,p2;

string subsubstring(string old,int st,int sizee){
	string str="";
	for(int i=0;i<sizee;i++){
		str+=old[st+i];
	}
	return str;
}
string substringsub(string old,int st,int ed){
	string str="";
	for(int i=st;i<=ed;i++){
		str+=old[i];
	}
	return str;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(m--){
		int ans=0;
		cin>>p1>>p2;
		for(int i=1;i<=n;i++){
			if(p1.size()<s1[i].size()) continue;
			for(int j=0;j<=p1.size()-s1[i].size();j++){
				if(subsubstring(p1,j,s1[i].size())==s1[i]){
					if(subsubstring(p1,0,j)+s2[i]+
					substringsub(p1,s1[i].size()+j,p1.size()-1)==p2){
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

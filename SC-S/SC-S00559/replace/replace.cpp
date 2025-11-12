#include<bits/stdc++.h>
using namespace std;
int n,q,l,r;
string s[200005][2],x,y,z;
map<string,vector<int>>mp;
long long ans;
void read(string &x){
	x="";
	char c=getchar();
	while(!isalpha(c))c=getchar();
	while(isalpha(c)){
		x+=c;
		c=getchar();
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		read(s[i][0]),read(s[i][1]);
		mp[s[i][0]].emplace_back(i);
	}
	while(q--){
		read(x),read(y);
		if(mp.find(x)==mp.end()||x.size()!=y.size()){
			printf("0\n");
		}else{
			l=r=-1;
			ans=0;
			for(int i=0;i<x.size();i++){
				if(x[i]!=y[i]){
					l=i;
					break;
				}
			}
			for(int i=x.size()-1;i>=0;i--){
				if(x[i]!=y[i]){
					r=i;
					break;
				}
			}
			
			for(int i=0;i<=l;i++){
				for(int j=r;j<x.size();j++){
					
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+30;
const int M=5e6+10;
const int INF=0x3f3f3f3f;
int n,q;
char c1[M],c2[M];
string s1[N],s2[N];
map<string,vector<int> > mp;
void solve(){
	int ans=0;
	scanf("%s",c1);
	scanf("%s",c2);
	int len1=strlen(c1);
	int len2=strlen(c2);
	if(len1!=len2){
		printf("0\n");
		return;
	}
	int x=0,yy=len1-1;
	while(c1[x]==c2[x]) x++;
	while(c1[yy]==c2[yy]) yy--;
	string ss1="",ss2="";
	for(int i=x;i<=yy;i++) ss1+=c1[i],ss2+=c2[i];
	for(int i=x;i>=0;i--){
		string s="",ss="";
		for(int k=i;k<x;k++) s+=c1[k],ss+=c2[k];
		s+=ss1,ss+=ss2;
		for(int j=yy+1;j<=len1;j++){
			if(mp[s].empty()){
				s+=c1[j],ss+=c2[j];
				continue;
			}
			for(auto v:mp[s]){
				if(s2[v]==ss){
					ans++;
				}
			}
			s+=c1[j],ss+=c2[j];
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",c1);
		scanf("%s",c2);
		s1[i]=c1,s2[i]=c2; 
		mp[s1[i]].push_back(i);
	}
	while(q--){
		solve();
	}
	return 0;
}

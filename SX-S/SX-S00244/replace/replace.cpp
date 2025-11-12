#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
map<pair<string,string>,int> mp;
void solve1(){
	for(int i=1;i<=n;i++) mp[{s[i][1],s[i][2]}]++;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int l=1e9,r=0;
		int len=t1.size();
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				if(l>=1e8) l=i;
				r=i;
			}
		}
		int ans=0;
		for(int i=0;i<=l;i++){
			string tt="",tt2="";
			for(int j=i;j<len;j++){
				tt+=t1[j];
				tt2+=t2[j];
				if(j>=r) ans+=mp[{tt,tt2}];
//				cout<<tt<<'\n'<<tt2<<'\n'<<ans<<'\n';
			}
		}
		printf("%d\n",ans);
	}
}
void solve2(){
	string t1,t2;
	cin>>t1>>t2;
	if(t1.size()!=t2.size()){
		printf("0\n");
		return;
	}
	int id1,id2;
	int len=t1.size();
	for(int i=0;i<len;i++) if(t1[i]=='b') id1=i;
	for(int i=0;i<len;i++) if(t2[i]=='b') id2=i;
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=s[i][1].size();
		int i1,i2;
		for(int j=0;j<l;j++){
			if(s[i][1][j]=='b') i1=j;
			if(s[i][2][j]=='b') i2=j;
		}
		if(i1-i2!=id1-id2) continue;
		if(i1>id1) continue;
		if(l-i1>len-id1) continue;
		ans++;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	int sum=0;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2],sum+=s[i][1].size()+s[i][2].size();
	if(n<=100&&q<=100&&sum<=500) solve1();
	else solve2();
	return 0;
}

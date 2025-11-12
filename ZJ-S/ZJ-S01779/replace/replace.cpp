#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
string ss[N],sz[N];
map<string,map<string,int> >mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>ss[i]>>sz[i];
		mp[ss[i]][sz[i]]++;
	}
	while(m--){
		ans=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			printf("0\n");
			continue ;
		}int f=-1,e=-1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]==s2[i])continue ;
			if(f==-1)f=e=i;
			else e=i;
		}
		for(int i=0;i<=f;i++){
			for(int j=e;j<s1.size();j++){
				ans+=mp[s1.substr(i,j-i+1)][s2.substr(i,j-i+1)];
			}
		}printf("%d\n",ans);
	}
	return 0;
}

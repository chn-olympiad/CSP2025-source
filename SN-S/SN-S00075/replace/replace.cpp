#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
int ps1[N],ps2[N],pt1[N],pt2[N];
map<pair<int,int>,vector<int> >mp;
map<pair<int,int>,int >mn;
int main(){//部分分 启动！！！       18:00 性质B完结 20分 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=n;i++){
		int len=s1[i].size();
		for(int j=0;j<len;j++){
			if(s1[i][j]=='b') ps1[i]=j;
			if(s2[i][j]=='b') ps2[i]=j;
		}
//			printf("%d %d ",ps1[i],ps2[i]);
		mp[make_pair(ps1[i],ps2[i])].push_back(len);
		mn[make_pair(ps1[i],ps2[i])]++;
//			printf("%d\n",mp[make_pair(ps1[i],ps2[i])]);
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		if(t1[i].size()!=t2[i].size()){
			printf("0\n");
			continue;
		}
		int len=t1[i].size();
		for(int j=0;j<len;j++){
			if(t1[i][j]=='b') pt1[i]=j;
			if(t2[i][j]=='b') pt2[i]=j;
		}
		for(int j=0;j<=pt1[i];j++){
			for(int k=0;k<mn[make_pair(j,j-pt1[i]+pt2[i])];k++){
				if(0<=j-pt1[i]+pt2[i]&&j-pt1[i]+pt2[i]<len&&pt1[i]+mp[make_pair(j,j-pt1[i]+pt2[i])][k]-j<len){
					ans++;
//						printf("%d %d %d\n",j,j-pt1[i]+pt2[i],mp[make_pair(j,j-pt1[i]+pt2[i])]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0; 
}

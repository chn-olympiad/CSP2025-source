#include<bits/stdc++.h>
using namespace std;
struct node{
	int s[3],k;
}a[100005];
int t,n;
bool cmp0(int c,int d){
	int sc0=a[c].s[0],sc1=a[c].s[1],sc2=a[c].s[2],sd0=a[d].s[0],sd1=a[d].s[1],sd2=a[d].s[2];
	return sc0-max(sc1,sc2)<sd0-max(sd1,sd2);
}
bool cmp1(int c,int d){
	int sc0=a[c].s[0],sc1=a[c].s[1],sc2=a[c].s[2],sd0=a[d].s[0],sd1=a[d].s[1],sd2=a[d].s[2];
	return sc1-max(sc0,sc2)<sd1-max(sd0,sd2);
}
bool cmp2(int c,int d){
	int sc0=a[c].s[0],sc1=a[c].s[1],sc2=a[c].s[2],sd0=a[d].s[0],sd1=a[d].s[1],sd2=a[d].s[2];
	return sc2-max(sc0,sc1)<sd2-max(sd0,sd1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int m=n/2,f=0;
		vector<int>g[3];
		for(int i=0;i<n;++i){
			cin>>a[i].s[0]>>a[i].s[1]>>a[i].s[2];
			if(a[i].s[0]>=a[i].s[1]&&a[i].s[0]>=a[i].s[2]) a[i].k=0;
			else if(a[i].s[1]>=a[i].s[0]&&a[i].s[1]>=a[i].s[2]) a[i].k=1;
			else if(a[i].s[2]>=a[i].s[0]&&a[i].s[2]>=a[i].s[1]) a[i].k=2;
			g[a[i].k].push_back(i);
			f+=a[i].s[a[i].k];
		}
		int s0=g[0].size(),s1=g[1].size(),s2=g[2].size();
		if(s0<=m && s1<=m && s2<=m) cout<<f<<endl;
		else{
			if(s0>m){
				sort(g[0].begin(),g[0].end(),cmp0);
				for(int i=0;i<s0-m;++i) f-=a[g[0][i]].s[0]-max(a[g[0][i]].s[1],a[g[0][i]].s[2]);
			}
			else if(s1>m){
				sort(g[1].begin(),g[1].end(),cmp1);
				for(int i=0;i<s1-m;++i) f-=a[g[1][i]].s[1]-max(a[g[1][i]].s[0],a[g[1][i]].s[2]);
			}
			else if(s2>m){
				sort(g[2].begin(),g[2].end(),cmp2);
				for(int i=0;i<s2-m;++i) f-=a[g[2][i]].s[2]-max(a[g[2][i]].s[0],a[g[2][i]].s[1]);
			}
			cout<<f<<endl;
		}
	}
	return 0;
}
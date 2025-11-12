//niuziru SN-S00452 xiangaoxindiyizhongxue
#include<bits/stdc++.h>
using namespace std;
#define il inline
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+3,M=5e6,K=1e7+13;
int n,q,mx;
string s[N][3],g[N][3];
int p[N][2],l[N],dis[N];
vector<int> h[K];
il void deal(int i){
	l[i]=s[i][0].size();
	s[i][0]=" "+s[i][0],s[i][1]=" "+s[i][1];
	for(int j=1;j<=l[i];j++){
		mx=max(mx,s[i][0][j]-'a');
		if(s[i][0][j]=='b'){
			p[i][0]=j;
			break;
		}
	}
	for(int j=1;j<=l[i];j++){
		mx=max(mx,s[i][0][j]-'a');
		if(s[i][1][j]=='b'){
			p[i][1]=j;
			break;
		}
	}
	dis[i]=p[i][0]-p[i][1];
	h[dis[i]+M].push_back(p[i][0]);
}
int p1,p2,len;
il void pre(){
	for(int i=0;i<=M*2;i++) sort(h[i].begin(),h[i].end());
}
il void find(string s1,string s2){
	len=s1.size();
	s1=" "+s1,s2=" "+s2;
	for(int j=1;j<=len;j++){
		if(s1[j]=='b'){
			p1=j;
			break;
		}
	}
	for(int j=1;j<=len;j++){
		if(s2[j]=='b'){
			p2=j;
			break;
		}
	}
	int tp=p1-p2+M;
	int l1=0,r1=h[tp].size()-1,mid;
	if(r1==-1) puts("0");
	else{
		while(l1<r1){
			mid=(l1+r1+1)>>1;
			if(h[tp][mid]>p1) r1=mid-1;
			else l1=mid;
		}
		if(h[tp][l1]<p1) puts("0");
		else printf("%d\n",l1+1);		
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],deal(i);
	for(int i=1;i<=q;i++) cin>>g[i][0]>>g[i][1];
	if(mx<=1){
		pre();
		for(int i=1;i<=q;i++){
			find(g[i][0],g[i][1]);
		}
	}
	else{
		for(int i=1;i<=q;i++) puts("0");
	}
	return 0;
}

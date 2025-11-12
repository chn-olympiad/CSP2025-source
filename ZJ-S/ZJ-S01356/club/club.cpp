#include "bits/stdc++.h"

using namespace std;
typedef long long LL;
const int MAXN=100020;
int n;
struct nodes {
	int INT[4];
	nodes() {
		memset(INT,0,sizeof(INT));
	}
	bool friend operator < (nodes a,nodes b) {
		return a.INT[0]>b.INT[0];
	}
	void clears() {
		memset(INT,0,sizeof(INT));
	}
} a[MAXN];
int fenpei[4];
LL ans=0;
int t;
void init() {
	memset(fenpei,0,sizeof(fenpei));
	for(int i=0; i<MAXN; i++) {
		a[i].clears();
	}
	n=0;
	ans=0;
}
void dfs(){
	for(int i=1;i<=n;i++){
		vector<int> maxx;
		for(int j=1; j<=3; j++) {
			if(a[i].INT[j]==a[i].INT[0]) {
				maxx.push_back(j);
			}
		}
		for(int j=1; j<=3; j++) {
			if(a[i].INT[j]!=a[i].INT[0]) {
				maxx.push_back(j);
			}
		}
		for(int j:maxx) {
			fenpei[j]++;
			ans+=a[i].INT[j];
			break;
		}
	}
}
struct newnodes{
	int INT[4],maxp;
	newnodes() {
		memset(INT,0,sizeof(INT));maxp=0;
	}
	bool friend operator < (newnodes a,newnodes b) {
		int maxxx=0,mbxxx=0;
		for(int i=1;i<=3;i++){
			if(i!=a.maxp){
				maxxx=max(maxxx,a.INT[i]);
			}
			if(i!=b.maxp){
				mbxxx=max(mbxxx,b.INT[i]);
			}
		}
		int asunshi=a.INT[a.maxp]-maxxx,bsunshi=b.INT[b.maxp]-mbxxx;
		return asunshi<bsunshi;
	}
	int sunshis(){
		int maxxx=0;
		for(int i=1;i<=3;i++){
			if(i!=maxp){
				maxxx=max(maxxx,INT[i]);
			}
		}
		return INT[maxp]-maxxx;
	}
	void clears() {
		memset(INT,0,sizeof(INT));
	}
};
void qianrang(){
	int weigui=0;
	for(int i=1;i<=3;i++){
		if(fenpei[i]>n/2){
			weigui=i;
		}
	}
	if(!weigui){
		return;
	}
	vector<newnodes> vsss;
	for(int i=1;i<=n;i++){
		if(a[i].INT[0]==a[i].INT[weigui]){
			newnodes tmp;
			memcpy(tmp.INT,a[i].INT,sizeof(tmp.INT));
			tmp.maxp=weigui;
			vsss.push_back(tmp);
		}
	}
	int len=vsss.size(),l=0;
	sort(vsss.begin(),vsss.end());
	while(len-l>n/2){
		newnodes tmp=vsss[l];
		ans-=tmp.sunshis();
		l++;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin>>t;
	for(int curci=1; curci<=t; curci++) {
		init();
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].INT[1]>>a[i].INT[2]>>a[i].INT[3];
			a[i].INT[0]=max(a[i].INT[0],a[i].INT[1]);
			a[i].INT[0]=max(a[i].INT[0],a[i].INT[2]);
			a[i].INT[0]=max(a[i].INT[0],a[i].INT[3]);
		}
		dfs();
		qianrang();
		cout<<ans<<'\n';
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull mod=233333;
const int maxn=2e5+10,maxm=5e6+10,maxk=2500010;
int tree[maxk],dfn[maxk],dpr[maxk],id;
int headp[maxk],nxtp[maxn],posp[maxn],idxp;
int headq[maxk],nxtq[maxn],posq[maxn],qryid[maxn],ans[maxn],idxq;
int sonl[maxk][26],sonr[maxk][26],idxl,idxr;
ull valp[maxn],valq[maxn],book[maxn<<1];
vector<int>vecp[maxn<<1],vecq[maxn<<1];
int prep[maxn],sucp[maxn],preq[maxn],sucq[maxn];
char pp[maxk],sp[maxk],pq[maxk],sq[maxk],str1[maxm],str2[maxm];
bool visp[maxn],visq[maxn];
inline void upd(int p,int k,int n){
	while(p<=n) tree[p]+=k,p+=(p&-p);
}
inline int qry(int p){
	int res=0;
	while(p>=1) res+=tree[p],p-=(p&-p);
	return res;
}
inline void dfsr(int u){
	dfn[u]=++id;
	for(int i=0;i<26;i++){
		if(sonr[u][i]) dfsr(sonr[u][i]);
	}
	dpr[u]=id;
}
inline void dfsl(int u){
	for(int i=headp[u];i;i=nxtp[i]){
		int v=posp[i];
		upd(dfn[v],1,idxr);
		upd(dpr[v]+1,-1,idxr);
	}
	for(int i=headq[u];i;i=nxtq[i]){
		int v=posq[i];
		ans[qryid[i]]=qry(dfn[v]);
	}
	for(int i=0;i<26;i++){
		if(sonl[u][i]) dfsl(sonl[u][i]);
	}
	for(int i=headp[u];i;i=nxtp[i]){
		int v=posp[i];
		upd(dfn[v],-1,idxr);
		upd(dpr[v]+1,1,idxr);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,q;cin>>n>>q;
	int tot=0;
	for(int i=1;i<=n;i++){
		cin>>(str1+1)>>(str2+1);
		int m=strlen(str1+1);
		int pl=1,pr=strlen(str2+1);
		while(pl<=pr and str1[pl]==str2[pl]) pl++;
		while(pl<=pr and str1[pr]==str2[pr]) pr--;
		if(pl>pr) continue;
		prep[i]=prep[i-1]+pl-1;
		for(int j=1;j<pl;j++){
			pp[prep[i]-j+1]=str1[j];
		}
		sucp[i]=sucp[i-1]+m-pr;
		for(int j=m;j>pr;j--){
			sp[sucp[i]-m+j]=str1[j];
		}
		for(int j=pl;j<=pr;j++){
			valp[i]=valp[i]*mod+(int)str1[j];
			valp[i]=valp[i]*mod+(int)str2[j];
		}
		book[++tot]=valp[i];
		visp[i]=1;
	}
	for(int i=1;i<=q;i++){
		cin>>(str1+1)>>(str2+1);
		int m=strlen(str1+1);
		int pl=1,pr=strlen(str2+1);
		if(pr!=m){
			ans[i]=0;
			continue;
		}
		while(pl<=pr and str1[pl]==str2[pl]) pl++;
		while(pl<=pr and str1[pr]==str2[pr]) pr--;
		preq[i]=preq[i-1]+pl-1;
		for(int j=1;j<pl;j++){
			pq[preq[i]-j+1]=str1[j];
		}
		sucq[i]=sucq[i-1]+m-pr;
		for(int j=m;j>pr;j--){
			sq[sucq[i]-m+j]=str1[j];
		}
		for(int j=pl;j<=pr;j++){
			valq[i]=valq[i]*mod+(int)str1[j];
			valq[i]=valq[i]*mod+(int)str2[j];
		}
		book[++tot]=valq[i];
		visq[i]=1;
	}
	sort(book+1,book+1+tot);
	tot=unique(book+1,book+1+tot)-book-1;
	for(int i=1;i<=n;i++){
		if(visp[i]){
			valp[i]=lower_bound(book+1,book+1+tot,valp[i])-book;
			vecp[valp[i]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		if(visq[i]){
			valq[i]=lower_bound(book+1,book+1+tot,valq[i])-book;
			vecq[valq[i]].push_back(i);
		}
	}
	for(int i=1;i<=tot;i++){
//		cout<<"--------------------------\n";
		idxl=1,idxr=1,idxp=0,idxq=0,id=0;
		for(int j:vecp[i]){
//			cout<<"    str  "<<j<<"\n";
			int pl=1;
			for(int k=prep[j-1]+1;k<=prep[j];k++){
				int cur=pp[k]-'a';
				if(sonl[pl][cur]) pl=sonl[pl][cur];
				else pl=sonl[pl][cur]=++idxl;
			}
			int pr=1;
			for(int k=sucp[j-1]+1;k<=sucp[j];k++){
				int cur=sp[k]-'a';
				if(sonr[pr][cur]) pr=sonr[pr][cur];
				else pr=sonr[pr][cur]=++idxr;
			}
//			cout<<pl<<" "<<pr<<"\n";
			posp[++idxp]=pr;
			nxtp[idxp]=headp[pl];
			headp[pl]=idxp;
		}
		for(int j:vecq[i]){
//			cout<<"    qry  "<<j<<"\n";
			int pl=1;
			for(int k=preq[j-1]+1;k<=preq[j];k++){
				int cur=pq[k]-'a';
				if(sonl[pl][cur]) pl=sonl[pl][cur];
//				else pl=sonl[pl][cur]=++idxl;
				else break;
			}
			int pr=1;
			for(int k=sucq[j-1]+1;k<=sucq[j];k++){
				int cur=sq[k]-'a';
				if(sonr[pr][cur]) pr=sonr[pr][cur];
//				else pr=sonr[pr][cur]=++idxr;
				else break;
			}
//			cout<<pl<<" "<<pr<<"\n";
			posq[++idxq]=pr;
			qryid[idxq]=j;
			nxtq[idxq]=headq[pl];
			headq[pl]=idxq;
		}
		dfsr(1);
		dfsl(1);
		for(int j=1;j<=idxl;j++){
			headp[j]=headq[j]=0;
			for(int k=0;k<26;k++){
//				if(sonl[j][k]) cout<<"edgel   "<<char('a'+k)<<" "<<j<<" "<<sonl[j][k]<<"\n";
				sonl[j][k]=0;
			}
		}
		for(int j=1;j<=idxr;j++){
//			cout<<"dfn of "<<j<<" is "<<dfn[j]<<"  "<<dpr[j]<<"\n";
			for(int k=0;k<26;k++){
//				if(sonr[j][k]) cout<<"edger   "<<char('a'+k)<<" "<<j<<" "<<sonr[j][k]<<"\n";
				sonr[j][k]=0;
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
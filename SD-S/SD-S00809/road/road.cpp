//#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long n,m,k,o,ct,ci,fu,fv;
char cc;
long long rd() {
	long long x=0;
	while(cc<'0'||cc>'9')
		cc=getchar();
	do {
		x*=10;
		cc^='0';
		x+=cc;
		cc=getchar();
	} while(cc>='0'&&cc<='9');
	return x;
}
inline void rd(long long&x) {
	x=0;
	while(cc<'0'||cc>'9')
		cc=getchar();
	do {
		x*=10;
		cc^='0';
		x+=cc;
		cc=getchar();
	} while(cc>='0'&&cc<='9');
	return ;
}
inline void rd(int&x) {
	x=0;
	while(cc<'0'||cc>'9')
		cc=getchar();
	while(cc>='0'&&cc<='9') {
		x*=10;
		cc^='0';
		x+=cc;
		cc=getchar();
	};
	return;
}
vector<int>b;
struct d {
	int u,v;
	long long w;
};
bool cm(d q,d p) {
	return q.w<p.w;
}
int fd(int x) {
	if(b[x]==x)return x;
	return b[x]=fd(b[x]);
}
void kl(vector<d>&e,int ci) {
	ct=ci;
	for(int i=0; i<n+k; ++i)b[i]=i;
	for(auto&i:e) {
		fu=fd(i.u);
		fv=fd(i.v);
		if(fu!=fv) {
			b[fu]=fv;
			ct+=i.w;
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	rd(n);
	rd(m);
	rd(k);
	b.resize(m+k);
	vector<d>e(m);
	vector<long long>c(k);
	vector<vector<d>>f(k,vector<d>(n));
	for(auto&i:e) {
		rd(i.u);
		rd(i.v);
		rd(i.w);
		--i.u;
		--i.v;
	}
	for(int j=0; j<k; ++j) {
		rd(c[j]);
		for(int i=0; i<n; ++i) {
			f[j][i].u=j;
			f[j][i].u+=n;
			f[j][i].v=i;
			rd(f[j][i].w);
		}
	}
	sort(e.begin(),e.end(),cm);

	vector<d>ee=e;

	ci=0;
	for(int i=0; i<n+k; ++i)b[i]=i;
	for(auto&i:e) {
		fu=fd(i.u);
		fv=fd(i.v);
		if(fu!=fv) {
			b[fu]=fv;
			ct+=i.w;
		}
	}
	o=ct;
	//ee[i][j]=ee[i-1][j-1]_j
	//		cv[i][j]=cv[i-1][j-1]+c[j] cv[i][j-1]
	//p[i][j]=min kl ee[i-1][j-1]_fj  ff[i][j-1]
	//jjj->ii
	//
	
//	vector<d>ee(k+1);
//	vector<vector<vector<d>>>er(k+1,vector<vector<d>>(k+1));
//	vector<vector<long long>>ff(k+1,vector<long long>(k+1));
//	vector<vector<long long>>cv(k+1,vector<long long>(k+1));
//
//	for(auto&i:er[0])i=e;
//	for(int g=1; g<=k; ++g) {
//		
//		er[g][g]=er[g-1][g-1];
//		
//		for(auto&i:f[g-1]) {
//			er[g][g].push_back(i);
//		}
//		
//		sort(er[g][g].begin(),er[g][g].end(),cm);
//		
//		kl(er[g][g],cv[g-1][g-1]+c[g-1]);
//		
//		ff[g][g]=ct;
//		cv[g][g]=cv[g-1][g-1]+c[g-1];
//		for(int j=g+1; j<=k; ++j) {
//		
//			er[g][j]=er[g-1][j-1];
//		
//			for(auto&i:f[j-1]) {
//				er[g][j].push_back(i);
//			}
//			sort(er[g][j].begin(),er[g][j].end(),cm);
//			kl(er[g][j],cv[g-1][j-1]+c[j-1]);
//			ff[g][j]=ff[g][j-1];
//			cv[g][j]=cv[g][j-1];
//			if(ct<ff[g][j]) {
//				ff[g][j]=ct;
//				cv[g][j]=cv[g-1][j-1]+c[j-1];
//			}
//		
//		}
//		
//		er[g-1].clear();
//		
//	}
//	for(int g=1; g<=k; ++g) {
//	for(int j=1; j<=k; ++j) {
//		o=min(o,ff[g][k]);
//		//fprintf(stderr,"%lld ",ff[g][k]);
//	}//fputs("\n",stderr);
//}
	for(int j=0;j<k;++j){
		ct=ci;
		ct+=c[j];
		e=ee;
		for(auto&i:f[j]){
			e.push_back(i);
		}
		sort(e.begin(),e.end(),cm);
		for(int i=0;i<n+k;++i)b[i]=i;
		for(auto&i:e){
			fu=fd(i.u);
			fv=fd(i.v);
			if(fu!=fv){
				b[fu]=fv;
				ct+=i.w;
			}
		}
		if(ct<o){
			o=ct;
			ee=e;
			ci+=c[j];
		}
	}
	printf("%lld",o);
	return 0;
}

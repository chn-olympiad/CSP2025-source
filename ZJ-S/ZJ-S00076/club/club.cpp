#include <bits/stdc++.h>
#define int long long
using namespace std;
int Readd(){
	int s = 0;char c = getchar();int f = 1;
	for(; c < '0' || c > '9'; c = getchar())(c == '-') && (f = -1);
	for(; c >= '0' && c <= '9'; c = getchar())s = (s << 1) + (s << 3) + (c ^ 48);
	return s * f;
}
struct Dati{
	int x,y;
}k[5];
bool cmp(Dati xx,Dati yy){
	return xx.y > yy.y;
}
struct dat{
	int id[5],c[5];
}a[100010];
struct Datt{
	int id,v,p;
	bool operator < (const Datt x)const{
		return v > x.v;
	}
};
priority_queue<Datt> qa,qb,qc;
int ans;
void Initt(){
	while(!qa.empty())qa.pop();
	while(!qb.empty())qb.pop();
	while(!qc.empty())qc.pop();
}
inline void Modi(Datt x){
	ans -= x.v;
	int nid = x.p + 1,nv,y = x.id;
	if(nid == 4 || nid == 3)nv = 1e9;
	if(nid == 2)nv = a[y].c[2] - a[y].c[3];
	if(a[y].id[nid] == 1)qa.push({y,nv,nid});
	if(a[y].id[nid] == 2)qb.push({y,nv,nid});
	if(a[y].id[nid] == 3)qc.push({y,nv,nid});
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t = Readd();
	while(t--){
		Initt();
		int n;
		ans = 0;
		n = Readd();
		for(int i = 1; i <= n; i++){
			k[1].y = Readd(),k[2].y = Readd(),k[3].y = Readd();
			k[1].x = 1,k[2].x = 2,k[3].x = 3;
			sort(k + 1,k + 4,cmp);
			for(int j = 1; j <= 3; j++){
				a[i].id[j] = k[j].x,a[i].c[j] = k[j].y;
			}
			if(a[i].id[1] == 1)qa.push({i,a[i].c[1] - a[i].c[2],1});
			if(a[i].id[1] == 2)qb.push({i,a[i].c[1] - a[i].c[2],1});
			if(a[i].id[1] == 3)qc.push({i,a[i].c[1] - a[i].c[2],1});
			ans += a[i].c[1];
		}
		while(qa.size() > n / 2 || qb.size() > n / 2 || qc.size() > n / 2){
			if(qa.size() > n / 2){
				Datt x = qa.top();
				qa.pop();
				Modi(x);
			}
			if(qb.size() > n / 2){
				Datt x = qb.top();
				qb.pop();
				Modi(x);
			}
			if(qc.size() > n / 2){
				Datt x = qc.top();
				qc.pop();
				Modi(x);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
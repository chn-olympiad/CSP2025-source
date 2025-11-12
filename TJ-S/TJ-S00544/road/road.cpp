#include <bits/stdc++.h> 
using namespace std;
struct road{
	long long u,v,w;
} r[1000005];
struct vl{
	long long c,a[10005];
} s[11],c[10001];
long long n,m,k,cnt;
bool drive(long long a,long long b,long long d){
	if(a == b) return 1;
	for(int i =1;i<=n;i++){
		if(c[a].a[i] and i != d){
			if(drive(i,b,a)) return 1;
		}
	}
	return 0;
}
bool cmp(road a,road b){
	return a.w<b.w;
}
bool cp(vl a,vl b){
	return a.c < b.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i =1;i<=m;i++){
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for(int j =1;j<=k;j++){
		cin >> s[j].c;
		for(int i =1;i<=n;i++){
			cin >> s[j].a[i];
		}
	}
	sort(r+1,r+n+1,cmp);
	sort(s+1,s+k+1,cp);
	for(int i =1;i<=n;i++){
		if((drive(r[i].u,r[i].v,0)== 0) or (drive(r[i].v,r[i].u,0)== 0)){
			c[r[i].u].a[r[i].v]= 1;
			c[r[i].v].a[r[i].u]= 1;
			cnt += r[i].w;
		}
	}
	cout << cnt;
	return 0;
}

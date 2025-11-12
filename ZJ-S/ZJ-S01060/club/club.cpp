#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+100;
int n,sj,sum[10],cnt[10];

struct node{
	int a,b,c,mx,zj,mxw,zjw;
	//mxw,zjw \in 1,2,3
} p[maxn+100]; 

bool cmp(node A,node B){
	return A.mx - A.zj < B.mx - B.zj;
}

inline void Main(){
	cnt[1] = cnt[2] = cnt[3] = 0;
	sum[1] = sum[2] = sum[3] = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> p[i].a >> p[i].b>> p[i].c;
		p[i].mx = max(p[i].a,max(p[i].b,p[i].c));
		if(p[i].mx == p[i].a){
			p[i].mxw = 1;
			p[i].zj = max(p[i].b,p[i].c);
			if(p[i].zj == p[i].b) p[i].zjw = 2;
			else p[i].zjw = 3;
		}else if(p[i].mx == p[i].b){
			p[i].mxw = 2;
			p[i].zj = max(p[i].a,p[i].c);
			if(p[i].zj == p[i].a) p[i].zjw = 1;
			else p[i].zjw = 3;
		}else{
			p[i].mxw = 3;
			p[i].zj = max(p[i].b,p[i].a);
			if(p[i].zj == p[i].b) p[i].zjw = 2;
			else p[i].zjw = 1;
		}
	}
	sort(p+1,p+1+n,cmp);
	int sj = n / 2;
	for(int i = 1;i <= n;i++){ //先全部放到最大 
		sum[p[i].mxw] += p[i].mx;
		cnt[p[i].mxw]++;
	}
	if(cnt[1] <= sj && cnt[2] <= sj && cnt[3] <= sj){
		cout << sum[1]+sum[2]+sum[3] << '\n';
		return;
	}
	else{
		int cw,m = max(cnt[1],max(cnt[2],cnt[3]));
		if(m == cnt[1]) cw = 1;
		else if(m == cnt[2]) cw = 2;
		else cw = 3;
		for(int i = 1;i <= n;i++){
			if(p[i].mxw == cw){
				sum[cw] -= p[i].mx;
				sum[p[i].zjw] += p[i].zj;
				cnt[cw]--;
			}
			if(cnt[cw] <= sj) break;
		}
		cout << sum[1]+sum[2]+sum[3] << '\n';
		return;
	}
}

//Yoimiya blees me!
//Miyeon blees me!
//20min!

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) Main();
	return 0;
}

//如果这个是黄题，那么我的OI生涯从来没有场切过橙题！ 

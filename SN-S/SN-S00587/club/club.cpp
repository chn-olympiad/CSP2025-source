#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 7;
int n;
struct ns{
	int id;
	int w;
};
struct stu{
	ns x[4];
	int score[4];
	int now_w;
	int only_id;
}a[N];
vector<stu> cnt[4];
bool cmp(ns a,ns b){
	return a.w > b.w;
}
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i].x[1].w>> a[i].x[2].w>> a[i].x[3].w;
		a[i].x[1].id =1;a[i].x[2].id =2;a[i].x[3].id =3;
		a[i].score[1] = a[i].x[1].w; a[i].score[2] = a[i].x[2].w; a[i].score[3] = a[i].x[3].w;
		int chosed = -1,maxn = -1;
		if(maxn < a[i].x[1].w)chosed = 1,maxn = a[i].x[1].w;
		if(maxn < a[i].x[2].w)chosed = 2,maxn = a[i].x[2].w;
		if(maxn < a[i].x[3].w)chosed = 3,maxn = a[i].x[3].w;
		a[i].now_w = maxn;
		a[i].only_id = i;
		sort(a[i].x + 1,a[i].x + 3 +1,cmp);
		cnt[chosed].push_back(a[i]);
	}
	int ans = 0;
	bool sunh = false;
	for(int i = 1;i<=3;i++){
		if(cnt[i].size() > n/2){//q
			sunh = true;
			int cost = 0;
			for(int j = 0;j<cnt[i].size();j++){
				stu stud=cnt[i][j];
				for(int k = 1;k<=3;k++){
					int bestto = cnt[i][j].x[k].id;
					if(bestto == i) continue;
					if(cnt[bestto].size() +1 <= n/2){
						if(cost < cost - stud.now_w + stud.x[bestto].w){
							cost = cost - stud.now_w + stud.x[bestto].w;
							vector<stu> moe;moe.clear();
							for(int fuc = 0;fuc < cnt[i].size();fuc++){
								if(cnt[i][fuc].only_id == stud.only_id) continue;
								moe.push_back(cnt[i][fuc]);
							}
							cnt[i] = moe;
							cnt[bestto].push_back(stud);
							break;
						}
					}
				}
			}
			ans+=cost;
		}
	}
	if(sunh == false){
		for(int i = 1;i<=3;i++){
			for(int j = 0;j<cnt[i].size();j++){
				ans+=cnt[i][j].score[i];
			}
		}
		cout << ans << endl;
	}else{
		cout <<ans << endl; 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin >> T;
	while(T--){
		memset(cnt,0,sizeof cnt);
		solve();
	}
	return 0;
}


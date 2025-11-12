#include <bits/stdc++.h>
#define _all(i,a,b) for(int i = a; i <= b; i ++)
#define __all(i,a,b) for(int i = a; i < b; i ++)
#define r_all(i,a,b) for(int i = a; i >= b; i--)
#define vt vector<int>
#define vl vector<LL>
#define v2 vector<vt>
using namespace std;
using LL = long long ;
struct mat{
	int w,cnt[4] = {0,0,0,0},u; // 当前这一步的满意度，部门使用情况
	bool operator<(const mat & other) const{return w < other.w;}
};
void work(){
	int n ,ans = 0;
	cin>>n;
	vt c(n+5);
	v2 a(n+5,vt(4));
	int maxx = 0;
	_all(i,1,n) cin>>a[i][1]>>a[i][2]>>a[i][3],c[i] = a[i][1],maxx = max({maxx,a[i][2],a[i][3]});
	if(maxx == 0){ //特殊A
		sort(c.begin()+1,c.begin()+n+1,greater<>());
		_all(i,1,n/2) ans += c[i];
		printf("%d\n",ans);
		return ;
	}
	queue<mat> q;
	_all(i,1,3) {
		mat mad;
		mad.w = a[1][i], mad.cnt[i] = 1, mad.u = i;
		q.push(mad);
	}
	for(int i = 2;i<=n ; i ++){
		auto tp = q;
		while(!tp.empty()){
			auto t = tp.front();tp.pop();
			_all(j,1,3){ //从u->j
				auto k = t;
				if(t.cnt[j] < n/2){ //这个部门可以用
					k.cnt[j] ++,k.w += a[i][j],k.u = j;
					if(i == n){
						ans = max(ans, k.w);
					}
				//	printf("%d %d %d %d\n",i,j,k.w,t.u);
					q.push(k);
				}
			}
		}
	}
	printf("%d\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t --) work();
	
	
	return 0;
}
/*

*/
//T1 - 部分分:策略不完善 
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int MAXN = 2e5;
int n,t,p[3],ans;//p:3个部门的人数
int full;

struct data{
	int d[3];
};

vector<data> a;

int maxp(){
	if(p[0]>(n>>1)) return 0;
	if(p[1]>(n>>1)) return 1;
	if(p[2]>(n>>1)) return 2;
	return -1;
}

int maxd(data d){//代表满意度
	return max(max(d.d[0],d.d[1]),d.d[2]);
}

int maxd(data d,int i){//非i部门代表满意度
	if(!i) return max(d.d[1],d.d[2]);
	if(i&1) return max(d.d[0],d.d[2]);
	return max(d.d[0],d.d[1]);
}

void init(){
	memset(p,0,sizeof(p));
	a.clear();
	ans = 0;
	full = -1;
};

bool compp(data self,data other){
	if(full==-1)
	return maxd(self)>=maxd(other);
	return maxd(self,full)>=maxd(other,full);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		init();
		cin >> n;
		for(int i=0;i<n;i++){
			int j1,j2,j3;
			cin >> j1 >> j2 >> j3;
			a.push_back({j1,j2,j3});
		}
		sort(a.begin(),a.begin()+n,compp);
		int i = 0;
		while(maxp()==-1&&i<n){
			data d = a[i];
			if(d.d[0]>=max(d.d[1],d.d[2])){
				p[0]++;
				ans += d.d[0];
			}else if(d.d[1]>=d.d[2]){//d.d[0]不是最大的,如果d.d[1]较大,那他也比d.d[0]大
				p[1]++;
				ans += d.d[1];
			}else{
				p[2]++;
				ans += d.d[2];
			}
			i++;
		}
		if(i<n){
			full = maxp();
			sort(a.begin()+i,a.begin()+n,compp);
			while(i<n){
				data d = a[i];
				ans += maxd(d,full);
				i++;
			}
		}
		cout << ans << " \n";
	}
	return 0;
}










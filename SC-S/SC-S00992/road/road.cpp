#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000000;
//struct Node{
//	long long nxt,to,dis;
//};
struct node{
	long long x,y,z;
};
//Node Graph[3 * MAXN];
//long long head[MAXN];
node data1[7 * MAXN];
long long n,m,k,fa[2 * MAXN],ans,cnt,x,temp[MAXN];
bool compare(const node &x,const node &y);
long long find(long long x);
//void insert_line(long long x,long long y,long long z);
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for (long long i = 1;i <= m;i ++){
		scanf("%lld %lld %lld",&data1[i].x,&data1[i].y,&data1[i].z);
	}
	for (long long i = 1;i <= k;i ++){
		scanf("%lld",&x);
		for (long long j = 1;j <= n;j ++){
			scanf("%lld",&temp[j]);
			for (long long k = 1;k < i;k ++){
				data1[++m] = {k,j,temp[k] + temp[j]};
			}
		}
	}
	for (long long i = 1;i <= n;i ++){
		fa[i] = i;
	}
	sort(data1 + 1,data1 + 1 + m,compare);
	for (long long i = 1;i <= m;i ++){
		long long L = find(data1[i].x);
		long long R = find(data1[i].y);
		if (L != R){
			fa[L] = R;
			ans += data1[i].z;
			cnt ++;
			if (cnt == n - 1){
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
bool compare(const node &x,const node &y){
	return x.z < y.z;
}
long long find(long long x){
	if (fa[x] == x){
		return x;
	} else {
		fa[x] = find(fa[x]);
		return fa[x];
	}
}
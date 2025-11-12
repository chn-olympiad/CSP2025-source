#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N = 1e5 + 10;
int T, n;
struct Node{
	int x, y, z;
}a[N];
struct Nod{
	int v,n;
}tong[N];
bool cmp(int a,int b){
	return a > b;
}
priority_queue<PII> qu1, qu2, qu3;
int num[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T --){
		memset(tong, -1, sizeof tong);
		memset(num, 0, sizeof num);
		cin >> n;
		for(int i = 1;i <= n;i ++){
			int a,b,c;
			cin >> a >> b >> c;
			
			qu1.push({a, i});
			qu2.push({b, i});
			qu3.push({c, i});
			
		}
		
		while(qu1.size()){
			PII t1 = qu1.top(), t2 = qu2.top(), t3 = qu3.top();
//			tong[t1.second] = max(tong[t1.second], t1.first);
//			tong[t2.second] = max(tong[t2.second], t2.first);
			if(tong[t1.second].v < t1.first && num[1] < (n / 2)){
				tong[t1.second].v = t1.first;
				//cout << tong[t1.second].v << 1 << "\n";
				num[tong[t1.second].n] --;
				tong[t1.second].n = 1;
				num[1] ++;
			}
			if(tong[t2.second].v < t2.first && num[2] < (n / 2)){
				tong[t2.second].v = t2.first;
				//cout << tong[t2.second].v << 2<<"\n";
				num[tong[t2.second].n] --;
				tong[t2.second].n = 2;
				num[2] ++;
			}
			if(tong[t3.second].v < t3.first && num[3] < (n / 2)){
				tong[t3.second].v = t3.first;
				//cout << tong[t3.second].v << 3<<  "\n";
				num[tong[t3.second].n] --;
				tong[t3.second].n = 3;
				num[3] ++;
			}
//			tong[t3.second] = max(tong[t3.second], t3.first);
			qu1.pop();qu2.pop();qu3.pop();
		}
		int res = 0;
		for(int i = 1;i <= n;i ++){
			if(tong[i].v == -1){
				continue;
			}
			res += tong[i].v;
		}
		cout << res << "\n";
	}
	return 0;
}
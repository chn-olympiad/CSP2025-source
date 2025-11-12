#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, ans, cnt1, cnt2;
struct node{
	int a, b, c;
}p[N];
struct zhuan{
	int jia, to;
	bool operator < (const zhuan &x) const{
		return jia < x.jia;
	}
};
priority_queue <zhuan> q1;
priority_queue <zhuan> q2;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t --){
		ans = 0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		cnt1 = 0;
		cnt2 = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++){
			scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
			if(p[i].a > p[i].b && p[i].a > p[i].c){
				if(cnt1 == (n / 2)){
					zhuan x = q1.top();
					int jia = x.jia;
					int to = x.to;
					if(jia + p[i].a < p[i].b){
						cnt2 ++;
						q2.push({p[i].a - p[i].b, i});
						ans += p[i].b;
					}
					else{
						cnt2 ++;
						q1.pop();
						q1.push({p[i].b - p[i].a, i});
						q2.push({p[to].a - p[to].b, to});
						ans += jia;
						ans += p[i].a;
					}
				}
				else{
					cnt1 ++;
					q1.push({p[i].b - p[i].a, i});
					ans += p[i].a;
				}
			}
			if(p[i].b > p[i].a && p[i].b > p[i].c){
				if(cnt2 == (n / 2)){
					zhuan x = q1.top();
					int jia = x.jia;
					int to = x.to;
					if(jia + p[i].b < p[i].a){
						cnt1 ++;
						q1.push({p[i].b - p[i].a, i});
						ans += p[i].a;
					}
					else{
						cnt1 ++;
						q2.pop();
						q2.push({p[i].a - p[i].b, i});
						q1.push({p[to].b - p[to].a, to});
						ans += jia;
						ans += p[i].b;
					}
				}
				else{
					q2.push({p[i].a - p[i].b, i});
					ans += p[i].b;
					cnt2 ++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

void _main();

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; scanf("%d", &t);
	while(t --){
		_main();
	}
	return 0;
}

int n;
int ans = 0;
priority_queue<int> pq[3];

void _main(){
	ans = 0;
	for(int i = 0; i <= 2; i ++) while(!pq[i].empty()) pq[i].pop();
	scanf("%d", &n);
	for(int i = 1, x, y, z; i <= n; i ++){
		scanf("%d%d%d", &x, &y, &z);
		if(x >= y && x >= z){
			ans += x;
			pq[0].emplace(max(y, z) - x);
		} else if(y >= x && y >= z){
			ans += y;
			pq[1].emplace(max(x, z) - y);
		} else {
			ans += z;
			pq[2].emplace(max(y, x) - z);
		}
	}
	for(int i = 0; i <= 2; i ++)
	if((signed)pq[i].size() > n / 2){
		while((signed)pq[i].size() > n / 2) ans += pq[i].top(), pq[i].pop();
		break;
	}
	printf("%d\n", ans);
	return ;
}
/*
I'm an Endangered Failed Useless human.
EFUOI(冥间组织)欢迎您
*/
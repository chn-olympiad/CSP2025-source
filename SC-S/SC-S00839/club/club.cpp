#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node{
	int a, b, c;
}e[N];

int n, t;

void init(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c); 
		e[i] = {a, b, c};
	}
	return ;
}

int a[5][N];

int cnt[5];

int di[N], dj[N], ai[N], aj[N];//i为最大 

void get(int ii){
	int a = e[ii].a, b = e[ii].b, c = e[ii].c;
	if(a >= b && a >= c){
		di[ii] = 1, ai[ii] = a;
		if(b >= c){
			dj[ii] = 2, aj[ii] = b;
		} 
		else{
			dj[ii] = 3, aj[ii] = c;
		}
	}
	else if(b >= a && b >= c){
		di[ii] = 2, ai[ii] = b;
		if(a >= c){
			dj[ii] = 1, aj[ii] = a;
		}
		else{
			dj[ii] = 3, aj[ii] = c;
		}
	}
	else{
		di[ii] = 3, ai[ii] = c;
		if(a >= b){
			dj[ii] = 1, aj[ii] = a;
		}
		else{
			dj[ii] = 2, aj[ii] = b;
		}
	}
	return ;
}

bool cmp(int a, int b){
	int x = aj[a] - ai[a];
	int y = aj[b] - ai[b];
	return x < y;
}

int ge(int i, int j){
	if(i == 1){
		return e[a[i][j]].a;
	}
	else if(i == 2){
		return e[a[i][j]].b;
	}
	else{
		return e[a[i][j]].c;
	}
	return 0;
}

void work(){
	int len = n / 2;
	for(int i = 1;i <= n;i ++){
		get(i);
	}
	for(int i = 1;i <= 3;i ++)cnt[i] = 0;
	for(int i = 1;i <= n;i ++){
		if(cnt[di[i]] < len){
			a[di[i]][++cnt[di[i]]] = i;
			push_heap(a[di[i]] + 1, a[di[i]] + cnt[di[i]] + 1, cmp);
		}
		else{
			int sum1 = aj[i];
			int ii = a[di[i]][1];
			int sum2 = ai[i] - ai[ii] + aj[ii];
			if(sum1 >= sum2){
				a[dj[i]][++cnt[dj[i]]] = i;
				push_heap(a[dj[i]] + 1, a[dj[i]] + cnt[dj[i]] + 1, cmp);
			}
			else{
				pop_heap(a[di[i]] + 1, a[di[i]] + cnt[di[i]] + 1, cmp);
				cnt[di[i]] --;
				a[dj[ii]][++cnt[dj[ii]]] = ii;
				push_heap(a[dj[ii]] + 1, a[dj[ii]] + cnt[dj[ii]] + 1, cmp);
				a[di[i]][++cnt[di[i]]] = i;
				push_heap(a[di[i]] + 1, a[di[i]] + cnt[di[i]] + 1, cmp);
			}
		}
//		cout << i << endl;
//		for(int j = 1;j <= 3;j ++){
//			cout << "j = " << j << ": ";
//			for(int k = 1;k <= cnt[j];k ++){
//				cout << a[j][k] << " "; 
//			}
//			cout << endl;
//		}
//		cout << endl;
	}
	int ans = 0;
	for(int i = 1;i <= 3;i ++){
		for(int j = 1;j <= cnt[i];j ++){
//			cout << i << " " << j << " " << a[i][j] << " " << ge(i, j) << endl; 
			ans += ge(i, j);
		}
	}
	printf("%d\n", ans);
	return ;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t --){
		init();
		work();
	}
	
	
	
	return 0;
}
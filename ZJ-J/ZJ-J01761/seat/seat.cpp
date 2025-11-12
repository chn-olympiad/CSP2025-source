#include<bits/stdc++.h>
using namespace std;
#define FINISH
struct stu{
	int score, id;
}a[110];
bool cmp(stu x, stu y){
	return x.score > y.score;
}
int n, m;
int main(){
#ifdef FINISH
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
#endif
	scanf ("%d %d", &n, &m);
	int nm = n * m;
	for (int i = 1; i <= nm; i++){
		scanf ("%d", &a[i].score);
		a[i].id = i;
	}
	sort(a + 1, a + nm + 1, cmp);
	int x;
	for (int i = 1; i <= nm; i++){
		if(a[i].id == 1){
			x = i;
			break;
		}
	}
	int y = (x - 1) / n + 1;
	printf("%d ", y);
	if(y % 2){
		printf("%d", (x - 1) % n + 1);
	}else{
		printf("%d", n - (x % n) + 1);
	}
	return 0;
}
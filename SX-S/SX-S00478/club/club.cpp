#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[100086][4];
struct gjx {
	int i,k;
	gjx(int id,ll k1) {
		i = id,k=k1;
	}
};
operator <(gjx x,gjx y) {
	return x.k<y.k;
}
bool cA();
bool cB();
bool cC();
priority_queue<gjx>A;
priority_queue<gjx>B;
priority_queue<gjx>C;
priority_queue<gjx>GJX;
int na,nb,nc;
bool cA(){
	int sz=A.size();
	if(sz>n/2){
		int i=A.top().i;
		A.pop();na-=a[i][1];
		if(a[i][2]>=a[i][3])B.push(gjx(i,-(a[i][2]-max(a[i][1],a[i][3])))),nb+=a[i][2],cB();
		else C.push(gjx(i,-(a[i][3]-max(a[i][2],a[i][1])))),nc+=a[i][3],cC();
		return 1;
	}return 0;
}
bool cB(){
	int sz=B.size();
	if(sz>n/2){
		int i=B.top().i;
		B.pop();nb-=a[i][2];
		if(a[i][1]>=a[i][3])A.push(gjx(i,-(a[i][1]-max(a[i][2],a[i][3])))),na+=a[i][1],cA();
		else C.push(gjx(i,-(a[i][3]-max(a[i][2],a[i][1])))),nc+=a[i][3],cC();
		return 1;
	}
	return 0;
}
bool cC(){
	int sz=C.size();
	if(sz>n/2){
		int i=C.top().i;
		C.pop();nc-=a[i][3];
		if(a[i][2]>=a[i][1])B.push(gjx(i,-(a[i][2]-max(a[i][1],a[i][3])))),nb+=a[i][2],cB();
		else A.push(gjx(i,-(a[i][1],-max(a[i][2],a[i][3])))),na+=a[i][1],cA();
		return 1;
	}
	return 0;
}
void run() {
	scanf("%d",&n);
	na=nb=nc=0;
	A=GJX;B=GJX;C=GJX;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)scanf("%lld",&a[i][j]);
		a[i][0] = max(a[i][1], max(a[i][3], a[i][2]));
		if (a[i][1] >= a[i][0])
			A.push(gjx(i,max(a[i][2],a[i][3])-a[i][1])),na+=a[i][1];
		else if (a[i][2]>=a[i][0])
			B.push(gjx(i,max(a[i][1],a[i][3])-a[i][2])),nb+=a[i][2];
		else
			C.push(gjx(i,max(a[i][2],a[i][1])-a[i][3])),nc+=a[i][3];
	}
	while(cA()){}
	while(cB()){}
	while(cC()){}
	printf("%lld",na+nb+nc);
	putchar('\n');
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d",&T);
	while (T--)
		run();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n,t;
int a[N],b[N],c[N];
long long ans;
bool flag1,flag2;
void solve1(){
	sort(a + 1,a + n + 1);
	for(int i = n ; i > n / 2 ; i --) ans += a[i];
	return;
}
void solve2(){
	int qz[n + 100];
	for(int i = 1 ; i <= n ; i ++){
		qz[i] = a[i] - b[i];
	}
	sort(qz + 1,qz + n + 1);
	for(int i = 1 ; i <= n ; i ++) ans += b[i];
	for(int i = n ; i > n / 2 ; i --) ans += qz[i];
	return;
}
int findmax(int a,int b,int c){
	return max(max(a,b),c);
}
void solve3(){
	int lx[3];
	int qz0[n + 100],qz1[n + 100],qz2[n + 100];
	for(int i = 1 ; i <= n ; i ++){
		int maxx = findmax(a[i],b[i],c[i]);
		if(maxx == a[i]){
			lx[0] ++;
			ans += a[i];
			qz0[lx[0]] = max(b[i] - a[i],c[i] - a[i]);
		}
		else if(maxx == b[i]){
			lx[1] ++;
			ans += b[i];
			qz1[lx[1]] = max(a[i] - b[i],c[i] - b[i]);
		}
		else{
			lx[2] ++;
			ans += c[i];
			qz2[lx[2]] = max(a[i] - c[i],b[i] - c[i]);
		}
	}
	if(lx[0] > n / 2){
		sort(qz0 + 1,qz0 + lx[0] + 1);
		//for(int i = 1 ; i <= lx[0] ; i ++) cout<<qz0[i]<<endl;
		for(int i = lx[0] ; i > n / 2 ; i --) ans += qz0[i];
	}
	else if(lx[1] > n / 2){
		sort(qz1 + 1,qz1 + lx[1] + 1);
		for(int i = lx[1] ; i > n / 2 ; i --) ans += qz1[i];
	}
	else if(lx[2] > n / 2){
		sort(qz2 + 1,qz2 + lx[2] + 1);
		for(int i = lx[2] ; i > n / 2 ; i --) ans += qz2[i];
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t --){
		ans = 0;
		flag1 = true;
		flag2 = true;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			if (b[i] != 0) flag1 = false;
			if (c[i] != 0) flag2 = false;
		}
		if(flag1) solve1();
		else if(flag2) solve2();
		else solve3();
		printf("%d\n",ans);
	}
	return 0;
}
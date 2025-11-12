#include<bits/stdc++.h>
using namespace std;
int vis[10],d[100007],p[100007],q[100007];
const int MAXN = 1e5+7;
struct ms{
	int a,b,c;
	int maxm;
};
bool cmpa(ms x,ms y){
	return x.a>y.a;
}
bool cmpb(ms x,ms y){
	return x.b>y.b;
}
bool cmpc(ms x,ms y){
	return x.c>y.c;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ms mem[MAXN];
	int t;
	cin >> t;
	int n;
	while(t--){
		int num = 0;
		cin >> n;
		int maxa = n/2,maxb = n/2,maxc = n/2;
		bool flag = true,flag2 = true;
		int sum = 0;
		for(int i = 0;i<n;i++){
			cin >> mem[i].a >> mem[i].b >> mem[i].c;
			if(mem[i].b == 0 && mem[i].c == 0){
				flag = false;
				sum+=max(mem[i].a,mem[i].b);
				continue;
			}
		}if(!flag){
			sort(mem,mem+n,cmpa);
			for(int i = 0;i<n/2;i++){
				num+=mem[i].a;
			}cout << num;
		}
	}
	return 0;
} 

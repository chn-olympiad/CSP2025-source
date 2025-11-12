#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct node{
	int a,b,c,ma;
};

int n,ans,b[3];
int f[100005];
node a[100005];

bool cmp(node a,node b){
	return a.ma > b.ma;
}

void solve(){
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	memset(b,0,sizeof(b));
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i].a >> a[i].b >> a[i].c;
		a[i].ma = max(a[i].a,max(a[i].b,a[i].c));
	}
	sort(a,a + n,cmp);
	for(int i = 0;i < n;i++){
		if(a[i].a > a[i].b && a[i].b > a[i].c){
			if(b[0] < n / 2){f[i + 1] = f[i] + a[i].a;b[0]++;}
			else if(b[1] < n / 2){f[i + 1] = f[i] + a[i].b;b[1]++;}
			else{f[i + 1] = f[i] + a[i].c;b[2]++;}
		}else if(a[i].a > a[i].c && a[i].c > a[i].b){
			if(b[0] < n / 2){f[i + 1] = f[i] + a[i].a;b[0]++;}
			else if(b[2] < n / 2){f[i + 1] = f[i] + a[i].c;b[2]++;}
			else{f[i + 1] = f[i] + a[i].b;b[1]++;}
		}else if(a[i].b > a[i].a && a[i].a > a[i].c){
			if(b[1] < n / 2){f[i + 1] = f[i] + a[i].b;b[1]++;}
			else if(b[0] < n / 2){f[i + 1] = f[i] + a[i].a;b[0]++;}
			else{f[i + 1] = f[i] + a[i].c;b[2]++;}
		}else if(a[i].b > a[i].c && a[i].c > a[i].a){
			if(b[1] < n / 2){f[i + 1] = f[i] + a[i].b;b[1]++;}
			else if(b[2] < n / 2){f[i + 1] = f[i] + a[i].c;b[2]++;}
			else{f[i + 1] = f[i] + a[i].a;b[0]++;}
		}else if(a[i].c > a[i].b && a[i].b > a[i].a){
			if(b[2] < n / 2){f[i + 1] = f[i] + a[i].c;b[2]++;}
			else if(b[1] < n / 2){f[i + 1] = f[i] + a[i].b;b[1]++;}
			else{f[i + 1] = f[i] + a[i].a;b[0]++;}
		}else{
			if(b[2] < n / 2){f[i + 1] = f[i] + a[i].c;b[2]++;}
			else if(b[0] < n / 2){f[i + 1] = f[i] + a[i].a;b[0]++;}
			else{f[i + 1] = f[i] + a[i].b;b[1]++;}
		}
	}
	cout << f[n] << '\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin >> t;
	while(t--) solve();
	return 0;
}

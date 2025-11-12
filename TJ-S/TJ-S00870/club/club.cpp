#include<bits/stdc++.h>
using namespace std;

struct ts{
	int c , num , sum , cn;
};

int a[100005];
int b[100005];
int c[100005];
ts cha[300005];
int t[5];
int f[100005];
int n , cnt;

bool cmp(ts x , ts y){
	if(x.c == y.c){
		int xct = x.cn - x.sum + 1;
		int xc1 , xc2;
		if(x.sum == 1){
			xc1 = xct+1;
			xc2 = xct+2;
		}else if(x.sum == 2){
			xc1 = xct;
			xc2 = xct + 2;
		}else{
			xc1 = xct;
			xc2 = xct + 1;
		}
		
		int yct = y.cn - y.sum + 1;
		int yc1 , yc2;
		if(y.sum == 1){
			yc1 = yct+1;
			yc2 = yct+2;
		}else if(y.sum == 2){
			yc1 = yct;
			yc2 = yct + 2;
		}else{
			yc1 = yct;
			yc2 = yct + 1;
		}
		
		if(cha[xc1].c >= cha[yc2].c && cha[xc1].c >= cha[yc1].c){
			return 1;
		}else if(cha[xc2].c >= cha[yc2].c && cha[xc2].c >= cha[yc1].c){
			return 1;
		}else{
			return 0;
		}
	}else{
		return x.c > y.c;
	}
}

void clear(){
	for(int i = 0;i <= n+1;i++){
		a[i] = b[i] = c[i] = 0;
		f[i] = 0;
	}for(int i = 0;i <= cnt+1;i++){
		cha[i] = {0 , 0 , 0 , 0};
	}
	t[1] = t[2] = t[3] = t[4] = 0;
}

int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	int T;
	cin >> T;
	for(int res = 1;res <= T;res++){
		clear();
		cin >> n;
		cnt = 0;
		
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		
		for(int i = 1;i <= n;i++){
			cnt++;
			cha[cnt] = {min(a[i]-b[i] , a[i]-c[i]) , i , 1 , cnt};
			
			cnt++;
			cha[cnt] = {min(b[i]-a[i] , b[i]-c[i]) , i , 2 , cnt};
			
			cnt++;
			cha[cnt] = {min(c[i]-a[i] , c[i]-b[i]) , i , 3 , cnt};
		}
		
		sort(cha+1 , cha+cnt+1 , cmp);
		
		long long ans = 0;
		for(int i = 1;i <= cnt;i++){
			if(t[cha[i].sum] == n / 2 || f[cha[i].num] == 1){
				continue;
			}
			
			t[cha[i].sum] += 1 , f[cha[i].num] = 1;
			
			if(cha[i].sum == 1){
				ans = ans + a[cha[i].num];
			}else if(cha[i].sum == 2){
				ans = ans + b[cha[i].num];
			}else{
				ans = ans + c[cha[i].num];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

// 姚奕辰 SN-S00140 西安市曲江第一学校 
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct s{
	int xie1;
	int xie2;
	int xie3;
	int he;
}a[100005];
int cida(int x,int y,int z){
	if(x > y > z){
		return y;
	}
	else if(x > z > y){
		return z;
	}
	else if(y > x > z){
		return x;
	}
	else if(y > z > x){
		return z;
	}
	else if(z > x > y){
		return x;
	}
	else{
		return y;
	}
}
int t,n,xiee1 = 0,xiee2 = 0,xiee3 = 0,maxx[100005],minn[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t --){
		cin >> n;
		xiee1 = 0;
		xiee2 = 0;
		xiee3 = 0;
		for(int i = 1;i <= n;i ++){
			maxx[i] = -100005;
			minn[i] = 100005;
		}
		for(int i = 1;i <= n;i ++){
			cin >> a[i].xie1 >> a[i].xie2 >> a[i].xie3;
			maxx[i] = max(max(a[i].xie3,a[i].xie1),a[i].xie2);
		}
		for(int i = 1;i <= n;i ++){
			if(xiee1 < 2 && maxx[i] == a[i].xie1){
				a[t].he += maxx[i];
				xiee1 ++;
			}
			else if(xiee1 >= 2 && maxx[i] == a[i].xie1){
				a[t].he += cida(a[i].xie1,a[i].xie2,a[i].xie3);
			}
			else if(xiee2 < 2 && maxx[i] == a[i].xie2){
				a[t].he += maxx[i];
				xiee2 ++;
			}
			else if(xiee2 >= 2 && maxx[i] == a[i].xie2){
				a[t].he += cida(a[i].xie1,a[i].xie2,a[i].xie3);
			}
			else if(xiee3 < 2 && maxx[i] == a[i].xie3){
				a[t].he += maxx[i];
				xiee3 ++;
			}
			else if(xiee3 >= 2 && maxx[i] == a[i].xie3){
				a[t].he += cida(a[i].xie1,a[i].xie2,a[i].xie3);
			}
		}
		cout << a[t].he;
	}
	return 0;
}

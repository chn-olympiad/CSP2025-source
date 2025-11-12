//杨陈泽 SN-J00417 西安高新第一中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t , n;
struct ys{
	int x , y , z;
}a[200010];
bool cmp1(ys x , ys y){
	return min(abs(x.x - x.y) , abs(x.x - x.z)) < min(abs(y.x - y.y) , abs(y.x - y.z));
}
bool cmp2(ys x , ys y){
	return min(abs(x.y - x.x) , abs(x.y - x.z)) < min(abs(y.y - y.x) , abs(y.y - y.z));
}
bool cmp3(ys x , ys y){
	return min(abs(x.z - x.y) , abs(x.z - x.x)) < min(abs(y.z - y.y) , abs(y.z - y.x));
}
signed main()
{
	freopen("club5.in" , "r" , stdin);
	freopen("club5.out" , "w" , stdout);
	cin >> t;
	while(t--){
		cin >> n;
		int cnt = 0 , ax = 0 , ay = 0 , az = 0;
//		for(int i = 1 ; i <= 200010 ; i++){
//			a[i].x = 0;
//			a[i].y = 0;
//			a[i].z = 0;
//		}
		for(int i = 1 ; i <= n ; i++)
			cin >> a[i].x >> a[i].y >> a[i].z;
		for(int i = 1 ; i <= n ; i++){
			if(a[i].x > a[i].y){
				if(a[i].x > a[i].z){
					cnt += a[i].x;
					ax++;
					continue;
				}
				else{
					cnt += a[i].z;
					az++;
					continue;
				}
			}
			else{
				if(a[i].y > a[i].z){
					cnt += a[i].y;
					ay++;
					continue;
				}
				else{
					cnt += a[i].z;
					az++;
					continue;
				}
			}
		}
		if(ax > n/2){
			sort(a + 1 , a + n + 1 , cmp1);
			ax -= n/2;
			for(int i = 1 ; i <= ax ; i++)
				cnt -= min(abs(a[i].x - a[i].y) , abs(a[i].x - a[i].z));
		}
		else if(ay > n/2){
			sort(a + 1 , a + n + 1 , cmp2);
			ay -= n/2;
			for(int i = 1 ; i <= ay ; i++)
				cnt -= min(abs(a[i].y - a[i].x) , abs(a[i].y - a[i].z));
		}
		else if(az > n/2){
			sort(a + 1 , a + n + 1 , cmp3);
			az -= n/2;
			for(int i = 1 ; i <= az ; i++)
				cnt -= min(abs(a[i].z - a[i].y) , abs(a[i].z - a[i].x));
		}
		cout << cnt << endl;
	}
	return 0;
}

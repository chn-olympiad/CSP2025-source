#include <iostream>
using namespace std;

int n, k; //如题
int lst; //上一个sum==3位置下标
int ans; //答案
int ind = 1; //游标index
int sum = -1; //目前异或和

const int N = 5e5 + 10;
int a[N];

void my_addsm(int x){
	if(sum == -1) sum = x;
	else sum = sum ^ x;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin>>n>>k;
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	
	while(lst <= n && ind <= n){
		my_addsm(a[ind]);
//		cout<<"ind = "<<ind<<", sum = "<<sum;
		bool flag = false;
		if(sum == k){
//			cout<<" sum == k "<<ans;
			ans ++;
			sum = -1;
			lst = ind;
			flag = true;
		}
		if(ind == n && !flag){
			ind = lst;
			lst ++;
		}
		ind ++;
//		cout<<endl;
	}
	
	cout<<ans<<endl;
	
	return 0;
}

/*

异或运算符 ^
这题像是前缀和
好像还有一点dp

我有一点思路了
从前往后遍历数组
不停加异或和存进sum   if(sum == -1) sum = a[i];
sum == k时 ans ++, sum = -1, 继续。
i == n && sum != k时从上一个加到k的下标(存为lst)+1继续枚举

a 	2 	1   1 	3
sum	2	3 | 1	2 cannot
sum           | 3

ans == 2.

10:50:22 大样例5和6过不了 很莫名其妙
10:51:54 Intel Core Ultra 9 285K CPU @ 3.70 GHz，内存 96 GB 超雄评测机
10:55:16 不调了，部分分吧

*/


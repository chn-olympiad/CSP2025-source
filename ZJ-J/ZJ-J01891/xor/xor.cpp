#include<bits/stdc++.h>
using namespace std;
struct xz{
	int l, r, len;
}; 
int z[100005];//输入的十进制数 
int q[100005];//前缀按位异或和
bool x[100005];//区间是否占用
xz p[100005];//符合条件的区间 
int n, k, tmp = 0, sum = 0;
bool cmp(xz x, xz y){
	return x.len < y.len;
}
int two_to_ten(string a){//二进制转十进制 
	int z = 0, cnt = 0, y = 20;
	while (y--)
	{
		z += ((a[cnt++] - '0') * pow(2, y));
	}
	return z;
}
string ten_to_two(int n){//十进制转二进制
	string s = "00000000000000000000";
	int cnt = 19;
	while (n)
	{
		s[cnt--] = (n % 2 == 0 ? '0' : '1');
		n /= 2; 
	}
	return s;
} 
string Awyh(string x, string y){//按位异或 
	string s = "00000000000000000000";
	for (int i = 0; i <= 19; i ++)
		if (x[i] != y[i]) s[i] = '1';
	return s;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){//输入，统计前缀和 
		cin >> z[i];
		q[i] = two_to_ten(Awyh(ten_to_two(q[i-1]), ten_to_two(z[i])));
	} 
	int zx = 1;//从一开始找
	while(zx != n){//找出所有符合调件的区间及其长度
		for (int i = zx; i <= n; i ++)
			if (two_to_ten(Awyh(ten_to_two(q[zx-1]),ten_to_two(q[i]))) == k){
				p[++tmp].l = zx; p[tmp].r = i; p[tmp].len = i - zx + 1;
			}
		zx ++;
	}
	sort(p + 1, p + tmp + 1, cmp);
	for (int i = 1; i <= tmp; i ++){//优先选择长度较短的序列 
		int t = 1;
		for (int j = p[i].l; j <= p[i].r; j ++)
		{
			if (x[j] == 1) {
				t = 0; break;
			}
		}
		if (t) 
		{
			for (int j = p[i].l; j <= p[i].r; j ++)
			{
				x[j] = 1;
			}
			sum ++;
		}
	}
	cout << sum;
}

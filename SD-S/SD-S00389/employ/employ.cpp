#include<bits/stdc++.h>

#define ll long long

using namespace std;
/*

//非常像dp
//[i]//第几个
//[j]//占几个位置最大
//[k]//被分到机组
//dp[i][j][k]
//遍历一遍其他组中
//
//先等等
//孤立地看问题
//就是背包
//
//限制：
//同一个数只能取一次
//那就分别算这个数

三个优先队列



*/

ll n,m;


int main() {

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);

	cin>>n>>m;



	ll num=1;
	for(int i=1; i<=n; i++) {

		num*=i% 998244353;
		num=num%998244353;

	}
	cout<<num;



	return 0;
}


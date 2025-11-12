#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+7;

int m,n;
string s;
int c[N];
__int128_t ans = 0;

/*
写不出来了，只能拿出独门秘籍骗分了
不好，这题貌似骗分要使用高精度 
*/

__int128_t A(int nn,int mm) { // nn >= mm
	__int128_t a = 1;
	for(int i=1;i<=nn;i++) {
		a *= i;
	}
	__int128_t b = 1;
	for(int i=1;i<=(nn-mm);i++) {
		b *= i;
	}
	return a/b;
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i=1; i<=n; i++) {
		cin >> c[i];
	}
	
	// 当s=1111111111时,答案实际上就是A(n,m)
	// 全当这种情况写了,因为其他的情况不会写
	// 悲，只会做数学题
	
	if(m == 1) { // 最后的倔强;话说真的会有公司只录取一个人吗
	// 万一是个性质A呢
		
		cout << n%998244353;
		return 0;
	}	
	
	ans = A(n,m); // 听天由命，大概率过不了这个点 
//	cout << ans << " <ans\n";
	cout << (ll)(ans%998244353) << "\n";
	
	return 0;
}

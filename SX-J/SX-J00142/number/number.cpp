#include<bits/stdc++.h>

using namespace std;

char s[1000010];
vector<int> v;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i ++){
		if(s[i] >= '0' && s[i] <= '9') v.emplace_back(s[i] - '0');
	}
	sort(v.begin(), v.end(), greater<int>());
	for(auto i : v) printf("%d", i);
	return 0;
}
/*
-------------------------hty111-------------------------
今日放水局，9:10做完开始对拍;
T1: 简单排序
时间复杂度: $\mathcal O(n \log{n})$
Expect: 100pts
-------------------------hty111-------------------------
*/
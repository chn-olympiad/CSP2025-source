#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int num[N], k;
char c[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> c;
	for(int i = 0; c[i]; i ++)
		if(isdigit(c[i]))
			num[k ++] = c[i] - '0';
	sort(num, num + k - 1, greater<int>());
	for(int i = 0; i < k; i ++) printf("%d", num[i]);
	puts("");
	
	
	
	
	return 0;
}

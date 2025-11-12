#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, k, a[N], f[N], maxv;

int xo(int a, int b)
{
    string s1 = "", s2 = "", s = "";
    int k = 1, ans = 0, l1 = 0, l2 = 0;
    do {
        char c = (a % 2 + '0');
        s1 = c + s1;
        a /= 2;
    }while(a > 0);
    do {
        char c = (b % 2 + '0');
        s2 = c + s2;
        b /= 2;
    }while(b > 0);
    while(s1.length() < s2.length()) s1 = '0' + s1;
    while(s1.length() > s2.length()) s2 = '0' + s2;
    int len = max(s1.length(), s2.length());
    for(int i = 0; i < len; i++) {
        s[i] = (s1[i] != s2[i] ? '1' : '0');
    }
    for(int i = len - 1; i >= 0; i--) {
        ans += (s[i] - '0') * k;
        k *= 2;
    }
    return ans;
}
int dfs(int j)
{
    int ans = 0, sum = 0;
    for(int i = j; i <= n; i++) {
        sum = xo(sum, a[i]);
        //if(j == 1) cout <<sum <<endl;
        if(sum == k) {
            if(f[i] == -1) f[i] = dfs(i + 1) + 1;
            ans = max(ans, f[i]);
        }
    }
    return ans;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[i] = -1;
	}
	cout << dfs(1) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

string s;
int f[15], flag = 0;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i++)
        if('0' <= s[i] && s[i] <= '9')
            f[s[i] - '0']++;
    for(int i = 9; i >= 0; i--) {
        if(f[i] && i > 0) flag = 1;
        while(f[i]--) {
            printf("%d", i);
            if(!flag) break;
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
string s; 
int a[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> s;
	int ls = s.size();
	int n = 0;
	for(int i = 0;i < ls;i++){
		if(s[i] >= '0' && s[i] <= '9') a[++n] = s[i] - '0';
	}
	sort(a + 1, a + n + 1);
	for(int i = n;i >= 1;i--) cout << a[i];
	return 0;
}



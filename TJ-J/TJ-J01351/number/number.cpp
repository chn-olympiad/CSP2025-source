#include <bits/stdc++.h>

using namespace std;

int cmp(int q, int w){
    if (q >= w) {
        return q;
    } else {
        return w;
    }
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int a[412712];
    a[0] = 0;
    int b = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == '1' or s[i] == '2' or s[i] == '3' or s[i] == '4' or s[i] == '5' or s[i] == '6' or s[i] == '7' or s[i] == '8' or s[i] == '9' or s[i] == '0') {
        	char t = s[i];
        	int y;
        	y = t - 48;
            a[b] = y;
            b++;
        } else {
			continue;
		}
    }
    //sort(begin(a), end(a), greater<int>);
    for (int i = 0; i <= b - 1; i++) {
        cout << a[i];
    }

    cout << endl;

 return 0;
}

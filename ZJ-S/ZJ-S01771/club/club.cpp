#include<bits/stdc++.h>
using namespace std;

long long read() {
    long long x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c - '0');c = getchar();}
    return x * f;
}
const int N = 2e5 + 10;
struct node {
    int a[5], id;
}a[N];
int sum[5];
int b[N];
bool cmp1(node x, node y) {
    return b[x.id] < b[y.id];
}
int getnxt(node x) {
    int idx1 = 0;
    for (int i = 1; i <= 3; i++) {
        if(x.a[b[x.id]] >= x.a[i] && i != b[x.id] && (idx1 == 0 || x.a[idx1] < x.a[i])) {
                idx1 = i;
        }
    }
    return idx1;
}
bool cmp2(node x, node y) {
    int idx1 = getnxt(x);
    int idx2 = getnxt(y);
    return x.a[b[x.id]] - x.a[idx1] < y.a[b[y.id]] - y.a[idx2];
}
int l[5], r[5];
void Main() {
	sum[2] = sum[1] = sum[3] = 0;
    int n = read();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        a[i].a[1] = read();
        a[i].a[2] = read();
        a[i].a[3] = read();
        a[i].id = i;
        int idx = 0;
        if(a[i].a[1] >= a[i].a[idx]) idx = 1;
        if(a[i].a[2] >= a[i].a[idx]) idx = 2;
        if(a[i].a[3] >= a[i].a[idx]) idx = 3;
        sum[idx]++;
        ans += a[i].a[idx];
        b[i] = idx;
    }
    //for (int i = 1; i <= n; i++) {
    //	cout << b[i] << " ";
	//}
	//cout << ans << endl;
    sort(a + 1, a + n + 1, cmp1);
    for (int k = 1; k <= 3; k++) {
    	l[k] = -1;
    	r[k] = 0;
    	for (int i = 1; i <= n; i++) {
    		if(b[a[i].id] != k) continue;
    		if(l[k] < 0) l[k] = i;
    		r[k] = i;
		}
	}
    for (int k = 1; k <= 3; k++) {
    	
        if(sum[k] > n / 2) {
            sort(a + l[k], a + r[k] + 1, cmp2);
            int cnt = sum[k] - n / 2;
            for (int i = 1; i <= cnt; i++) {
                int idx = i + l[k] - 1;
                int nxt = getnxt(a[idx]);
                ans -= a[idx].a[k] - a[idx].a[nxt];
                sum[k]--;
                sum[nxt]++;
                //cout << i << " " << ans << endl;
                //	cout << a[idx].a[1] << " " << a[idx].a[2] << " " << a[idx].a[3] << endl;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int _ = read();
    while(_--) Main();
    return 0;
}
/*

g++ -std=c++14 -O2 -Wall -Wextra -Wl,--stack=512000000 1.cpp -o 1
*/
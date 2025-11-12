#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    for(; ch < '0' || ch > '9'; w *= ch == '-' ? -1 : 1, ch = getchar());
    for(; ch >= '0' && ch <= '9'; s = s * 10 + ch - '0', ch = getchar());
    return s * w;
}
const int MAXN = 100005;
int N, a[MAXN][3], res, c[MAXN];
vector<int> cnt[4];
signed main(){
//	freopen("club5.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T--){
		for(int i = 1; i <= 3; i++) cnt[i].clear();
		res = 0;
		N = read();
	    for(int i = 1, mx; i <= N; i++){
	        mx = 0;
	        for(int j = 1; j <= 3; j++){
	        	a[i][j] = read(), mx = max(mx, a[i][j]);
	        }
	        for(int j = 1; j <= 3; j++){
	            if(a[i][j] == mx){
	                cnt[j].push_back(i);
	                res += mx;
	                break;
	            }
	        }
	    }
	    int flag = 0;
	    for(int i = 1; i <= 3; i++){
	        if(cnt[i].size() > N / 2){
	            flag = i;
	            break;
	        }
	    }
	    if(flag == 0){
	        cout << res << endl;
	        continue;
	    }
	//    cout << flag << " " << cnt[flag].size() << endl;
		for(int i = 1, cur, v; i <= cnt[flag].size(); i++){
			cur = cnt[flag][i - 1], v = 0;
			for(int j = 1; j <= 3; j++){
				if(j == flag) continue;
				v = max(v, a[cur][j]);
			}
			c[i] = a[cur][flag] - v;
		}
	//	for(int i = 1; i <= cnt[flag].size(); i++) cout << c[i] << " ";
	//	cout << endl;
		sort(c + 1, c + 1 + cnt[flag].size());
		for(int i = 1; i <= cnt[flag].size() - N / 2; i++){
			res -= c[i];
		}
		cout << res << endl;
	}
    return 0;
}
/*
At 15:15, complete the code of problem A and test it with 5 examples receiving expected results.
I havn't read statements of other problems yet, so now i'm going to read those.
Feeling a little bit of sleepy...
The boy seated next to me is always coughing...
By 15:46, I read statements of B, C and D, and I have no idea to solve them...
A bit of tired, I guess it is the time to try to get partical points.
My goal is to reach 200pts, but it seems that I couldn't solve B.
Maybe it is just because I'm tired, but it is also possible that i am not capable of it.
At 16:18, I wake up, which means I have slept for half an hour.
//freopen("club.in", "r", stdin);
//freopen("club.out", "w", stdout);
*/
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
/*
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
/*
2
10 9 8
4 0 0
*/

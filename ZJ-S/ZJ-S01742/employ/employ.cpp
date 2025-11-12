#include <bits/stdc++.h>
#define ll long long
#define MOD (ll) (998244353)
using namespace std;

int N, M;
// int difficulty_cnt;
ll ans;
int c[505];
char difficulty[505];
// bool pass[505];

// int count_below_include_eq(int x)
// {
//     int l = 1, r = 
// }

// void calc()
// {
//     int cnt = 0;
//     for(int i = 1; i <= N; ++ i)
//     {
//         if(pass[i]) cnt ++;
//     }
//     if(cnt < M || cnt != difficulty_cnt) return;
//     int real_denied_cnt = 0;
//     for(int i = 1; i <= N; ++ i)
//     {
//         if(!pass[i]) {
//             real_denied_cnt ++;
//             continue;
//         }

//         ans = ans * ()
//     }
//     ans = (ans + ) % MOD;
// }

// void dfs(int who)
// {
//     if(who == N + 1) calc();
//     else {
//         pass[who] = true;
//         dfs(who + 1);
//         pass[who] = false;
//         dfs(who + 1);
//     }
// }

int order[505];
bool used[505];

void calc()
{
    int failed_cnt = 0;
    for(int i = 1; i <= N; ++ i)
    {
        int u = order[i];
        if(difficulty[i] == '0' || failed_cnt >= c[u]) ++ failed_cnt;
    }

    if(N - failed_cnt >= M) ans = (ans + 1) % MOD;
}

void dfs(int who)
{
    if(who == N + 1) calc();
    else {
        for(int i = 1; i <= N; ++ i)
        {
            if(used[i]) continue;
            used[i] = true;
            order[who] = i;
            dfs(who + 1);
            used[i] = false;
            order[who] = 0;
        }
    }
}

ll fac(ll x)
{
	ll res = 1;
	for(int i = 1; i <= x; ++ i) res = (res * i) % MOD;
	return res;
}

void solA()
{
//	puts("Here");
	sort(c + 1, c + N + 1);
//	ans = 1;
	int alive_cnt = 0, dead_cnt;
	for(int i = 1; i <= N; ++ i)
		alive_cnt += (c[i] == 0 ? 0 : 1);
	
	dead_cnt = N - alive_cnt;
	while(dead_cnt <= N)
	{
		while(c[dead_cnt + 1] == c[dead_cnt]) ++ dead_cnt;
		if(N - dead_cnt < M) break;
		ans = (ans + fac(dead_cnt) * fac(N - dead_cnt) % MOD) % MOD;
		++ dead_cnt;
	}
}

void solC()
{
	ans = fac(N);
	for(int i = 1; i <= N; ++ i)
	{
		if(c[i] == 0) ans = 0;
	}
}

void solD()
{
	ans = fac(N);
	int zero_in_a_row = 0;
	for(int i = 1; i <= N; ++ i)
	{
		if(difficulty[i] == '0') ++ zero_in_a_row;
		else zero_in_a_row = 0;
	}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin >> N >> M;
    bool flagA = true;
    for(int i = 1; i <= N; ++ i)
    {
        cin >> difficulty[i];
        if(difficulty[i] == 0) flagA = false;
        // difficulty_cnt += (difficulty[i] ? 1 : 0);
    }
    
    for(int i = 1; i <= N; ++ i)
        cin >> c[i];
	
//	puts("");
    if(N <= 10) dfs(1);
//    else if(N <= 18) dfs(1);
    else if(flagA) solA();
//    else if(flagB) solB();
    else if(N == M) solC();
    else if(M == 1) solD();
    cout << ans % MOD << endl;
    return 0;
}

/*
 */
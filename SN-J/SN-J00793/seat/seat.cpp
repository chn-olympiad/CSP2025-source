#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e2 + 3;
ll ans, a[N], mm, n, m, m_n, m_m;
bool cmp(int r, int l){
    return l < r;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n,&m);
    for(int i = 1; i <= n * m; i ++)
        scanf("%d", &a[i]);
    mm = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = n * m; i >= 1; i --){
        if (a[i] == mm){
            m_m = i / n;
            if (i % n != 0)
                m_m ++;
            if (m_m % 2 == 1){
                m_n = i % n;
                if (m_n == 0)
                    m_n = n;
            }
            if (m_m % 2 == 0){
                m_n =  n - i % n + 1;
                if (m_n > n)
                    m_n = 1;
            }
			break;
        }
    }
    printf("%d %d", m_m, m_n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

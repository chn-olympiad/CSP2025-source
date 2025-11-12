#include <bits/stdc++.h>
using namespace std;
struct stu{
    int a1, a2, a3, j, m;
};
bool cmp( stu x, stu y ){
    return x.m > y.m;
}
stu a[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ){
            cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
            if( a[i].a1 > a[i].a2 ){
                if( a[i].a1 > a[i].a3 ){
                    a[i].j = 1;
                    a[i].m = a[i].a1;
                }
                else{
                    a[i].j = 3;
                    a[i].m = a[i].a3;
                }
            }
            else{
                if( a[i].a2 > a[i].a3 ){
                    a[i].j = 2;
                    a[i].m = a[i].a2;
                }
                else{
                    a[i].j = 3;
                    a[i].m = a[i].a3;
                }
            }
        }
        long long sum1 = 0, sum2 = 0;
        sort(a+1, a+1+n, cmp);
        int s = n / 2, b[5] = {0,0,0,0};
        for( int i = 1; i <= n; i++ ){
            if( b[a[i].j] < s ){
                sum1 += a[i].m;
                b[a[i].j]++;
            }
            else{
                if( a[i].j == 1 ){
                    if( a[i].a2 > a[i].a3 ){
                        sum1 += a[i].a2;
                        b[2]++;
                    }
                    else{
                        sum1 += a[i].a3;
                        b[3]++;
                    }
                }
                else if( a[i].j == 2 ){
                    if( a[i].a1 > a[i].a3 ){
                        sum1 += a[i].a1;
                        b[1]++;
                    }
                    else{
                        sum1 += a[i].a3;
                        b[3]++;
                    }
                }
                else{
                    if( a[i].a2 > a[i].a1 ){
                        sum1 += a[i].a2;
                        b[2]++;
                    }
                    else{
                        sum1 += a[i].a1;
                        b[1]++;
                    }
                }
            }
        }
        b[1] = 0, b[2] = 0, b[3] = 0;
        for( int i = n; i >= 1; i-- ){
            if( b[a[i].j] < s ){
                sum2 += a[i].m;
                b[a[i].j]++;
            }
            else{
                if( a[i].j == 1 ){
                    if( a[i].a2 > a[i].a3 ){
                        sum2 += a[i].a2;
                        b[2]++;
                    }
                    else{
                        sum2 += a[i].a3;
                        b[3]++;
                    }
                }
                else if( a[i].j == 2 ){
                    if( a[i].a1 > a[i].a3 ){
                        sum2 += a[i].a1;
                        b[1]++;
                    }
                    else{
                        sum2 += a[i].a3;
                        b[3]++;
                    }
                }
                else{
                    if( a[i].a2 > a[i].a1 ){
                        sum2 += a[i].a2;
                        b[2]++;
                    }
                    else{
                        sum2 += a[i].a1;
                        b[1]++;
                    }
                }
            }
        }
        cout << max(sum1, sum2)<< endl;
    }
    return 0;
}

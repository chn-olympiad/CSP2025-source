#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    //9:29
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);


    ll n , m;
    cin >> n >> m;
    ll sum = n * m;
    ll R , index = 1;
    cin >> R;
    for(ll i = 2;i <= sum;i++){
        ll num;
        cin >>num;

        if(num > R){
            index++;
        }
    }

    ll a = (index / m);
    if(index % m != 0){
        a++;
    }

    ll b;

    if(a % 2 == 1){
        ll be = (a - 1) * n + 1;
        b = index - be + 1;
    }
    else{
        ll be = a * n;
        b = be - index + 1;
    }

    cout << a << ' ' << b << endl;
    return 0;
}

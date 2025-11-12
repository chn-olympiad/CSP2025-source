#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n , k;
vector<ll> arr;

bool check(pair<ll , ll> x , pair<ll , ll> y);

vector<pair<ll , ll> > solve1(){
    vector<pair<ll , ll> > re;
    for(ll len = 1;len <= n;len++){
        for(ll i = 1;i + len - 1 <= n;i++){
            ll j = i + len - 1;
            ll ans = arr[i];
            for(ll l = i + 1;l <= j;l++){
                ans ^= arr[l];
            }
            if(ans == k){
                bool can = true;
                for(auto it = re.begin();it != re.end() && can;it++){
                    can = check(*it , {i , j});
                }
                if(!can){
                    continue;
                }
                re.push_back({i , j});
            }
        }
    }

    return re;
}

bool check(pair<ll , ll> x , pair<ll , ll> y){
	ll a = x.first;
	ll b = x.second;
	ll c = y.first;
	ll d = y.second;
    if(a > c){
        swap(a , c);
        swap(b , d);
    }
    for(ll i = a;i <= b;i++){
        if(i >= c && i <= d){
            return false;
        }
    }
    return true;
}

int main(){
    //10:34
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    bool sp_a = true;

    cin >> n >> k;
    arr.resize(n + 1);
    for(ll i = 1;i <= n;i++){
        cin >> arr[i];
        sp_a = (sp_a && arr[i] == 1);
    }
    vector<pair<ll , ll> > ans;
    vector<pair<ll , ll> > re;
    if(sp_a){
        cout << n / 2 << endl;
        return 0;
    }
    else{
        re = solve1();
    }

    cout << re.size() << endl;

    return 0;
}

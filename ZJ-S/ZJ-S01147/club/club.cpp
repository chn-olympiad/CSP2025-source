#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node
{
    int a, b, c;

    int mx(){
        return max({a,b,c});
    }

    int smx(){
        int smx = 0;
        int mx = max({a,b,c});
        if(mx == a)smx = max(b,c);
        if(mx == b)smx = max(a,c);
        if(mx == c)smx = max(a,b);
        return smx;
    }

    int mx_index(){
        int mx = this->mx();
        if(mx == a)return 0;
        if(mx == b)return 1;
        if(mx == c)return 2;
        return mx;
    }


    int smx_index(){
        int smx = this->smx();
        if(smx == a)return 0;
        if(smx == b)return 1;
        if(smx == c)return 2;
        return smx;
    }
};

struct Lost{
    int value;
    int id;

    bool operator>(const Lost& o)const{
        return this->value > o.value;
    }
    bool operator<(const Lost& o)const{
        return this->value < o.value;
    }
};
vector<Node> vec;
vector<Lost> loss;

void solve(){
    vec.clear();
    loss.clear();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        vec.push_back(Node{x,y,z});
        loss.push_back(Lost{vec.back().smx()-vec.back().mx(), i-1});
    }
    sort(loss.begin(), loss.end());
    ll ans = 0;
    ll cnt[3] = {0};
    for(auto i:loss){
        if(cnt[vec[i.id].mx_index()] == n/2){
            cnt[vec[i.id].smx_index()]++;
            ans += vec[i.id].smx();
        }
        else{
            cnt[vec[i.id].mx_index()]++;
            ans += vec[i.id].mx();
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}
// 首先选出三个值中最大的值，分别排序，例如样例2则有
// a1 = {0 0 0 0}
// a2 = {2 2 1 1}
// a3 = {0 0 0 0}
// 因为 a2 不能超过 2 个人
// 故剔除贡献较小的 1 和 1
// 但是我们要考虑长期贡献
// 如样例 3
// 我们注意到排序后如果选 10 那么最大和是不行的
// 我们考虑改变排序后所需改变的贡献值
// 如 10 9 8 改变的贡献值为 -1
// 如 4 0 0 改变的贡献值为 -4
// 由于只是不能超过 n/2 故我们选可能的不能选的另一个值的最大值
// 所以说再次排序：{-4 -1} 故 -4 的要求最紧
// 故 -4 先排，然后再考虑其他的

// 故思路为：
// 先处理损失函数，再按照损失的从高到低进行排序，并进行选择
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=500005;
const int INF=0x3f3f3f3f;
ll a[N],pre[N];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) pre[i]=(pre[i-1]^a[i]);
    vector<pair<int,int> > vec;
    map<ll,int> mp;
    mp[0]=0;
    for(int i=1;i<=n;i++){
        if(vec.empty()){
            if(mp.count(pre[i]^k)){
                pair<ll,int> t;
                t.first=mp[pre[i]^k]+1;
                t.second=i;
                vec.push_back(t);
            }
        }else{
            if(mp.count(pre[i]^k)){
                pair<ll,int> t;
                t.first=mp[pre[i]^k]+1;
                t.second=i;
                if(t.first>vec.back().second) vec.push_back(t);
            }
		}
		mp[pre[i]]=i;
    }
    printf("%d\n",(int)vec.size());
    return 0;
}

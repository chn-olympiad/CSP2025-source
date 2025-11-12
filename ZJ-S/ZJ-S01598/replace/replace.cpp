#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int n,q;
int tr[N][26][26],dep[N],sum[N],idx;

void build(int u,string s1,string s2){
    if(dep[u] == s1.size()){
        sum[u]++;
        return;
    }
    if(tr[u][s1[dep[u]] - 'a'][s2[dep[u]] - 'a']) build(tr[u][s1[dep[u]] - 'a'][s2[dep[u]] - 'a'], s1, s2);
    else{
        tr[u][s1[dep[u]] - 'a'][s2[dep[u]] - 'a'] = ++idx;
        dep[idx] = dep[u]+1;
        build(idx,s1,s2);
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        string a,b;
        cin >> a >> b;
        build(0,a,b);
    }
    for(int i = 1;i <= q;i++){
        int in = 1;
        int ans = 0;
        string a,b;
        cin >> a >> b;
        vector<int> l,nl;
        for(int j = 0;j < a.size();j++){
            l = nl;
            nl.clear();
            if(in) l.push_back(0);
            if(a[j] != b[j]) ans = 0, in = 0;
            for(auto k:l){
                if(tr[k][a[j] - 'a'][b[j] - 'a']){
                    nl.push_back(tr[k][a[j] - 'a'][b[j] - 'a']);
                    ans += sum[tr[k][a[j] - 'a'][b[j] - 'a']];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
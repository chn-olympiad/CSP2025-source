#include<bits/stdc++.h>
using namespace std;
#define hash scp
const int N=1e5+5;
const int p1 = 131;
const int p2 = 1e5 + 53;
int n,q;
int has[N][2];
int sum1[N], sum2[N];
int sz[N];
int hash(string s){
    int n = s.size(), sum = 0;
    for(int i=0;i<n;i++)
        sum = (sum * p1 + (s[i] - 'a')) % p2;
    return sum;
}
int solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), l=0, r=0;
    if(n1!=s2.size()) return 0;
    for (int i = 1; i <= n1;i++){
        sum1[i] = (sum1[i- 1] * p1 + (s1[i-1] - 'a')) % p2;
        sum2[i] = (sum2[i - 1] * p1 + (s2[i - 1] - 'a')) % p2;
        if(!l){
            if(s1[i-1]!=s2[i-1])
                l = i, r = i;
        }
        else if(s1[i-1]!=s2[i-1])
            r = i;
    }
}
string s1, s2;
vector<int> sum[N*2];
int solve0(){
    cin >> s1 >> s2;
    int n1 = s1.size();
    if(n1!=s2.size()) return 0;
    int l1, l2;
    for (int i = 0; i < n1;i++){
        if(s1[i]=='b')
            l1 = i;
        if(s2[i]=='b')
            l2 = i;
    }
    

}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> q;
    string s1,s2;
    for (int i = 1; i <= n;i++){
        cin >> s1 >> s2;
        sz[i] = s1.size();
        int pos1, pos2;
        for (int j = 0; j < sz[i];j++){
            if(s1[j]=='b') pos1 = j;
            if(s2[j]=='b') pos2 = j;
        }
    }
    string s1, s2;
    while(q--)
        cout << 0 << '\n';
    return 0;
}

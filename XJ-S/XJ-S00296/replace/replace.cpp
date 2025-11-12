#include<bits/stdc++.h>
using namespace std;
const int TAS = 2.5e6+10;
int to[TAS][26];
int fail[TAS];
vector<int> bian[TAS];
vector<tuple<int,unsigned long long,unsigned long long>> difs[TAS];
struct query{
    tuple<int,unsigned long long,unsigned long long> need;
    int to;
};
vector<query> querys[TAS];
int pcnt;
int rot;
const int N = 2e5+10;
long long ans[N];
void insert(const string &s,tuple<int,unsigned long long,unsigned long long> val){
    int now = rot;
    for(char c : s){
        c -= 'a';
        if(!to[now][c]){
            to[now][c] = ++pcnt;
        }
        now = to[now][c];
    }
    difs[now].push_back(val);
}
void build(){
    queue<int> que;
    for(int i = 0;i < 26;i++){
        if(to[rot][i]){
            que.push(to[rot][i]);
            fail[to[rot][i]] = rot;
        }else{
            to[rot][i] = rot;
        }
    }
    while(que.size()){
        int now = que.front();
        que.pop();
        bian[fail[now]].push_back(now);
        for(int i = 0;i < 26;i++){
            if(to[now][i]){
                que.push(to[now][i]);
                fail[to[now][i]] = to[fail[now]][i];
            }else{
                to[now][i] = to[fail[now]][i];
            }
        }
    }
}
struct ha{
    size_t operator()(tuple<int,unsigned long long,unsigned long long> val) const{   
        size_t res = get<0>(val);
        res ^= (res<<2)*0x314112312;
        res ^= (get<1>(val)>>32) ^ (get<1>(val));
        res ^= (res<<2)*0x141239081;
        res ^= (get<2>(val)>>32) ^ (get<2>(val));
        res ^= (res<<2)*0x314112312;
        return res;
    }
};
unordered_map<tuple<int,unsigned long long,unsigned long long>,int,ha> cnt;
void dfs(int x){
    for(auto val : difs[x]){
        cnt[val]++;
    }
    for(auto qu : querys[x]){
        ans[qu.to] += cnt[qu.need];
    }
    for(int v : bian[x]){
        dfs(v);
    }
    for(auto val : difs[x]){
        cnt[val]--;
    }
}
const int M1 = 13331,M2 = 131;
int read(){
    char c = getchar_unlocked();
    while(!isdigit(c)){
        c = getchar_unlocked();
    }
    int res = 0;
    while(isdigit(c)){
        res = res*10 + c - '0';
        c = getchar_unlocked();
    }
    return res;
}
string reads(){
    string res = "";
    char c = getchar_unlocked();
    while(!('a' <= c && c <= 'z')){
        c = getchar_unlocked();
    }
    while(('a' <= c && c <= 'z'))
    {
        res += c;
        c = getchar_unlocked();
    }
    return res;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n = read(),q = read();
    rot = ++pcnt;
    for(int i = 1;i <= n;i++){
        string s1 = reads(),s2 = reads();
        if(s1 == s2)continue;   // 保证了t不同，那么这样的s没有用武之地了。
        unsigned long long v1 = 0,v2 = 0;
        bool f = 0;
        int len = 0;
        for(int j = 0;j < s1.size();j++){
            f |= s1[j] != s2[j];
            if(f){
                len++;
                v1 = v1*M1 + s2[j] - 'a';
                v2 = v2*M2 + s2[j] - 'a';
            }
        }
        insert(s1,make_tuple(len,v1,v2));
    }
    build();
    for(int i = 1;i <= q;i++){
        string s1 = reads(),s2 = reads();
        bool f = 0;
        int lpos = s1.size() - 1;
        for(int j = s1.size() - 1;j >= 0;j--){
            f |= s1[j] != s2[j];
            if(f)
            {
                lpos = j;
                break;
            }
        }
        int cur = rot;
        unsigned long long v1 = 0,v2 = 0;
        f = 0;
        int len = 0;
        for(int j = 0;j < lpos;j++){
            f |= s1[j] != s2[j];
            cur = to[cur][s1[j] - 'a'];
            if(f){
                len++;
                v1 = v1*M1 + s2[j] - 'a';
                v2 = v2*M2 + s2[j] - 'a';
            }
        }
        for(int j = lpos;j < s1.size();j++){
            cur = to[cur][s1[j] - 'a'];
            v1 = v1*M1 + s2[j] - 'a';
            v2 = v2*M2 + s2[j] - 'a';
            querys[cur].push_back({make_tuple(j - lpos + 1 + len,v1,v2),i});
        }
    }
    dfs(rot);
    for(int i = 1;i <= q;i++){
        cout<<ans[i]<<'\n';
    }

}
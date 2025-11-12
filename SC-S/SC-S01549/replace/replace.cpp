#include<bits/stdc++.h>
using namespace std;
constexpr bool online=1;
#define int long long
int n,m,h2[200005],dl[200005],dr[200005],dic,ans;
vector<int>dip[200005]; map<pair<int,int>,int>did;
string t1[200005],t2[200005],s1,s2;

constexpr int p=13331,mod=998244353;
inline int gethash(const string&s){
    int v=0;
    for(const char&c:s) v=(v*p+c)%mod;
    return v;
}
int pv[5000005],hv[5000005];
inline void inith(){
    for(int i=pv[0]=1;i<=5e6;++i)
        pv[i]=pv[i-1]*p%mod;
}
inline void hashtb(const string&s){
    for(int i=0;i!=s.size();++i)
        hv[i+1]=(hv[i]*p+s[i])%mod;
}

signed main(){
    if(online)
        freopen("replace.in","r",stdin),
        freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    // time_t st=clock();
    cin>>n>>m; inith();
    /*
    (s1,s2) 能和 (t1,t2) 匹配上的一个必要条件是二者的极短差异串相同。
    在此之下，可以用哈希等技巧快速的验证一对 ((s1,s2),(t1,t2)) 是否产生贡献。
    这样直接做可以获得 50pts 的好成绩。

    我想，按照往年种满护林员，不可以总司令
    的数据强度的话，应该能够创一个更高的分数。
    开干！！！！！！

    you know what?! this passed all the big samples in less than 0.5s!!!
    */
    for(int i=1;i<=n;++i){
        cin>>t1[i]>>t2[i]; dr[i]=t1[i].size()-1;
        if(t1[i]==t2[i]) continue;
        while(t1[i][dl[i]]==t2[i][dl[i]]) dl[i]++;
        while(t1[i][dr[i]]==t2[i][dr[i]]) dr[i]--;
        s1=t1[i].substr(dl[i],dr[i]-dl[i]+1);
        s2=t2[i].substr(dl[i],dr[i]-dl[i]+1);
        int dv1=gethash(s1),dv2=gethash(s2);
        if(!did.count(make_pair(dv1,dv2)))
            did[make_pair(dv1,dv2)]=++dic;
        dip[did[make_pair(dv1,dv2)]].emplace_back(i);
        h2[i]=gethash(t2[i]);
	}
    for(int i=1;i<=m;++i){
        cin>>s1>>s2; dl[0]=0; dr[0]=s1.size()-1;
        if(s1.size()!=s2.size()){
            cout<<"0\n"; continue;
        }
        while(s1[dl[0]]==s2[dl[0]]) dl[0]++;
        while(s1[dr[0]]==s2[dr[0]]) dr[0]--;
        t1[0]=s1.substr(dl[0],dr[0]-dl[0]+1);
        t2[0]=s2.substr(dl[0],dr[0]-dl[0]+1);
        int dv1=gethash(t1[0]),dv2=gethash(t2[0]);
        if(!did.count(make_pair(dv1,dv2))){
            cout<<"0\n"; continue;
        }
        hashtb(s2); ans=0;
        for(const int&si:dip[did[make_pair(dv1,dv2)]]){
            int lp=dl[0]-dl[si]+1,rp=lp+t2[si].size()-1;
            if(lp<=0||rp>s2.size()) continue;
            int hs=hv[rp]-hv[lp-1]*pv[rp-lp+1];
            hs=(hs%mod+mod)%mod;
            if(hs==h2[si]) ans++;
        }
        cout<<ans<<endl;
    }
//    cerr<<clock()-st<<endl<<CLOCKS_PER_SEC<<endl;
    return 0; 
}
/*
things start to become more interesting...
*/
/*
好神奇，真的考字符串了，不过你认为我会做吗？？？！！！

本质上是找出一段 y，满足 y=s1, y`=s2
观察到这道题其实有点双文本多模式串匹配的感觉。
那是不是做完了，使用一下 AC 自动机？

实则不然，没有办法高效的跳跃。
我们让两个串分开匹配。如果同时匹配到了同一对字符串，那就记录贡献。
贡献真的好记录吗？

再挖一挖性质：
当你两端都匹配上了一对字符串时，若不一样的部分在内部，那么贡献为 1。
一个字符串最多能够给单次询问带来 1 的贡献。
但是匹配上了又恰能证明这一部分不一样。
所以说匹配上了且没有贡献当且仅当长度不够长。

不太对，是时候换一个思路了。Backup 一下。
*/
//by haotian,sun
//面积luogu联系 @fkxr(uid=995934)
#include<bits/stdc++.h>
#define endl cerr<<"I love Olympiad in Informatics!\n"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
/*#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc getchar
#define pc putchar
#endif
namespace FastIO{
    void r(int &a){
        a=0;bool ok=0;char ch=gc();
        for(;ch>'9'||ch<'0';ch=gc())ok^=(ch=='-');
        for(;ch>='0'&&ch<='9';ch=gc())
            a=(a<<3)+(a<<1)+ch-'0';
        if(ok)a=-a;
    }
    void w(int a){
        if(a==0){pc('0');return;}
        int till=0;char ch[25];
        if(a<0){
            pc('-');
            for(;a;a/=10)ch[till++]=-(a%10);
        }else for(;a;a/=10)ch[till++]=a%10;
        for(;till;)pc(ch[--till]+'0');
    }
    struct FIstream{
        FIstream operator>>(int &x){r(x);return {};}
    }in;
    struct FOstream{
        FOstream operator<<(int x){w(x);return {};}
        FOstream operator<<(char ch){pc(ch);return {};}
        FOstream operator<<(string s){for(auto ch:s)pc(ch);return {};}
    }out;
}using FastIO::in;using FastIO::out;*/
namespace code{
    void Freopen(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
#define base 998244853
#define mod 2012030509
    int power(int x,int y){
        int ans=1;
        for(;y;y>>=1){
            if(y&1)ans=ans*x%mod;
            x=x*x%mod;
        }
        return ans;
    }
    int pw[5000006];//,ni[5000006];
    vector<pair<pair<int,int>,int>>e[200005];int till=0;
    map<int,int>mp;
    int hs[255][255];
    int hash[5000006];
    int HS[225];
    void Main(){
        ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
        Freopen("replace");
        pw[0]=1;
        for(int i=1;i<=5000000;i++)pw[i]=pw[i-1]*base%mod;
        /*ni[5000000]=power(pw[5000000],mod-2);
        for(int i=5000000-1;~i;i--)ni[i]=ni[i+1]*base%mod;*/
        mt19937 rd(mod);
        for(int i='a';i<='z';i++){
            for(int j='a';j<='z';j++)
                hs[i][j]=rd()%base;
            HS[i]=hs[i][i];
        }
        int n,q;cin>>n>>q;
        for(;n--;){
            string s,t;cin>>s>>t;
            if(s==t)continue;
            int x=0,y=s.size()-1;
            for(;s[x]==t[x];++x);
            for(;s[y]==t[y];--y);
            int hash1=0;
            for(auto i:s)hash1=(hash1*base+HS[i])%mod;
            int hash2=0;
            for(int i=x;i<=y;i++)hash2=(hash2*base+hs[s[i]][t[i]])%mod;
            if(!mp[hash2]){
                hash2=mp[hash2]=++till;
            }else hash2=mp[hash2];
            e[hash2].push_back({{x,(int)s.size()},hash1});
        }
        for(;q--;){
            string s,t;cin>>s>>t;
            int x=0,y=s.size()-1;
            for(;s[x]==t[x];++x);
            for(;s[y]==t[y];--y);int hash2=0;
            for(int i=x;i<=y;i++)hash2=(hash2*base+hs[s[i]][t[i]])%mod;
            if(mp.find(hash2)==mp.end()){
                cout<<"0\n";
                continue;
            }else hash2=mp[hash2];
            for(int i=0;i<s.size();i++)
                hash[i+1]=(hash[i]*base+HS[s[i]])%mod;
            int ans=0;
            for(auto i:e[hash2]){
                int lenq=i.first.first,hs=i.second,len=i.first.second;
                int l=x-lenq,r=l+len-1;++l,++r;
                if(l<=0||r>s.size())continue;
                //cout<<l<<" "<<r<<"\n";
                int hasht=(hash[r]-hash[l-1]*pw[len])%mod;
                hasht=(hasht+mod)%mod;
                if(hasht==hs)++ans/*,endl*/;
            }
            cout<<ans<<"\n";
        }
    }
}
signed main(){
    code::Main();
    return 0;
}
/*
zjojxhmkzosbfsrzoytcbjmouamvjtearyierexqrvbwtiu yucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrp sndwydcdsptolyoikshfbftmbyhqitcpgxvv 
zjojxhmkzosbfsrzoytcbjmouamvjtearyierexqrvbwtin hvarpmcurogqsjnsymlzdmvilobyooplzkfvkhegxzrvcygauplfuyfkyakftyyxdsdsw sndwydcdsptolyoikshfbftmbyhqitcpgxvv
*/
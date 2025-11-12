//by haotian,sun
//面积luogu联系 @fkxr(uid=995934)
#include<bits/stdc++.h>
#define endl cerr<<"I love Olympiad in Informatics!\n"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#ifdef __linux__
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
}using FastIO::in;using FastIO::out;
namespace code{
    void Freopen(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
    int a[100005][3];
    bool cmp(pair<int,int>x,pair<int,int>y){
        return x.second-x.first<y.second-y.first;
    }
    void Main(){
        Freopen("club");
        int T;in>>T;
        for(;T--;){
            //endl;
            int n;in>>n;
            int ans=0;
            vector<pair<int,int>>e[5];
            for(int i=1;i<=n;i++){
                in>>a[i][0]>>a[i][1]>>a[i][2];
                int maxid=0;
                if(a[i][1]>a[i][maxid])maxid=1;
                if(a[i][2]>a[i][maxid])maxid=2;
                int midid=(maxid+1)%3;
                if(maxid!=0&&a[i][0]>a[i][midid])midid=0;
                if(maxid!=1&&a[i][1]>a[i][midid])midid=1;
                if(maxid!=2&&a[i][2]>a[i][midid])midid=2;
                //out<<maxid<<" "<<midid<<"\n";
                e[maxid].push_back(make_pair(a[i][maxid],a[i][midid]));
            }
            sort(all(e[0]),cmp);
            sort(all(e[1]),cmp);
            sort(all(e[2]),cmp);
            for(int i=0;i<3;i++){
                for(int j=0;j<n/2&&j<e[i].size();j++)ans+=e[i][j].first;
                for(int j=n/2;j<e[i].size();j++)ans+=e[i][j].second;
            }
            out<<ans<<"\n";
        }
    }
}
signed main(){
    code::Main();
    return 0;
}
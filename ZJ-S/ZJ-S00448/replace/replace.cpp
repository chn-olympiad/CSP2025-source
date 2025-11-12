#include <bits/stdc++.h>
using namespace std;

#define int long long
#define spa putchar(' ')
#define ero putchar('\n')
#define pii pair<int,int>
#define fi first
#define se second

const int N=1e5+10;

#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n";

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(!x)putchar('0');
    if(x<0){putchar('-'),x=-x;}
    int a[60],cnt=0;
    while(x){a[++cnt]=x%10;x/=10;}
    while(cnt--){putchar(a[cnt+1]+48);}
}

int n;
string s[N][3];
string t[3];

void solve(){
    int n=read(),q=read();
    for(int i=1;i<=n;i++){
        cin>>s[i][1];
        cin>>s[i][2];
        // cout<<s[i][1]<<"!\n";
        // cout<<s[i][2]<<"!\n";
    }
// debug
    while(q--){
        // debug;
        int ans=0;
        cin>>t[1];
        // cout<<t[1]<<"!\n";
        // debug;
        cin>>t[2];
        // cout<<t[2]<<"!\n";
        // debug
        for(int i=1;i<=n;i++){
        // cout<<__LINE__<<" "<<__FUNCTION__<<"\n";
        // debugs[is[]]
        if(t[1].size()<s[i][1].size())continue;
        // cout<<t[1].size()<<" "<<s[i][1].size()<<" ";
            for(int j=0;j<=t[1].size()-s[i][1].size();j++){
                // debug
                string ss="";
                for(int k=0;k<min((int)t[1].size()-j,(int)s[i][1].size());k++){
                    ss+=t[1][j+k];
                    // cout<<j+k<<" ";
                    // putchar(t[1][j+k]);
                    // debug
                }
                // ero;
                // cout<<"SS: "<<ss<<"\n";
                if(ss==s[i][1]){
                    // debug
        // cout<<__LINE__<<" "<<__FUNCTION__<<"\n";
                    string str="";
                    for(int k=0;k<t[1].size();k++){
                        if(k>=j&&k<j+s[i][1].size()){
                            str+=s[i][2];
                            k=j+s[i][1].size()-1;
                            continue;
                        }
                        str+=t[1][k];
                    }
                    // cout<<str<<"  str!\n";
                    if(str==t[2]){
                        ans++;
                    }
                }
            }
        // cout<<__LINE__<<" "<<__FUNCTION__<<"\n";
        }
        // cout<<"ANS:";
        write(ans);ero;
    }
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // int T=read();
    int T=1;
    while(T--){solve();}
    return 0;
}
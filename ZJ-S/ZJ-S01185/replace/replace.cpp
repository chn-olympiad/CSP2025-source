#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef unsigned long long ull;

ll read(){
    ll w=1,c,ret;
    while((c=getchar())<'0'||c>'9') w=(c=='-'?-1:1);
    ret=c-48;
    while((c=getchar())>='0'&&c<='9') ret=ret*10+c-48;
    return w*ret;
}

bool st;

int const maxn=2e5+5,maxl=5e6+5;
int n,q;

mt19937 sj(time(0));

ull B1;
ull const B2=131;
ull const B3=171;

struct info{
    ull h1,h2,h3;
    int len;
};

vector<info> s1[maxn];
vector<info> s2[maxn];

string t1,t2;

ull h1,h2,h3,h4,h5,h6;

ull hh1[maxl],hh2[maxl],hh3[maxl];
ull hh4[maxl],hh5[maxl],hh6[maxl];

bool ed;

ull qpow(ull a,ll b){
    ull s=1;
    while(b){
        if(b&1) s=s*a;
        b>>=1;
        a=a*a;
    }
    return s;
}
vector<ull> vec1;
vector<ull> vec2;
vector<ull> vec3;
vector<ull> vec4;
vector<ull> vec5;
vector<ull> vec6;
int main(){
     freopen("replace.in","r",stdin);
     freopen("replace.ans","w",stdout);
   // printf("%.2f",(&st-&ed)/1024.0/1024.0);
    n=read(),q=read();
    B1=abs((int)sj())%2000+30;
    for(int i=1;i<=n;i++){
        cin>>t1>>t2;
        h1=h2=h3=0;
        int len=t1.length();
        for(int i=0;i<len;i++){
            h1=h1*B1+t1[i]-'a'+1;
            h2=h2*B2+t1[i]-'a'+1;
        }
        h4=h5=h6=0;
        for(int i=0;i<len;i++){
            h4=h4*B1+t2[i]-'a'+1;
            h5=h5*B2+t2[i]-'a'+1;

        }
        vec1.push_back(h1);
        vec2.push_back(h2);

        vec4.push_back(h4);
        vec5.push_back(h5);
     //   cout<<h1<<' '<<h4<<'\n';
    }

    for(int j=1;j<=q;j++){
        cin>>t1>>t2;
        int len=t1.length();
        t1='0'+t1;
        t2='0'+t2;
        for(int i=1;i<=len;i++){
            hh1[i]=hh1[i-1]*B1+t1[i]-'a'+1;
            hh2[i]=hh2[i-1]*B2+t1[i]-'a'+1;
        }
        for(int i=1;i<=len;i++){
            hh4[i]=hh4[i-1]*B1+t2[i]-'a'+1;
            hh5[i]=hh5[i-1]*B2+t2[i]-'a'+1;
        }
        int l=0,r=len+1;
        for(int i=1;i<=len;i++){
            if(t1[i]==t2[i]) l=i;
            else break;
        }
        for(int i=len;i>=1;i--){
            if(t1[i]==t2[i]) r=i;
            else break;
        }
        ll ans=0;
        l++;
        r--;
        for(int L=l;L>=1;L--){
            for(int R=r;R<=len;R++){
                h1=hh1[R]-hh1[L-1]*qpow(B1,R-L+1);
                h2=hh2[R]-hh2[L-1]*qpow(B2,R-L+1);

                h4=hh4[R]-hh4[L-1]*qpow(B1,R-L+1);
                h5=hh5[R]-hh5[L-1]*qpow(B2,R-L+1);
                // cout<<h1<<' '<<h4<<'\n';
    //			 cout<<L<<' '<<R<<" "<<h1<<" "<<h4<<'\n';
//			
//				if(mp2[h2]==h5){
//                    ans++;
//                }
//				
                for(int j=0;j<n;j++){
                    if(vec1[j]==h1&&vec4[j]==h4&&vec2[j]==h2&&vec5[j]==h5) ans++;
                }
            }
        }
        cout<<ans<<'\n';
    
        
    }

    return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/
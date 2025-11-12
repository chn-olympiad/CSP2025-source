#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using std::cin;
typedef unsigned long long ull;
const int maxn=220000;
const int maxlen=5500000;
const int maxd=2;
const ull B[maxd]={73, 97};
const ull P[maxd]={998244353, 1000000007};
ull Bm[maxlen][maxd];
ull GetHash(std::string &s, ull b, ull p){
    ull res=0;
    int size=s.size();
    for(int i=0;i<size;i++)
        res=(res*b+s[i]-'a'+7)%p;
    return res;
}
int n,q;
std::string s1[maxn],s2[maxn];
std::string t1[maxn],t2[maxn];
ull hs1[maxn][maxd],hs2[maxn][maxd];
ull ht1[maxlen][maxd];//,ht2[maxlen][maxd];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    for(int d=0;d<maxd;d++){
        Bm[0][d]=1;
        for(int i=1;i<maxlen-1000;i++)
            Bm[i][d]=(Bm[i-1][d]*B[d])%P[d];
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for(int d=0;d<maxd;d++){
            hs1[i][d]=GetHash(s1[i],B[d],P[d]);
            hs2[i][d]=GetHash(s2[i],B[d],P[d]);
            // printf("%llu %llu\n",hs1[i][d],hs2[i][d]);
        }
        // printf("\n");
    }
    for(int i=1;i<=q;i++){
        long long ans=0;
        cin>>t1[i]>>t2[i];
        int size=t1[i].size();
        for(int d=0;d<maxd;d++)
            ht1[0][d]=(t1[i])[0]-'a'+7;
        for(int j=1;j<size;j++){
            for(int d=0;d<maxd;d++){
                ht1[j][d]=(ht1[j-1][d]*B[d]+(t1[i])[j]-'a'+7)%P[d];
                // printf("%llu ",ht1[j][d]);
            }//printf("\n");
        }
        ull hasht2[maxd];
        for(int d=0;d<maxd;d++)
            hasht2[d]=GetHash(t2[i],B[d],P[d]);
        // size=t2[i].size();
        // for(int j=0;j<size;j++)
        //     for(int d=0;d<maxd;d++)
        //         ht2[j][d]=(ht2[j][d]*B[d]+(t2[i])[j]-'a'+7)%P[d];
        
        // size=t1[i].size();
        for(int j=0;j<size;j++){
            if(j>0)
                if((t1[i])[j-1]!=(t2[i])[j-1])
                    break;
            for(int si=1;si<=n;si++){
                int s2size=s2[si].size();
                if(j+s2size>size) continue;

                int flag1=0,flag2=0;
                for(int d=0;d<maxd;d++){
                    ull hash=0;
                    hash=ht1[j+s2size-1][d];
                    if(j>0) hash=(hash-((ht1[j-1][d]*Bm[s2size][d])%P[d])+100*P[d])%P[d];
                    // printf("%d %d : %d %d %d : %llu %llu\n",i,si,j,j+s2size-1,d,hash,hs1[si][d]);
                    if(hash==hs1[si][d]) flag1++;
                    else break;

                    hash=0;
                    hash=(ht1[size-1][d]-((ht1[j+s2size-1][d]*Bm[size-j-s2size][d])%P[d])+100*P[d])%P[d]; // last
                    if(j>0) hash=(hash+ht1[j-1][d]*Bm[size-j][d])%P[d]; // head
                    hash=(hash+hs2[si][d]*Bm[size-j-s2size][d])%P[d]; // swap
                    if(hash==hasht2[d]) flag2++;
                    else break;
                }

                if(flag1>=maxd&&flag2>=maxd)
                    ans++;
            }
        }
        printf("%lld\n",ans);
        memset(ht1,0,sizeof(ull)*(t1[i].size()+3));
        // memset(ht2,0,sizeof(ull)*(t2[i].size()+3));
    }
    return 0;
}
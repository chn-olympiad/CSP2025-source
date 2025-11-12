#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+50;
int T,n,m;
int a[N][5];
int f[205][105][105];
int cntt[N];
bool Al;
int cnt[10];
struct node{
    int p,num,cl;
    bool friend operator < (const node &A,const node &B){
        return A.num>B.num;
    }
}b[N];
bool st[N];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>T;
    while(T--){
        int ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        m=0;
        Al=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            b[++m].p=i;b[m].cl=1;cin>>b[m].num;
            a[i][1]=b[m].num;
            b[++m].p=i;b[m].cl=2;cin>>b[m].num;
            a[i][2]=b[m].num;
            b[++m].p=i;b[m].cl=3;cin>>b[m].num;
            a[i][3]=b[m].num;
            cntt[i]=a[i][1];
            if(a[i][2]!=0||a[i][3]!=0)Al=0;
            st[i]=0;
        }
        if(n<=200){
            for(int i=1;i<=n;i++){
                for(int j=0;j<=min(n/2,i);j++){
                    for(int k=0;k+j<=i&&k<=n/2;k++){
                        f[i][j][k]=0;
                        int s=i-j-k;
                        if(s<0)continue;
                        if(s>n/2)continue;
                        if(s>=1)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
                        if(j>=1)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
                        if(k>=1)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
                        ans=max(ans,f[i][j][k]);
                    }
                }
            }
        }else if(Al){
            sort(cntt+1,cntt+n+1);
            for(int i=n;i>n/2;i--)ans+=cntt[i];
        }else{
            sort(b+1,b+m+1);
            for(int i=1;i<=m;i++){
                if(st[b[i].p])continue;
                if(cnt[b[i].cl]>=n/2)continue;
                ans+=b[i].num;
                cnt[b[i].cl]++;
                st[b[i].p]=1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
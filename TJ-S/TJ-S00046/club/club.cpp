#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
int a[N][4];

int nA,nB,nC,numA,numB,numC;
int maxn;
void dfs10(int f){
    if(f>n){
        maxn=max(maxn,numA+numB+numC);
        return;
    }
    if(nA<n/2){
        nA++,numA+=a[f][1];
        dfs10(f+1);
        nA--,numA-=a[f][1];
    }
    if(nB<n/2){
        nB++,numB+=a[f][2];
        dfs10(f+1);
        nB--,numB-=a[f][2];
    }
    if(nC<n/2){
        nC++,numC+=a[f][3];
        dfs10(f+1);
        nC--,numC-=a[f][3];
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int flag=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][2]!=0||a[i][3]!=0)
                    flag=1;
            }
        if(n<=10){
            //1-4
            nA=0,
            nB=0,
            nC=0;
            numA=0,
            numB=0,
            numC=0;
            maxn=0;
            dfs10(1);
            cout<<maxn<<'\n';
        }
        
        else if(!flag){
            //12
            int b[N];
            for(int i=0;i<n;i++)
                b[i]=a[i+1][1];
            sort(b,b+n);
            int ans=0;
            for(int i=n-1;i>n-1-n/2;i--)
                ans+=b[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}

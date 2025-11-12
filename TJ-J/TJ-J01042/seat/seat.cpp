#include<bits/stdc++.h>
using namespace std;
int a[20][20],s[110],k,n,m,f,x=1;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
        if(i==1){
            f=s[i];
        }
    }
    sort(s+1,s+(n*m)+1,cmp);
    for(int i=1;i<=m;i++){
        if(k==0){
            for(int j=1;j<=n;j++){
                if(s[x]==f){
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
                else{
                    a[i][j]=s[x];
                }
                x++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(s[x]==f){
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
                else{
                    a[i][j]=s[x];
                }
                x++;
            }
        }
        k^=1;
    }
    return 0;
}

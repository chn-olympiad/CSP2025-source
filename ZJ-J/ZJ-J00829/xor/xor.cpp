#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        bool t=false;
        int ans=0;
        for(int j=i;j<=n;j++){
            int x=s[j]^s[i-1];
            if(x==k){
                ans=j;
                t=true;
                break;
            }
        }
        bool ok=true;
        for(int j=i+1;j<=ans&&ok;j++)
             for(int k=j;k<=ans&&ok;k++){
                int x=s[k]^s[j-1];
                if(x==k){
                    ok=false;
                    break;
                }
            }
        if(t==true&&ok==true){
                printf("%d %d\n",i,ans);
            sum++;
            i=ans;
        }
    }
    printf("%d",sum);
    return 0;
}

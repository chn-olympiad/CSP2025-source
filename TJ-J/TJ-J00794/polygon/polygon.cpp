#include<bits/stdc++.h>
using namespace std;

int n,a[5010],sum=0;
bool flag[5010];
int dfs(int x,int y){
    //cout<<1<<" ";
    cout<<x<<" "<<n<<" "<<y<<endl;
    if(x>n||y>n){
        return 0;
    }
    /*if(y<3){
        flag[x]=true;
        dfs[x+1,y+1];
    }*/
    else{
        int ta[5010],head=1,maxn=0;
        for(int i=1;i<=n;i++){
            if(flag[i]){
                flag[i]=false;
                ta[head]=a[i];
                head++;
                maxn+=a[i];
            }
        }
        cout<<maxn-ta[head-1]<<" "<<2*ta[head-1];
        if(maxn-ta[head-1]>2*ta[head-1]){
            sum++;
        }
        for(int i=x;i<=n;i++){
            dfs(x++,y++);
        }
        return 0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int tn=n,b=1;
    for(int i=3;i<=n;i++){
        tn=n;
        for(int j=1;j<=i;j++){
            b*=tn;
            tn--;
            b%=998244353;
        }
        sum+=b;
        b=1;
    }
    cout<<sum;
    return 0;


    for(int i=1;i<=n;i++){
        dfs(i,0);
    }
    cout<<sum;
    return 0;
}

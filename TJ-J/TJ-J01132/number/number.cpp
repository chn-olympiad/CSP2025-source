#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int p,q;
int nums=0;
int a[1000005];
int flag=1,ans=0;
int dp[1000005];
void as(int a,int b){
    int ma;
    int x=1;
    if(a>b) ma=a;
    else  ma=b;
    while(ma>0){
        nums=nums+(abs(a%2-b%2))*x;
        a=a/2;
        b=b/2;
        x*=2;
        ma/2;
    }
}
int main(){
//    freopen("xor.in","r",stdin);
//    freopen("xor.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i>=2){
            if(a[i]!=a[i-1])  flag=0;
        }
    }
    if(n==1){
        if(a[1]!=k){
            cout<<0;
            return 0;
        }else{
            cout<<1;
            return 0;
        }
    }else if(n==2){
        if(k==0){
            if(a[1]==a[2]){
                cout<<1;
                return 0;
            }
        }
        if(k==a[1]) ans++;
        if(k==a[2]) ans++;
        cout<<ans;
        return 0;

    }else
    if(k==0){
        if(flag){
            cout<<n/2;
            return 0;
        }else{
        	cout<<0;
        	return 0;
		}
    }
    /*
    for(int i=1;i<=n;i++){
        nums=0;
        as(a[i],a[i-1]);
        if(nums==k){
            dp[i]++;
            a[i]=0;
            a[i-1]=0;
        }else{
            a[i]=nums;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

        }
    }
    */
    return 0;
}


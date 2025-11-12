#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[105];
int ans=0;
bool flag=0,f01=1;
int sum=0;
void plana(){
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            ans++;
        }
    }
    cout<<ans;
}
void planb(){
    for(int i=1;i<=n;i++){
        if(a[i]==0&&flag==0){
            ans++;
        }else if(a[i]==1&&flag==1){
            flag=0;
            ans++;
        }else if(a[i]==1&&flag==0){
            flag=1;
        }else{
            if(ans%2==1)ans-=1;
            else ans+1;
        }
    }
    cout<<ans;
}
void godblessme(){
    for(int i=1;i<=n;i++){//startpoint
        for(int j=1;i+j-1<=n;j++){//long
            //cout<<j<<endl;
            sum=0;
            for(int x=0;x<j;x++){//xiabiao
                sum=(sum^a[i+x]);
            }
            if(sum==k){
                //cout<<"test:"<<sum<<endl;
                ans++;
                i=i+j-1;
                break;
            }
        }
    }
    cout<<ans;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1&&a[i]!=0){
            f01=0;
        }
    }

    if(k==1&&f01){
        plana();
    }
    else if(k==0&&f01){
        planb();
    }
    else{
        godblessme();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
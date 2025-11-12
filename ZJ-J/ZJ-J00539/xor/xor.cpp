#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum=0,t[256],f[500005];
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
        if(a[i]==k){
            sum++;
            //cout<<i<<" "<<i<<"\n";
            f[i]=1;
        }
    }
    if(n<=1000){
        for(int z=2;z<=n;z++){
            int yhh=a[1];
            for(int l=1,r=1;l<=n;l++){
                while(r<n&&r-l+1<z){
                    r++;
                    yhh^=a[r];
                }
                if(r-l+1<z) break;
                //cout<<z<<" "<<l<<" "<<r<<" "<<yhh<<"\n";
                if(yhh==k){
                    //cout<<a[l]<<" ^ "<<(yhh^a[l])<<" == "<<yhh<<"\n";
                    int flag=1;
                    for(int i=l;i<=r;i++) if(f[i]) flag=0;
                    if(flag){
                        //cout<<l<<" "<<r<<endl;
                        for(int i=l;i<=r;i++) f[i]=1;
                        sum++;
                        yhh^=a[l];
                    }
                    else{yhh^=a[l];continue;}
                }
                else{
                    //cout<<yhh<<" ^ "<<a[l]<<" == "<<(yhh^a[l])<<endl;
                    yhh^=a[l];
                }
                //cout<<1<<endl;
            }
        }
        cout<<sum;
    }
    else cout<<t[k];
}

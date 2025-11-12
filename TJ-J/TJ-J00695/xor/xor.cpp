#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+1]={},b,num=0,c=0;
    for(int i=1;i<=n;i++){
        cin>>b;
        a[i]=(b^a[i-1]);
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j<i;j++){
            if((a[i]^a[j])==k){
                c=i;
                num++;
                break;
            }
        }
    }
    cout<<num; 
    fclose(stdin);
    fclose(stdout);
    return 0;
}


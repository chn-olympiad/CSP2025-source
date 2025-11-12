#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> v(n*m);
    for(int i=0;i<n*m;i++){
        cin>>v[i];
    }
    int k=v[0];
    sort(v.begin(),v.end(),cmp);
    int i=1,j=1,l=0;
    while(j<=m){
        if(i==1){
            while(i<=n){
                if(v[l]==k){
                    cout<<j<<" "<<i;
                    return 0;
                }
                i++;
                l++;
            }
            i=n;
        }
        else if(i==n){
            while(i>=1){
                if(v[l]==k){
                    cout<<j<<" "<<i;
                    return 0;
                }
                i--;
                l++;
            }
            i=1;
        }
        j++;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

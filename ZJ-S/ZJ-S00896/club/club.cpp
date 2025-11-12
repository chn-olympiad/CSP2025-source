#include <bits/stdc++.h>
using namespace std;
const int MN=1e5+5;
int n,a[MN][4],s[MN],cnt[3];
int mdl(int aa,int bb,int cc){
    int mid;
    if((aa>=bb&&bb>=cc)||(cc>=bb&&bb>=aa)) return bb;
     else if((aa>=cc&&cc>=bb)||(bb>=cc&&cc>=aa)) return cc;
     else return aa;   
}
void swp(int i,int j){
    swap(a[i][0],a[j][0]);
    swap(a[i][1],a[j][1]);
    swap(a[i][2],a[j][2]);
    swap(a[i][3],a[j][3]);
    swap(s[i],s[j]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int n2=n/2,vl=0;
        cnt[0]=0;
        cnt[1]=0;
        cnt[2]=0;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            a[i][3]=max(a[i][0],max(a[i][1],a[i][2]));
            s[i]=a[i][3]-mdl(a[i][0],a[i][1],a[i][2]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i]<s[j]) swp(i,j);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i][0]==a[i][3]){
                if(cnt[0]<n2){
                    cnt[0]++;
                    vl+=a[i][0];
                }else{
                    vl+=a[i][3]-s[i];
                }
            }else{
                if(a[i][1]==a[i][3]){
                    if(cnt[1]<n2){
                        cnt[1]++;
                        vl+=a[i][1];
                    }else{
                        vl+=a[i][3]-s[i];
                    }
                }else{
                    if(cnt[2]<n2){
                        cnt[2]++;
                        vl+=a[i][2];
                    }else{
                        vl+=a[i][3]-s[i];
                    }
                }
            }
        }
        cout<<vl<<endl;
    }
    return 0;
}
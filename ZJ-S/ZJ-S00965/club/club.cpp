#include<bits/stdc++.h>
using namespace std;
int t, x, y, z;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--){
        bool b1=0, b2=0, b3=0;
        long long ans=0;
        int n;
        cin>>n;
        vector<int> a1(n), a2(n), a3(n), a4(n), a5(n), a6(n), a7(n), a8(n), a9(n);
        for(int i=0; i<n; i++){
            vector<int> rank(3);
            for(int j=0; j<3; j++){
                cin>>rank[j];
            } int cmp=0, pos;
            for(int j=0; j<3; j++){
                if(rank[j]>cmp){
                    cmp=rank[j];
                    pos=j;
                }
            } if(pos==0) x++;
            else if(pos==1) y++;
            else z++;
            a1[i]=rank[0];
            a2[i]=rank[1];
            a3[i]=rank[2];
            a4[i]=rank[0];
            a5[i]=rank[1];
            a6[i]=rank[2];
            a7[i]=rank[0];
            a8[i]=rank[1];
            a9[i]=rank[2];
        } vector<int> r(3);
        
        r[0]=x, r[1]=y, r[2]=z;
        sort(r.begin(), r.end(), greater<int>());
        if(r[0]==x){
            
            b1=1;
            sort(a1.begin(), a1.end(), greater<int>());
            int maxn=n/2;
            for(int i=0; i<maxn; i++){
                ans+=a1[i];
            }
            for(int i=0; i<maxn; i++){
                int tpos=find(a4.begin(), a4.end(), a1[i])-a4.begin();
                a4[tpos]=0;
                a5[tpos]=0;
                a6[tpos]=0;
            }
        }else if(r[0]==y){
            
            b2=1;
            sort(a2.begin(), a2.end(), greater<int>());
            int maxn=n/2;
            for(int i=0; i<maxn; i++){
                ans+=a2[i];
            }for(int i=0; i<maxn; i++){
                int tpos=find(a5.begin(), a5.end(), a1[i])-a5.begin();
                a4[tpos]=0;
                a5[tpos]=0;
                a6[tpos]=0;
            }
        }else if(r[0]==z){
            
            b3=1;
            sort(a3.begin(), a3.end(), greater<int>());
            int maxn=n/2;
            for(int i=0; i<maxn; i++){
                ans+=a3[i];
            }for(int i=0; i<maxn; i++){
                int tpos=find(a6.begin(), a6.end(), a1[i])-a6.begin();
                a4[tpos]=0;
                a5[tpos]=0;
                a6[tpos]=0;
            }
        }
        if(r[1]==x){
            if(!b1){
                sort(a4.begin(), a4.end(), greater<int>());
                int maxn=n/4;
                for(int i=0; i<maxn; ++i){
                    ans+=a4[i];
                }for(int i=0; i<maxn; i++){
                    int tpos=find(a7.begin(), a7.end(), a4[i])-a7.begin();
                    a7[tpos]=0;
                    a8[tpos]=0;
                    a9[tpos]=0;
                }
            }
        }else if(r[1]==y){
            if(!b2){
                b2=1;
                sort(a5.begin(), a5.end(), greater<int>());
                int maxn=n/4;
                for(int i=0; i<maxn; ++i){
                    ans+=a5[i];
                }for(int i=0; i<maxn; i++){
                    int tpos=find(a8.begin(), a8.end(), a5[i])-a8.begin();
                    a7[tpos]=0;
                    a8[tpos]=0;
                    a9[tpos]=0;
                }
            }
        }else if(r[1]==z){
            if(!b3){
                b3=1;
                sort(a6.begin(), a6.end(), greater<int>());
                int maxn=n/4;
                for(int i=0; i<maxn; ++i){
                    ans+=a6[i];
                }for(int i=0; i<maxn; i++){
                    int tpos=find(a9.begin(), a9.end(), a6[i])-a9.begin();
                    a7[tpos]=0;
                    a8[tpos]=0;
                    a9[tpos]=0;
                }
            }
        }
        if(r[2]==x){
            if(!b1){
                b1=1;
                sort(a7.begin(), a7.end(), greater<int>());
                int maxn=n/8;
                if(maxn<0) ans+=a7[0];
                else{for(int i=0; i<maxn; ++i){
                    ans+=a7[i];
                }}
            }
        }else if(r[2]==y){
            if(!b2){
                b2=1;
                sort(a8.begin(), a8.end(), greater<int>());
                int maxn=n/8;
                if(maxn<0) ans+=a8[0];
                else{for(int i=0; i<maxn; ++i){
                    ans+=a8[i];
                }}
            }
        }else if(r[2]==z){
            if(!b3){
                b3=1;
                sort(a9.begin(), a9.end(), greater<int>());
                int maxn=n/8;
                if(maxn<0) ans+=a7[0];
                else{for(int i=0; i<maxn; ++i){
                    ans+=a9[i];
                }}
            }
        } 
        for(int i=0; i<n; i++){
            //cout<<i<<endl;
            //cout<<a1[i]<<" "<<a5[i]<<" "<<a9[i]<<" "<<endl;
        }
        cout<<ans<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
long long cl1[100005],cl2[100005],cl3[100005];
long long t,n,ans=0;
long long c1[100005],c2[100005],c3[100005];
long long c11=0,c22=0,c33=0;
long long a01,b01,c01,a02,b02,c02;
long long ansss[10];
long long ano[100005];
bool flag=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;

        if(n==2){
            cin>>a01>>b01>>c01;
            cin>>a02>>b02>>c02;
            ansss[1]=a01+b02;
            ansss[2]=a01+c02;
            ansss[3]=b01+a02;
            ansss[4]=b01+c02;
            ansss[5]=c01+a02;
            ansss[6]=c01+b02;
            sort(ansss+1,ansss+7);
            cout<<ansss[6];
            return 0;
        }


        for(int i=1;i<=n;i++){
            cin>>cl1[i]>>cl2[i]>>cl3[i];
            if(cl2[i]==0&&cl3[i]==0) ano[i]=cl1[i];
            else flag=0;
            if(cl1[i]>=cl2[i]&&cl1[i]>=cl3[i]){ //1max
                if(c11+1<=n/2){
                    ans+=cl1[i];
                    c11++;
                    c1[c11]=cl1[i];
                    sort(c1+1,c1+1+c11);
                }else{
                    sort(c1+1,c1+1+c11);
                    if(cl1[i]>c1[1]){
                        ans+=cl1[i];
                        ans-=c1[1];
                        c1[1]=cl1[i];
                        sort(c1+1,c1+1+c11);
                    }else if(cl2[i]>=cl3[i]){
                        if(c22+1<=n/2){
                            ans+=cl2[i];
                            c22++;
                            c2[c22]=cl2[i];
                            sort(c2+1,c2+1+c22);
                        }else if(cl2[i]>c2[1]){
                            ans+=cl2[i];
                            ans-=c2[1];
                            c2[1]=cl2[i];
                            sort(c2+1,c2+1+c22);
                        }else{
                            ans+=cl3[i];
                            c33++;
                            c3[c33]=cl3[i];
                            sort(c3+1,c3+1+c33);
                        }
                    }else{
                        if(c33+1<=n/2){
                            ans+=cl3[i];
                            c33++;
                            c3[c33]=cl3[i];
                            sort(c3+1,c3+1+c33);
                        }else if(cl3[i]>c3[1]){
                            ans+=cl3[i];
                            ans-=c3[1];
                            c3[1]=cl3[i];
                            sort(c3+1,c3+1+c33);
                        }else{
                            ans+=cl2[i];
                            c22++;
                            c2[c22]=cl2[i];
                            sort(c2+1,c2+1+c22);
                        }
                    }
                }
            }
            if(cl2[i]>=cl1[i]&&cl2[i]>=cl3[i]){ //2max
                if(c22+1<=n/2){
                    ans+=cl2[i];
                    c22++;
                    c2[c22]=cl2[i];
                    sort(c2+1,c2+1+c22);
                }else{
                    sort(c2+1,c2+1+c22);
                    if(cl2[i]>c2[1]){
                        ans+=cl2[i];
                        ans-=c2[1];
                        c2[1]=cl2[i];
                        sort(c2+1,c2+1+c22);
                    }else if(cl1[i]>=cl3[i]){
                        if(c11+1<=n/2){
                            ans+=cl1[i];
                            c11++;
                            c1[c11]=cl1[i];
                            sort(c1+1,c1+1+c11);
                        }else if(cl1[i]>c1[1]){
                            ans+=cl1[i];
                            ans-=c1[1];
                            c1[1]=cl1[i];
                            sort(c1+1,c1+1+c11);
                        }else{
                            ans+=cl3[i];
                            c33++;
                            c3[c33]=cl3[i];
                            sort(c3+1,c3+1+c33);
                        }
                    }else{
                        if(c33+1<=n/2){
                            ans+=cl3[i];
                            c33++;
                            c3[c33]=cl3[i];
                            sort(c3+1,c3+1+c33);
                        }else if(cl3[i]>c3[1]){
                            ans+=cl3[i];
                            ans-=c3[1];
                            c3[1]=cl3[i];
                            sort(c3+1,c3+1+c33);
                        }else{
                            ans+=cl1[i];
                            c11++;
                            c1[c11]=cl1[i];
                            sort(c1+1,c1+1+c11);
                        }
                    }
                }
            }
            if(cl3[i]>=cl1[i]&&cl3[i]>=cl2[i]){ //3max
                if(c33+1<=n/2){
                    ans+=cl3[i];
                    c33++;
                    c3[c33]=cl3[i];
                    sort(c3+1,c3+1+c33);
                }else{
                    sort(c3+1,c3+1+c33);
                    if(cl3[i]>c3[1]){
                        ans+=cl3[i];
                        ans-=c3[1];
                        c3[1]=cl3[i];
                        sort(c3+1,c3+1+c33);
                    }else if(cl1[i]>=cl2[i]){
                        if(c11+1<=n/2){
                            ans+=cl1[i];
                            c11++;
                            c1[c11]=cl1[i];
                            sort(c1+1,c1+1+c11);
                        }else if(cl1[i]>c1[1]){
                            ans+=cl1[i];
                            ans-=c1[1];
                            c1[1]=cl1[i];
                            sort(c1+1,c1+1+c11);
                        }else{
                            ans+=cl2[i];
                            c22++;
                            c2[c22]=cl2[i];
                            sort(c2+1,c2+1+c22);
                        }
                    }else{
                        if(c22+1<=n/2){
                            ans+=cl2[i];
                            c22++;
                            c2[c22]=cl2[i];
                            sort(c2+1,c2+1+c22);
                        }else if(cl2[i]>c2[1]){
                            ans+=cl2[i];
                            ans-=c2[1];
                            c2[1]=cl2[i];
                            sort(c2+1,c2+1+c22);
                        }else{
                            ans+=cl1[i];
                            c11++;
                            c1[c11]=cl1[i];
                            sort(c1+1,c1+1+c11);
                        }
                    }
                }
            }
        }
        if(flag){
            ans=0;
            sort(ano+1,ano+1+n,cmp);
            for(int j=1;j<=n/2;j++){
                ans+=ano[j];
            }
        }
        cout<<ans<<endl;
        ans=0;
        c1[100005]={},c2[100005]={},c3[100005]={};
        c11=0,c22=0,c33=0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][4];
int f[100005],p[100005],s[100005];
int sp[100005];
int c1=0,c2=0,c3=0;
int ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        c1=0,c2=0,c3=0;
        ans=0;
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        memset(p,0,sizeof(p));
        memset(s,0,sizeof(s));
        memset(sp,0,sizeof(sp));
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
                    f[i]=1;
                    p[i]=a[i][1]-max(a[i][2],a[i][3]);
                    s[i]=a[i][1];
                    c1++;
                    ans+=s[i];
            }
            else  if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
                    f[i]=2;
                    p[i]=a[i][2]-max(a[i][1],a[i][3]);
                    s[i]=a[i][2];
                    c2++;
                    ans+=s[i];
            }
            else  if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) {
                    f[i]=3;
                    p[i]=a[i][3]-max(a[i][1],a[i][2]);
                    s[i]=a[i][3];
                    c3++;
                    ans+=s[i];
            }
        }
        if(c1>n/2){
            int k=1;
            for(int i=1;i<=n;i++){
                if(f[i]==1){
                    sp[k]=p[i];
                    k++;
                }
            }
            sort(sp+1,sp+k);
  //          for(int i=1;i<k;i++) printf("%d\n",sp[i]);
    //        cout<<endl;
            for(int i=1;i<=c1-n/2;i++){

                ans=ans-sp[i];
            }
        }
        else if(c2>n/2){
            int k=1;
            for(int i=1;i<=n;i++){
                if(f[i]==2){

                    sp[k]=p[i];
                    k++;
                }
            }
            sort(sp+1,sp+k);
   //         for(int i=1;i<k;i++) printf("%d\n",sp[i]);
     //       cout<<endl;
            for(int i=1;i<=c2-n/2;i++){
                ans=ans-sp[i];
            }
        }
        else if(c3>n/2){
            int k=1;
            for(int i=1;i<=n;i++){
                if(f[i]==3){
                    sp[k]=p[i];
                    k++;
                }
            }
            sort(sp+1,sp+k);
   //         for(int i=1;i<k;i++) printf("%d\n",sp[i]);
     //       cout<<endl;
            for(int i=1;i<=c3-n/2;i++){
                ans=ans-sp[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

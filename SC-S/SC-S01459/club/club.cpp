#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+500;
int t,n;
int a[MAXN],b[MAXN],c[MAXN];
int z[MAXN];
struct A{
    int a,id;
    operator <(const A l){
        return a>l.a;
    }
}a11[MAXN];
struct B{
    int b,id;
    operator <(const B l){
        return b>l.b;
    }
}b11[MAXN];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int x=0,y=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0||c[i]!=0){
                x=1;
            }
            if(c[i]!=0){
                y=1;
            }
            a11[i].a=a[i],a11[i].id=i;
            b11[i].b=b[i],b11[i].id=i;
        }
        if(n==2){
            if(a[1]==max(a[1],max(b[1],c[1]))&&a[2]==max(a[2],max(b[2],c[2]))){
                cout<<max(a[1]+max(b[2],c[2]),a[2]+max(b[1],c[1]));
            }else if(b[1]==max(a[1],max(b[1],c[1]))&&b[2]==max(a[2],max(b[2],c[2]))){
                cout<<max(b[1]+max(a[2],c[2]),b[2]+max(a[1],c[1]));
            }else if(c[1]==max(a[1],max(b[1],c[1]))&&c[2]==max(a[2],max(b[2],c[2]))){
                cout<<max(c[1]+max(b[2],a[2]),c[2]+max(b[1],a[1]));
            }else{
                cout<<max(a[1],max(b[1],c[1]))+max(a[2],max(b[2],c[2]));
            }
            cout<<endl;
            continue;
        }
        if(x==0){
            sort(a+1,a+1+n);
            int ans=0;
            for(int i=n;i>n/2;i++){
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        }
        if(y==0){
            int ans=0;
            sort(a11+1,a11+1+n);
            sort(b11+1,b11+1+n);
            for(int i=n;i>n/2;i--){
                z[a11[i].id]++;
                z[b11[i].id]++;
                ans+=a11[i].a;
                ans+=b11[i].b;
            }
            for(int i=n;i>=1;i--){
                if(z[a11[i].id]==2){
                    z[a11[i].id]--;
                    int sun;
                    int num;
                    for(int j=i-1;i>=1;j--){
                        if(z[a11[j].id]==0){
                            sun==a11[j].id;
                            break;
                        }
                    }
                    for(int j=i-1;i>=1;j--){
                        if(z[b11[j].id]==0){
                            num=b11[j].id;
                            break;
                        }
                    }
                    if(a11[i].a-a11[sun].a>b11[i].b-b11[num].b){
                        z[num]=1;
                        ans-=abs(b11[i].b-b11[num].b);
                    }else{
                        z[sun]=1;
                        ans-=abs(a11[i].a-a11[sun].a);
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
//10

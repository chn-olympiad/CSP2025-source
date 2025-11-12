#include<bits/stdc++.h>
using namespace std;
#define modd 998244353
int n,ans;
int a[501000],maxx,sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n<3){
        cout<<0<<endl;
    }else if(n==3){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx = max(maxx,a[i]);
            sum+=a[i];
        }
        if(sum>2*maxx){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }else if(n==4){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx = max(maxx,a[i]);
            sum+=a[i];
        }
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    int su = a[i]+a[j]+a[k];
                    int ma = max({a[i],a[j],a[k]});
                    if(su>2*ma){
                        ans++;
                    }
                }
            }
        }
        if(sum>2*maxx){
            cout<<ans+1<<endl;
        }else{
            cout<<ans<<endl;
        }

    }else if(n==5){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx = max(maxx,a[i]);
            sum+=a[i];
        }
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    int su = a[i]+a[j]+a[k];
                    int ma = max({a[i],a[j],a[k]});
                    if(su>2*ma){
                        ans++;
                    }
                }
            }
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=j+1;k<=n-1;k++){
                    for(int o=k+1;o<=n;o++){
                        int su = a[i]+a[j]+a[k]+a[o];
                        int ma = max({a[i],a[j],a[k],a[o]});
                        if(su>2*ma){
                            ans++;
                        }
                    }
                }
            }
        }
        if(sum>2*maxx){
            cout<<ans+1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }else if(n==6){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx = max(maxx,a[i]);
            sum+=a[i];
        }
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    int su = a[i]+a[j]+a[k];
                    int ma = max({a[i],a[j],a[k]});
                    if(su>2*ma){
                        ans++;
                    }
                }
            }
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=j+1;k<=n-1;k++){
                    for(int o=k+1;o<=n;o++){
                        int su = a[i]+a[j]+a[k]+a[o];
                        int ma = max({a[i],a[j],a[k],a[o]});
                        if(su>2*ma){
                            ans++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                for(int k=j+1;k<=n-2;k++){
                    for(int o=k+1;o<=n-1;o++){
                        for(int q=o+1;q<=n;q++){
                            int su = a[i]+a[j]+a[k]+a[o];
                            int ma = max({a[i],a[j],a[k],a[o]});
                            if(su>2*ma){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        if(sum>2*maxx){
            cout<<ans+1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }else if(n==7){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx = max(maxx,a[i]);
            sum+=a[i];
        }
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    int su = a[i]+a[j]+a[k];
                    int ma = max({a[i],a[j],a[k]});
                    if(su>2*ma){
                        ans++;
                    }
                }
            }
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=j+1;k<=n-1;k++){
                    for(int o=k+1;o<=n;o++){
                        int su = a[i]+a[j]+a[k]+a[o];
                        int ma = max({a[i],a[j],a[k],a[o]});
                        if(su>2*ma){
                            ans++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                for(int k=j+1;k<=n-2;k++){
                    for(int o=k+1;o<=n-1;o++){
                        for(int q=o+1;q<=n;q++){
                            int su = a[i]+a[j]+a[k]+a[o];
                            int ma = max({a[i],a[j],a[k],a[o]});
                            if(su>2*ma){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-5;i++){
            for(int j=i+1;j<=n-4;j++){
                for(int k=j+1;k<=n-3;k++){
                    for(int o=k+1;o<=n-2;o++){
                        for(int q=o+1;q<=n-1;q++){
                            for(int w=q+1;w<=n;w++){
                                int su = a[i]+a[j]+a[k]+a[o];
                                int ma = max({a[i],a[j],a[k],a[o]});
                                if(su>2*ma){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(sum>2*maxx){
            cout<<ans+1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }else if(n==8){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx = max(maxx,a[i]);
            sum+=a[i];
        }
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    int su = a[i]+a[j]+a[k];
                    int ma = max({a[i],a[j],a[k]});
                    if(su>2*ma){
                        ans++;
                    }
                }
            }
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=j+1;k<=n-1;k++){
                    for(int o=k+1;o<=n;o++){
                        int su = a[i]+a[j]+a[k]+a[o];
                        int ma = max({a[i],a[j],a[k],a[o]});
                        if(su>2*ma){
                            ans++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                for(int k=j+1;k<=n-2;k++){
                    for(int o=k+1;o<=n-1;o++){
                        for(int q=o+1;q<=n;q++){
                            int su = a[i]+a[j]+a[k]+a[o];
                            int ma = max({a[i],a[j],a[k],a[o]});
                            if(su>2*ma){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-5;i++){
            for(int j=i+1;j<=n-4;j++){
                for(int k=j+1;k<=n-3;k++){
                    for(int o=k+1;o<=n-2;o++){
                        for(int q=o+1;q<=n-1;q++){
                            for(int w=q+1;w<=n;w++){
                                int su = a[i]+a[j]+a[k]+a[o];
                                int ma = max({a[i],a[j],a[k],a[o]});
                                if(su>2*ma){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-6;i++){
            for(int j=i+1;j<=n-5;j++){
                for(int k=j+1;k<=n-4;k++){
                    for(int o=k+1;o<=n-3;o++){
                        for(int q=o+1;q<=n-2;q++){
                            for(int w=q+1;w<=n-1;w++){
                                for(int g=w+1;g<=n;g++){
                                    int su = a[i]+a[j]+a[k]+a[o];
                                    int ma = max({a[i],a[j],a[k],a[o]});
                                    if(su>2*ma){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(sum>2*maxx){
            cout<<ans+1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }else if(n==9){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx = max(maxx,a[i]);
            sum+=a[i];
        }
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    int su = a[i]+a[j]+a[k];
                    int ma = max({a[i],a[j],a[k]});
                    if(su>2*ma){
                        ans++;
                    }
                }
            }
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=j+1;k<=n-1;k++){
                    for(int o=k+1;o<=n;o++){
                        int su = a[i]+a[j]+a[k]+a[o];
                        int ma = max({a[i],a[j],a[k],a[o]});
                        if(su>2*ma){
                            ans++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                for(int k=j+1;k<=n-2;k++){
                    for(int o=k+1;o<=n-1;o++){
                        for(int q=o+1;q<=n;q++){
                            int su = a[i]+a[j]+a[k]+a[o];
                            int ma = max({a[i],a[j],a[k],a[o]});
                            if(su>2*ma){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-5;i++){
            for(int j=i+1;j<=n-4;j++){
                for(int k=j+1;k<=n-3;k++){
                    for(int o=k+1;o<=n-2;o++){
                        for(int q=o+1;q<=n-1;q++){
                            for(int w=q+1;w<=n;w++){
                                int su = a[i]+a[j]+a[k]+a[o];
                                int ma = max({a[i],a[j],a[k],a[o]});
                                if(su>2*ma){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-6;i++){
            for(int j=i+1;j<=n-5;j++){
                for(int k=j+1;k<=n-4;k++){
                    for(int o=k+1;o<=n-3;o++){
                        for(int q=o+1;q<=n-2;q++){
                            for(int w=q+1;w<=n-1;w++){
                                for(int g=w+1;g<=n;g++){
                                    int su = a[i]+a[j]+a[k]+a[o];
                                    int ma = max({a[i],a[j],a[k],a[o]});
                                    if(su>2*ma){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-7;i++){
            for(int j=i+1;j<=n-6;j++){
                for(int k=j+1;k<=n-5;k++){
                    for(int o=k+1;o<=n-4;o++){
                        for(int q=o+1;q<=n-3;q++){
                            for(int w=q+1;w<=n-2;w++){
                                for(int g=w+1;g<=n-1;g++){
                                    for(int y=g+1;y<=n;y++){
                                        int su = a[i]+a[j]+a[k]+a[o];
                                        int ma = max({a[i],a[j],a[k],a[o]});
                                        if(su>2*ma){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(sum>2*maxx){
            cout<<ans+1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }else if(n==10){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx = max(maxx,a[i]);
            sum+=a[i];
        }
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    int su = a[i]+a[j]+a[k];
                    int ma = max({a[i],a[j],a[k]});
                    if(su>2*ma){
                        ans++;
                    }
                }
            }
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=j+1;k<=n-1;k++){
                    for(int o=k+1;o<=n;o++){
                        int su = a[i]+a[j]+a[k]+a[o];
                        int ma = max({a[i],a[j],a[k],a[o]});
                        if(su>2*ma){
                            ans++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                for(int k=j+1;k<=n-2;k++){
                    for(int o=k+1;o<=n-1;o++){
                        for(int q=o+1;q<=n;q++){
                            int su = a[i]+a[j]+a[k]+a[o];
                            int ma = max({a[i],a[j],a[k],a[o]});
                            if(su>2*ma){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-5;i++){
            for(int j=i+1;j<=n-4;j++){
                for(int k=j+1;k<=n-3;k++){
                    for(int o=k+1;o<=n-2;o++){
                        for(int q=o+1;q<=n-1;q++){
                            for(int w=q+1;w<=n;w++){
                                int su = a[i]+a[j]+a[k]+a[o];
                                int ma = max({a[i],a[j],a[k],a[o]});
                                if(su>2*ma){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-6;i++){
            for(int j=i+1;j<=n-5;j++){
                for(int k=j+1;k<=n-4;k++){
                    for(int o=k+1;o<=n-3;o++){
                        for(int q=o+1;q<=n-2;q++){
                            for(int w=q+1;w<=n-1;w++){
                                for(int g=w+1;g<=n;g++){
                                    int su = a[i]+a[j]+a[k]+a[o];
                                    int ma = max({a[i],a[j],a[k],a[o]});
                                    if(su>2*ma){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-7;i++){
            for(int j=i+1;j<=n-6;j++){
                for(int k=j+1;k<=n-5;k++){
                    for(int o=k+1;o<=n-4;o++){
                        for(int q=o+1;q<=n-3;q++){
                            for(int w=q+1;w<=n-2;w++){
                                for(int g=w+1;g<=n-1;g++){
                                    for(int y=g+1;y<=n;y++){
                                        int su = a[i]+a[j]+a[k]+a[o];
                                        int ma = max({a[i],a[j],a[k],a[o]});
                                        if(su>2*ma){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-8;i++){
            for(int j=i+1;j<=n-7;j++){
                for(int k=j+1;k<=n-6;k++){
                    for(int o=k+1;o<=n-5;o++){
                        for(int q=o+1;q<=n-4;q++){
                            for(int w=q+1;w<=n-3;w++){
                                for(int g=w+1;g<=n-2;g++){
                                    for(int y=g+1;y<=n-1;y++){
                                        for(int x=y+1;x<=n;x++){
                                            int su = a[i]+a[j]+a[k]+a[o];
                                            int ma = max({a[i],a[j],a[k],a[o]});
                                            if(su>2*ma){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(sum>2*maxx){
            cout<<ans+1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }

    return 0;
}

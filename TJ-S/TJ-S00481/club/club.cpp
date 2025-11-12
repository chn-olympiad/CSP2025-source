#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int ton[5];
bool vis[N];
struct Node{
    int x,id;
}a[N],b[N],c[N];
bool cmp(Node a,Node b){
    return a.x<b.x;
}
void solve(){
    memset(vis,0,sizeof(vis));
    memset(ton,0,sizeof(ton));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].x>>b[i].x>>c[i].x;
        a[i].id=i,b[i].id=i,c[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    sort(c+1,c+1+n,cmp);
    int ans=0;
    int idx1=n,idx2=n,idx3=n;
    int t1=1e18;
    bool flag=false;
    while (1){
        if (t1==ans && flag==true) break;
        else if (t1==ans) flag=true;
        t1=ans;
        if (ton[1]+1>n/2 && ton[2]+1<=n/2 && ((a[idx1].x+b[idx2].x>a[idx1+1].x+b[idx2].x && b[idx2].id!=a[idx1].id) || (a[idx1].x+b[idx2].x>a[idx1+1].x))){
            ans-=a[idx1+1].x,ans+=a[idx1].x,ans+=b[idx2].x;
            vis[a[idx1].id]=1,vis[b[idx2].id]=1;
            idx2--,idx1--;
            //cout<<"a"<<ans<<endl;
        }
        else if (ton[1]+1>n/2 && ton[3]+1<=n/2 && ((a[idx1].x+c[idx3].x>a[idx1+1].x+c[idx3].x && c[idx3].id!=a[idx1].id) || (a[idx1].x+c[idx3].x>a[idx1+1].x))){
            ans-=a[idx1+1].x,ans+=a[idx1].x,ans+=c[idx3].x;
            vis[c[idx3].id]=1,vis[a[idx1].id]=1;
            idx3--,idx1--;
            //cout<<"b"<<ans<<endl;
        }
        else if (ton[2]+1>n/2 && ton[3]+1<=n/2 && ((b[idx2].x+c[idx3].x>b[idx2+1].x+c[idx3].x && c[idx3].id!=b[idx2].id) || (b[idx2].x+c[idx3].x>b[idx2+1].x))){
            ans-=b[idx2+1].x,ans+=b[idx2].x,ans+=c[idx3].x;
            vis[c[idx3].id]=1,vis[b[idx2].id]=1;
            idx2--,idx3--;
            //cout<<"c"<<ans<<endl;
        }
        else{
            if (a[idx1].x>=b[idx2].x && a[idx1].x>=c[idx3].x && ton[1]<n/2 && !vis[a[idx1].id]){
                ans+=a[idx1].x,ton[1]++,vis[a[idx1].id]=1,idx1--;
            }
            else if (b[idx2].x>=a[idx1].x && b[idx2].x>=c[idx3].x && ton[2]<n/2 && !vis[b[idx2].id]){
                ans+=b[idx2].x,ton[2]++,vis[b[idx2].id]=1,idx2--;
            //cout<<"a2"<<endl;
            }
            else if (c[idx3].x>=a[idx1].x && c[idx3].x>=b[idx2].x && ton[3]<n/2 && !vis[c[idx3].id]){
                ans+=c[idx3].x,ton[3]++,vis[c[idx3].id]=1,idx3--;
               // cout<<"a3"<<endl;
            }
            else if (ton[1]<n/2 && ton[2]>=n/2 && ton[3]>=n/2 && !vis[a[idx1].id]){
                ans+=a[idx1].x,ton[1]++,vis[a[idx1].id]=1,idx1--;
            //cout<<"a4"<<endl;
            }
            else if (ton[2]<n/2 && ton[1]>=n/2 && ton[3]>=n/2 && !vis[b[idx2].id]){
                    ans+=b[idx2].x,ton[2]++,vis[b[idx2].id]=1,idx2--;
        //cout<<"a5"<<endl;
            }
            else if (ton[1]>=n/2 && ton[2]>=n/2 && ton[3]<n/2 && !vis[c[idx3].id]){
                ans+=c[idx3].x,ton[3]++,vis[c[idx3].id]=1,idx3--;
            //cout<<"a6"<<endl;
            }
            else if (ton[1]<n/2 && ton[2]<n/2 && ton[3]>=n/2){
                if (a[idx1].x>b[idx2].x  ){
                    if (!vis[a[idx1].id])
                    ans+=a[idx1].x,ton[1]++,vis[a[idx1].id]=1;
                        idx1--;
              //  cout<<"a7"<<endl;
                }
                else if (!vis[b[idx2].id]){
                    ans+=b[idx2].x,ton[2]++,vis[b[idx2].id]=1,idx2--;
                //cout<<"a8"<<endl;
                }
            }
            else if (ton[1]<n/2 && ton[2]>=n/2 && ton[3]<n/2){
                if (a[idx1].x>c[idx3].x){
                    if (!vis[a[idx1].id]) ans+=a[idx1].x,ton[1]++,vis[a[idx1].id]=1;
                    idx1--;
                //cout<<"a9"<<endl;
                }
                else if(!vis[c[idx3].id]){
                    ans+=c[idx3].x,ton[3]++,vis[c[idx3].id]=1,idx3--;
                  //  cout<<"a10"<<endl;
                }
            }
            else if (ton[1]>=n/2 && ton[2]<n/2 && ton[3]<n/2){
                if (b[idx2].x>c[idx3].x){
                    if (!vis[b[idx2].id])
                        ans+=b[idx2].x,ton[2]++,vis[b[idx2].id]=1;
                    idx2--;
            //cout<<"a11"<<endl;
                }
                else if(!vis[c[idx3].id]){
                    ans+=c[idx3].x,ton[3]++,vis[c[idx3].id]=1,idx3--;
                //cout<<"a12"<<endl;
                }
            }
        }
        //cout<<ans<<" "<<a[idx1].x<<" "<<b[idx2].x<<" "<<c[idx3].x<<endl;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while (T--) solve();
    return 0;
}

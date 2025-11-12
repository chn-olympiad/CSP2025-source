#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+5;
struct node{
    int x,y,z;
}a[N];
int a1[N],a2[N],a3[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a1,0,sizeof a1);
        memset(a2,0,sizeof a2);
        memset(a3,0,sizeof a3);
        int n;
        cin>>n;
        int ans=0;
        int len1=0,len2=0,len3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                int c=min(a[i].x-a[i].y,a[i].x-a[i].z);
                a1[++len1]=c;
                ans+=a[i].x;
            }
            else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
                int c=min(a[i].y-a[i].x,a[i].y-a[i].z);
                a2[++len2]=c;
                ans+=a[i].y;
            }
            else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
                int c=min(a[i].z-a[i].x,a[i].z-a[i].y);
                a3[++len3]=c;
                ans+=a[i].z;
            }
        }
        sort(a1+1,a1+len1+1);
        sort(a2+1,a2+len2+1);
        sort(a3+1,a3+len3+1);
        int j=1;
        if(len1>n/2){
            while(len1>n/2){
                len1--;
                ans-=a1[j++];
            }
        }
        if(len2>n/2){
            while(len2>n/2){
                len2--;
                ans-=a2[j++];
            }
        }
        if(len3>n/2){
            while(len3>n/2){
                len3--;
                ans-=a3[j++];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

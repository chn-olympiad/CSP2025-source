#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,id;
}a[100005],b[100005],c[100005];

int T,n,N,sum=0;

bool vis[100005];

bool cmp(node u,node v){
    return u.x>v.x;
}

void DFS(int idx,int ans,int la,int lb,int lc){
    //cout<<idx<<" "<<ans<<" "<<la<<" "<<lb<<" "<<lc<<endl;
    if(la>N)    return ;
    if(lb>N)    return ;
    if(lc>N)    return ;
    if(idx==n)  {sum=max(sum,ans);return ;}
    DFS(idx+1,ans+a[idx+1].x,la+1,lb,lc);
    DFS(idx+1,ans+b[idx+1].x,la,lb+1,lc);
    DFS(idx+1,ans+c[idx+1].x,la,lb,lc+1);
}

void DFS2(int idx,int ans,int la,int lb){
    if(la>N)    return ;
    if(lb>N)    return ;
    if(idx==n)  {sum=max(sum,ans);return ;}
    if(a[idx+1].x*4<=b[idx+1].x)
        DFS2(idx+1,ans+b[idx+1].x,la,lb+1);
    else if(b[idx+1].x*4<=a[idx+1].x)
        DFS2(idx+1,ans+a[idx+1].x,la+1,lb);
    else{
        DFS2(idx+1,ans+b[idx+1].x,la,lb+1);
        DFS2(idx+1,ans+a[idx+1].x,la+1,lb);
    }
    return ;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        sum=0;
        N=n/2;
        bool flag1=0,flag2=0;
        for(int i=1;i<=n;i++){
            vis[i]=0;
            cin>>a[i].x>>b[i].x>>c[i].x;
            a[i].id=i,b[i].id=i,c[i].id=i;
            if(b[i].x!=0) flag1=1;
            if(c[i].x!=0) flag2=1;
        }
        if(n<=30){
            DFS(1,a[1].x,1,0,0);
            DFS(1,b[1].x,0,1,0);
            DFS(1,c[1].x,0,0,1);
            cout<<sum<<'\n';
        }
        else if(flag1==0&&flag2==0){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=N;i++)
                sum+=a[i].x;
            cout<<sum<<'\n';
        }
        else if(flag1==1&&flag2==0){
           DFS2(1,a[1].x,1,0);
           DFS2(1,b[1].x,0,1);
           cout<<sum<<'\n';
        }
        else{
            DFS(1,a[1].x,1,0,0);
            DFS(1,b[1].x,0,1,0);
            DFS(1,c[1].x,0,0,1);
            cout<<sum<<'\n';
        }
        /*
        for(int i=1;i<=n;i++)
            cout<<a[i].x<<" "<<a[i].id<<endl;
        cout<<endl;
        for(int i=1;i<=n;i++)
            cout<<b[i].x<<" "<<b[i].id<<endl;
        cout<<endl;
        for(int i=1;i<=n;i++)
            cout<<c[i].x<<" "<<c[i].id<<endl;
        cout<<endl;*/
    }
    return 0; 
}

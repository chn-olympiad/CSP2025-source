#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll read(){
    ll w=1,c,ret;
    while((c=getchar())<'0'||c>'9') w=(c=='-'?-1:1);
    ret=c-48;
    while((c=getchar())>='0'&&c<='9') ret=ret*10+c-48;
    return w*ret;
}

int const maxn=1e5+105,maxm=1e6+5;
ll const inf=1e18;

int n,m,k,ck;

struct edge{
    int u,v;
    ll w;
    bool chose;
    bool sj;

    bool operator<(edge const &x) const{
        return w<x.w;
    }

}e[maxm],e2[maxm+10*maxn];

ll c[20],a[20][maxn];

int fa[maxn];

int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.ans","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        e[i]={u,v,w};
        e2[++ck]={u,v,w};
    }

    bool A=1;

    for(int i=1;i<=k;i++){
        c[i]=read();
        if(c[i]!=0) A=0;
        for(int j=1;j<=n;j++){
            a[i][j]=read();
            //e2[++ck]={i+n,j,c[i]+a[i][j]};
        }
    }

    ll ans=0;

    if(A){
    	for(int i=1;i<=k;i++){
	       // c[i]=read();
	       // if(c[i]!=0) A=0;
	        for(int j=1;j<=n;j++){
	          //  a[i][j]=read();
	            e2[++ck]={i+n,j,c[i]+a[i][j]};
	        }
	    }
        sort(e2+1,e2+ck+1);
        for(int i=1;i<=ck;i++){
            int u=e2[i].u,v=e2[i].v,w=e2[i].w;
            u=find(u),v=find(v);
            if(u==v) continue;
            fa[u]=v;
            ans+=w;
        }
        cout<<ans;
        return 0;
    }else if(k==0){
        sort(e+1,e+m+1);
        for(int i=1;i<=m;i++){
            int u=e2[i].u,v=e2[i].v,w=e2[i].w;
            u=find(u),v=find(v);
            if(u==v) continue;
            fa[u]=v;
            ans+=w;
        }
        cout<<ans;
        return 0;
    }
    // else if(n<=1000){
    //     ans=inf;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             if(i==j) g[i][j]=0;
    //             else g[i][j]=inf;
    //         }
    //     }
    //     for(int i=1;i<=m;i++){
    //         g[e[i].u][e[i].v]=e[i].w;
    //         g[e[i].v][e[i].u]=e[i].w;
    //     }

    // 	for(int s=0;s<(1<<k);s++){
    // 		ck=0;
    //         int blo=n;
    // 		ll tmp=0;
    //         for(int i=1;i<=k;i++){
    //             for(int j=1;j<=n;j++){
    //                 g[i+n][j]=g[j][i+n]=inf;
    //             }
    //         }

    // 		for(int i=1;i<=k;i++){
    // 			if((s>>(i-1))&1){
    //                 blo++;
    //                 tmp+=c[i];
    //                 for(int j=1;j<=n;j++){
    //                     g[i+n][j]=g[j][i+n]=a[i][j];
    //                 }
	// 			}
	// 		}
    //         for(int i=1;i<=n+k;i++) dis[i]=inf;
    //         dis[1]=0;
    //         while(blo>1){
    //             int u=0;
                


    //         }
            
           
    		
    		
	// 	}
    // 	cout<<ans;

    // }
    else if(k<=5){
        ans=inf;
    	for(int s=0;s<(1<<k);s++){
    		ck=0;
    		ll tmp=0;
            int blo=n;
    		for(int i=1;i<=n+k;i++) fa[i]=i;

    		for(int i=1;i<=k;i++){
    			if((s>>(i-1))&1){
                  //  cout<<s<<' '<<(i-1)<<" "<<k<<'\n';
                    blo++;
    				tmp+=c[i];
    				for(int j=1;j<=n;j++){
                        e2[++ck]={i+n,j,a[i][j]};
                    }
				}
			}
            for(int i=1;i<=m;i++){
                e2[++ck]={e[i].u,e[i].v,e[i].w};
            }
            sort(e2+1,e2+ck+1);
            for(int i=1;i<=ck;i++){
                int u=e2[i].u,v=e2[i].v,w=e2[i].w;
                u=find(u),v=find(v);
                if(u==v) continue;
                blo--;
                fa[u]=v;
                tmp+=w;
                if(blo==1) break;
            }
            ans=min(ans,tmp);
    		
    		
		}
    	cout<<ans;
    	
	}else{
		sort(e+1,e+m+1);
        for(int i=1;i<=m;i++){
            int u=e2[i].u,v=e2[i].v,w=e2[i].w;
            u=find(u),v=find(v);
            if(u==v) continue;
            fa[u]=v;
            ans+=w;
        }
        cout<<ans;
	}

    





    
    





    return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/
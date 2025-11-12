#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
const int M=3e6+5;

int n,m,k;
struct node{
    int u;
    int v;
    int val;
    int leic;
    bool friend operator<(node a,node b){
        return a.val<b.val;
    }
}Edge[M];
int cnte;
int fa[N];
int c[15];
bool us[15];
int a[15][N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
ll ans=1e18;
int nowbian=0;
ll now=0;
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1,lu,lv,la;i<=m;i++){
        cin>>lu>>lv>>la;
        Edge[++cnte]={lu,lv,la,0};
    }
    for(int i=0;i<k;i++){
        cin>>c[i+1];
        int minn=1e9+7,id;
        for(int j=0;j<n;j++){
            cin>>a[i+1][j+1];
            if(minn>a[i+1][j+1]){
                minn=min(minn,a[i+1][j+1]);
                id=j+1;
            }
        }
        for(int j=1;j<=n;j++){
            if(j==id) continue;
            Edge[++cnte]={id,j,a[i+1][j]+minn+c[i+1],id};
        }
    }
    sort(Edge+1,Edge+cnte+1);
//    cout<<cnte<<"\n";
    
    
//    for(int S=0;S<(1<<k);S++){
    	
//    	cout<<now<<" ";
	    for(int i=1;i<=cnte;i++){
	        int lu=Edge[i].u,lv=Edge[i].v,la=Edge[i].val;
	        int fau=find(lu),fav=find(lv);
	        if(fau!=fav){
	            if(Edge[i].leic!=0&&us[Edge[i].leic]==1)
	                now+=la-c[Edge[i].leic];
	            else if(Edge[i].leic!=0&&us[Edge[i].leic]==0) now+=la,us[Edge[i].leic]=1;
	            else now+=la;
	            fa[fau]=fav;
                nowbian++;
                 if(nowbian==n-1) break;
	        //    cout<<lu<<" "<<lv<<" "<<" "<<la<<"\n";
	        }
	    }
	    ans=min(ans,now);
	// }    
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int _T=1;
    // cin>>_T;
    while(_T--) solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+6;
int T,n,ans=0,cnt=0;
struct node{
    int x,y,z;
}a[maxn];
bool flag,flag2,flag3;
void dfs(int x,int d1,int d2,int d3,int res){
	if(flag3)return;
	if(cnt>1999996){
		flag3=true;
		return;
	}
    if(x==n){
        ans=max(ans,res);
        return;
    }
    if(d1<n/2)dfs(x+1,d1+1,d2,d3,res+a[x+1].x);
    if(d2<n/2)dfs(x+1,d1,d2+1,d3,res+a[x+1].y);
    if(d3<n/2)dfs(x+1,d1,d2,d3+1,res+a[x+1].z);
}
bool cmp(node x,node y){
    int x1=x.x-y.x;
    int y1=x.y-y.y;
    return x1<y1;
}
bool cmp3(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
    	cnt=0;
        ans=0;
        flag=true;
        flag2=true;
        flag3=false;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].z!=0)flag=false;
            if(a[i].y!=0)flag2=false;
        }
        if(flag2&&flag){
        	for(int i=1;i<=n/2;i++)ans+=a[i].x;
        	cout<<ans<<"\n";
        	continue;
		}
        if(flag){
        	sort(a+1,a+1+n,cmp);
        	for(int i=1;i<=n/2;i++)ans+=a[i].y;
        	for(int i=n/2+1;i<=n/2+n+1;i++)ans+=a[i].x;
        	cout<<ans<<'\n';
        	continue;
		}
        dfs(0,0,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}


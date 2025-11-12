#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[100000];
struct node{
	int x,y,z,u;
};
int find(int x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
	return ;
}
bool cmp(node x,node y){
	return x.z<y.z;
}
node a[1000010];
int f=0;
int s[12][10100],l[12],vis[12];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
    	cin>>a[i].x>>a[i].y>>a[i].z;
	}
	int p=m;
	for(int i=1;i<=k;i++){
		cin>>l[i];
		if(l[i]!=0){
			f=1;
		}
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
			if(s[i][j]!=0){
				f=1;
			}
		}
	}
	if(k==0){
        for(int i=1;i<=n;i++){
        	fa[i]=i;
		}
		sort(a+1,a+1+m,cmp);
		int p=0,ans=0;
		for(int i=1;i<=m;i++){
			if(find(a[i].x)!=find(a[i].y)){
				ans+=a[i].z;
				p++;
				merge(a[i].x,a[i].y);
			}
			if(p==n){
				cout<<ans<<endl;
				return 0;
			}
		}
		cout<<ans<<endl;
		return 0;
	}

	if(f==0){
		cout<<0;
		return 0;
	}
	
	for(int o=1;o<=k;o++){
		for(int i=1;i<=n;i++){
	    	for(int j=i+1;j<=n;j++){
	    		a[++p].x=i,a[p].y=j;
	    		a[p].z=l[o]+s[o][i]+s[o][j];
	    		a[p].u=o;
	    		vis[o]=1;
			}
		}
	}
    for(int i=1;i<=n;i++){
        fa[i]=i;
	}
	sort(a+1,a+1+p,cmp);
	int p1=0,ans=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].x)!=find(a[i].y)){
			if(a[i].u==1){
				ans+=a[i].z;
			}else{
    			ans+=a[i].z-l[a[i].u];
	    	}
			p1++;
			merge(a[i].x,a[i].y);
		}
		vis[a[i].u]=0;
		if(p1==n){
			cout<<ans<<endl;
			return 0;
		}
	}
    cout<<ans<<endl;
	return 0;
}


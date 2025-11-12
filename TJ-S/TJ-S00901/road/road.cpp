#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,ans;
ll fa[10010],c[15],l[1010];
struct st{
	ll u,v,w;
}a[1000010];
bool cmp(st x,st y){
	return x.w<y.w;
}
ll find(ll x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
void qre(ll x,ll y){
	ll p=find(x),q=find(y);
	if(p!=q){
		fa[q]=p;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if(k==0){
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(find(a[i].u)!=find(a[i].v)){
				ans+=a[i].w;
				qre(a[i].u,a[i].v);
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>l[j];
			}
			for(int j=1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					a[++m].u=j;
					a[m].v=h;
					a[m].w=l[j]+l[h];
				}
			}
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(find(a[i].u)!=find(a[i].v)){
				ans+=a[i].w;
				qre(a[i].u,a[i].v);
			}
		}
		cout<<ans;
	}
	return 0;
}


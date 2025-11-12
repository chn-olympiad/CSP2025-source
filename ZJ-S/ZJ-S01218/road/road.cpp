#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10050],ans;
const int N=1e9+10;
struct nd{
	int u,v,w;
}a[1000050];
int d[10050][10050];
int c[15];
int mp[10050][10050];
bool cmp(nd x,nd y){
	return x.w<y.w;
}
int ff(int x){
	if(fa[x]==x)
		return x;
	fa[x]=ff(fa[x]);
	return fa[x];
}
int f(int l,int x,int y,int s){
	if(x==y)
		return s;
	for(int i=1;i<=n;i++){
		if(mp[x][i]>0&&i!=l){
//			cout<<x<<' '<<i<<" "<<s<<"\n";
			f(x,i,y,max(s,mp[x][i]));
		}
	}
}
void de(int l,int s,int e,int x,int y){
	if(s==e){
		mp[x][y]=0;
		mp[y][x]=0;
//		cout<<x<<" "<<y<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(mp[s][i]&&i!=l){
			if(mp[s][i]>mp[x][y]){
				x=s;
				y=i;
			}
			de(s,i,e,x,y);
			return;
		}
	}
	return;
}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("% 5d ",mp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		mp[i][i]=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(ff(a[i].u)!=ff(a[i].v)){
//			cout<<a[i].u<<" "<<a[i].v<<"\n";
//			cout<<fa[a[i].u]<<" "<<fa[a[i].v]<<"\n\n";
			fa[fa[a[i].u]]=fa[a[i].v];
			mp[a[i].u][a[i].v]=a[i].w;
			mp[a[i].v][a[i].u]=a[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&mp[n+i][j]);
			mp[j][n+i]=mp[n+i][j];
		}
		int t=0;
		for(int j=1;j<n;j++){
			for(int l=j+1;l<=n;l++){
				int s=f(0,j,l,0);
				if(s>mp[j][n+i]+mp[n+i][l]){
//					cout<<j<<" "<<l<<"\n";
//					cout<<s<<" "<<mp[j][n+i]<<" "<<mp[n+i][l]<<"\n";
					t+=s-mp[j][n+i]-mp[n+i][l];
				}
			}
		}
//		print();
//		cout<<"\n"<<mp[1][3]<<" ";
//		cout<<"\n"<<f(0,1,3,0)<<"\n";
//		cout<<t<<"\n";
		if(t>c[i]){
			for(int j=1;j<n;j++){
				for(int l=j+1;l<=n;l++){
					int s=f(0,j,l,0);
					if(s>mp[j][n+i]+mp[n+i][l]){
						d[j][l]=i;
						d[l][j]=i;
//						print();
						de(0,j,l,0,0);
						mp[j][l]=mp[j][n+i]+mp[n+i][l];
						mp[l][j]=mp[j][l];
//						print();
					}
				}
			}
//			cout<<1<<"\n";
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(mp[i][j]>0){
//				cout<<i<<" "<<j<<" "<<mp[i][j]<<" "<<c[d[i][j]]<<"\n";
				ans=ans+mp[i][j]+c[d[i][j]];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}


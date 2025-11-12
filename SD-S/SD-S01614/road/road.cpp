#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n,m,k,ans=0x3f3f3f3f3f3f3f3f,w[200005],d[15][200005],f[200005];
struct node{
	int x,y,z;
}a[1000005],b[1000005],bb[1000005],c[2000005];
bool cmp(node a,node b){
	return a.z<b.z;
}
int find(int pos){
	if(f[pos]==pos) return pos;
	return f[pos]=find(f[pos]);
}
void fun(int cnt,int nd,int s){
	int t=s;
	for(int i=1; i<=cnt; i++) bb[i]=b[i];
	sort(bb+1,bb+cnt+1,cmp);
	int i=1,j=1,cnt2=0;
	while(i<=m&&j<=cnt){
		if(a[i].z<bb[j].z){
			c[++cnt2]=a[i];
			i++;
		}
		else{
			c[++cnt2]=bb[j];
			j++;
		}
	}
	while(i<=m){
		c[++cnt2]=a[i++];
	}
	while(j<=cnt){
		c[++cnt2]=bb[j++];
	}
//	for(int i=1; i<=n+cnt; i++){
//		cout<<c[i].x<<' '<<c[i].y<<' '<<c[i].z<<"***\n";
//	}cout<<"!!!\n\n";
	for(int i=1; i<=n+k; i++) f[i]=i;
	int nw=0;
	for(int i=1; i<=cnt2; i++){
		int f1=find(c[i].x),f2=find(c[i].y);
		if(f1!=f2){
			nw++;
			f[f1]=f2;
			t+=c[i].z;
		}
		if(nw==n+nd-1) break;
	}
	ans=min(ans,t);
}
void dfs(int pos,int cnt,int nd,int sum){
	if(pos>k){
		fun(cnt,nd,sum);
		return ;
	}
	dfs(pos+1,cnt,nd,sum);
	for(int i=1; i<=n; i++){
		cnt++;
		b[cnt]={i,n+pos,d[pos][i]};
	}
	dfs(pos+1,cnt,nd+1,sum+w[pos]);
	cnt-=n;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1; i<=m; i++){
		scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a+1,a+m+1,cmp);
	int F=0;
	for(int i=1; i<=k; i++){
		scanf("%lld",&w[i]);
		F=max(F,w[i]);
		for(int j=1; j<=n; j++) scanf("%lld",&d[i][j]);
	} 
	if(F==0){
		for(int i=1; i<=n+k; i++) f[i]=i;
		for(int i=1; i<=m; i++) c[i]=a[i];
		int cnt2=m;
		for(int i=1; i<=k; i++){
			for(int j=1; j<=n; j++){
				c[++cnt2]={j,n+i,d[i][j]};
			}
		}
		sort(c+1,c+cnt2+1,cmp);
		int nw=0,tans=0;
		for(int i=1; i<=cnt2; i++){
//			cout<<c[i].x<<' '<<c[i].y<<' '<<c[i].z<<' '<<i<<"!!!\n";
			int f1=find(c[i].x),f2=find(c[i].y);
			if(f1!=f2){
				f[f1]=f2;
				nw++;
				tans+=c[i].z;
			}
			if(nw==n+k-1) break; 
		}
		printf("%lld",tans);
	}
	else{
		dfs(1,0,0,0);
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


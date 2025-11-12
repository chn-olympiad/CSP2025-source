#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4];
int v[4];
int cnt,ans,maxx,cnt2;
bool vis[N],f[N][4];
struct node{
	int ii,jj,sum;
}d[3*N];
struct node2{
	int p,numbers;
}ch[N];
bool cmp(node a,node b){
	if(a.sum==b.sum){
		return a.ii<b.ii;
	}
	return a.sum>b.sum;
}
bool cmp2(node2 a,node2 b){
	return a.numbers<b.numbers;
}
void add(int x,int y){
	d[++cnt].ii=x;
	d[cnt].jj=y;
	d[cnt].sum=a[x][y];
}
void dis(int x){
	if(v[x]>n/2){
		for(int i=1;i<=n;i++){
			if(f[i][x]){
				for(int k=1;k<=3;k++){
					if(k!=x){
						ch[++cnt2].p=k;
						ch[cnt2].numbers=a[i][x]-a[i][k];
					}
				}
			}
		}
		sort(ch+1,ch+cnt2+1,cmp2);
		for(int i=1;i<=cnt2&&v[x]>n/2;i++){
			if(v[ch[i].p]<n/2){
				v[ch[i].p]++;
				v[x]--;
				maxx-=ch[i].numbers;
			}
		}
	}
	for(int i=1;i<=cnt2;i++) ch[i].p=ch[i].numbers=0;
	cnt2=0; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			add(i,1); add(i,2); add(i,3);
		}
		sort(d+1,d+cnt+1,cmp);
		for(int i=1;i<=cnt&&ans<n;i++){
			if(!vis[d[i].ii]){
				vis[d[i].ii]=true;
				ans++;
				maxx+=d[i].sum;
				v[d[i].jj]++;
				f[d[i].ii][d[i].jj]=true;
			}
		}
		dis(1); dis(2); dis(3);
		printf("%d\n",maxx);
		cnt=ans=maxx=0;
		v[1]=v[2]=v[3]=0;
		for(int i=1;i<=n;i++) vis[i]=false;
		for(int i=1;i<=n;i++){
			f[i][1]=f[i][2]=f[i][3]=false;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

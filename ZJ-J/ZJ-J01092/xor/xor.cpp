#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
int n,k;
int a[500005];
int p[500005];
queue<int>q[1000005]; 
node b[500005];
int head[2000005];
int nx[500005];
int cnt,ct;
int now=0;
int ans=0;
void add(int x,int id){
	nx[id]=head[x];
	head[x]=id;
}
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		p[i]=(p[i-1]^a[i]);
	}
	for(int i=n;i>=1;i--){
		add(p[i],i);
	}
	for(int i=1;i<=n;i++){
		int r=(p[i-1]^k);
		if(~head[r]){
			b[++cnt].l=i;
			b[cnt].r=head[r];
		}
		head[p[i]]=nx[i];
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(b[i].l>now){
			now=b[i].r;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

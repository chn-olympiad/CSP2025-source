#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*y;
}
struct yll{
	int u,v;
	long long w;
}a[1100001],b[1100001];
long long n,m,k;
int father[20001],cnt;
long long sum,answer=LONG_LONG_MAX,c[11];
bool flag[20001],F=true;
bool cmp(yll x,yll y){
	return x.w<y.w;
}
int find(int x){
	if(father[x]==x) return x;
	return father[x]=find(father[x]);
}
void work(){
	for(int i=1;i<=m;i++){
		a[i].u=read()+k;
		a[i].v=read()+k;
		a[i].w=read();
		cnt++;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]) F=false;
		for(int j=1;j<=n;j++){
			a[++cnt].u=i;
			a[cnt].v=j+k;
			a[cnt].w=read();
		}
	}
	m+=k*n;
	sort(a+1,a+m+1,cmp);
	n+=k;
	for(int i=0;i<(1<<k);i++){
		sum=0;
		cnt=n-1;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				flag[j]=false;
				sum+=c[j];
			}
			else{
				flag[j]=true;
				cnt--;
			}
		}
		if(sum>answer) continue;
		for(int j=1;j<=n;j++){
			father[j]=j;
		}
		for(int j=1;j<=m;j++){
			if(flag[a[j].u]||flag[a[j].v]) continue;
			if(find(a[j].u)!=find(a[j].v)){
				father[father[a[j].u]]=father[a[j].v];
				sum+=a[j].w;
				cnt--;
				if(cnt==0) break;
			}
			if(sum+cnt*a[j].w>answer) break;
		}
		if(cnt==0){
			answer=min(answer,sum);
		}
	}
	cout<<answer;
	return ;
}
void tepn(){
	for(int j=1;j<=k;j++){
		flag[j]=false;
	}
	cnt=n-1;
	sum=0;
	for(int j=1;j<=n;j++){
		father[j]=j;
	}
	for(int j=1;j<=m;j++){
		if(find(a[j].u)!=find(a[j].v)){
			father[father[a[j].u]]=father[a[j].v];
			sum+=a[j].w;
			cnt--;
			if(cnt==0) break;
		}
	}
	cout<<sum;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	if(m<=100000||k<=5){
		work();
		return 0;
	}
	for(int i=1;i<=m;i++){
		a[i].u=read()+k;
		a[i].v=read()+k;
		a[i].w=read();
	}
	sort(a+1,a+m+1,cmp);
	for(int j=k+1;j<=n+k;j++) father[j]=j;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			father[father[a[i].u]]=father[a[i].v];
			b[++cnt].u=a[i].u;
			b[cnt].v=a[i].v;
			b[cnt].w=a[i].w;
		}
	}
	for(int i=1;i<=cnt;i++){
		a[i]=b[i];
	}
	m=cnt;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]) F=false;
		for(int j=1;j<=n;j++){
			a[++cnt].u=i;
			a[cnt].v=j+k;
			a[cnt].w=read();
		}
	}
	m+=k*n;
	sort(a+1,a+m+1,cmp);
	n+=k;
	if(F){
		tepn();
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		sum=0;
		cnt=n-1;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				flag[j]=false;
				sum+=c[j];
			}
			else{
				flag[j]=true;
				cnt--;
			}
		}
		if(sum>answer) continue;
		for(int j=1;j<=n;j++){
			father[j]=j;
		}
		for(int j=1;j<=m;j++){
			if(flag[a[j].u]||flag[a[j].v]) continue;
			if(find(a[j].u)!=find(a[j].v)){
				father[father[a[j].u]]=father[a[j].v];
				sum+=a[j].w;
				cnt--;
				if(cnt==0) break;
			}
			if(sum+cnt*a[j].w>answer) break;
		}
		if(cnt==0){
			answer=min(answer,sum);
		}
	}
	cout<<answer;
	return 0;
}

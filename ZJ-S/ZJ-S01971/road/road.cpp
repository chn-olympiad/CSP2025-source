#include<bits/stdc++.h>
using namespace std;
struct node{
	int st,en,lb;
	long long val;
}a[2000005],d[2000005];
int n,m,c[15],k,sum,e[15],f[15];
int fa[2000005],num[2000005];
long long ans,gzsum;
bool b[15];
bool cmp(node i,node j){
	return i.val<j.val;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool unio(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	if(num[x]<num[y])swap(x,y);
	fa[y]=x;num[x]+=y;
	return 1;
}
long long krusl(){
	memset(e,0,sizeof(e));
	long long res=0;
	for(int i=1;i<=n;i++)fa[i]=i,num[i]=1;
	for(int i=1;i<=m;i++){
		if(!b[a[i].lb]){
			if(unio(a[i].st,a[i].en)){
				res+=a[i].val;
				if(a[i].lb){
					e[a[i].lb]++;
					f[a[i].lb]=i;	
				}	
			}
		}
	}
	for(int i=1;i<sum;i++){
		if(e[i]==1){
			b[i]=1;
			res-=a[f[i]].val;
			gzsum-=c[i];
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].st>>a[i].en>>a[i].val;
		a[i].lb=0;
	}
	sort(a+1,a+m+1,cmp);
	ans=krusl();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			a[j+m].st=j;
			a[j+m].en=n+1;
			cin>>a[j+m].val;
			a[j+m].lb=i;
		}
		sum++;gzsum+=c[i];n++;
		sort(a+m+1,a+m+n-sum+1,cmp);
		int h1=1,h2=m+1;
		for(int i=1;i<=m+n-sum;i++){
			if(cmp(a[h1],a[h2])||h2>m+n-sum)d[i]=a[h1++];
			else d[i]=a[h2++];
		}
		for(int i=1;i<=m+n-sum;i++){
			a[i]=d[i];
		}
		m+=n-sum;
		long long r=krusl();
		if(r+gzsum<ans){
			ans=r+gzsum;
		}
		else{
			gzsum-=c[i];
			b[i]=1;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> qu;
long long n,cnt,m,k,y,z,ans=1e17,ok=200,f,c[100],uu,vv,cc[100];
struct node{
	int u,v,x,s;
}a[2000005];
struct node1{
	int ve,nu;
}b[10005];
bool cmp(node1 xx,node1 yy){
	return xx.ve<yy.ve;
}
bool cmp1(node xx,node yy){
	if(xx.u==yy.u){
		if(xx.v==yy.v){
			return xx.x<yy.x;
		}
		return xx.v<yy.v;
	}
	return xx.u<yy.u;
}
bool cmp2(node xx,node yy){
	return xx.x<yy.x;
}
void dfs(int x,long long sum){
	if(x==k){
		while(!qu.empty()){
			qu.pop();
		}
		uu=-1;vv=-1;
		for(int i=0;i<cnt;i++){
				//cout<<a[i].x;
			if((a[i].s==-1||cc[a[i].s]==1)&&(a[i].u!=uu||a[i].v!=vv)){
				uu=a[i].u;
				vv=a[i].v;
				qu.push(a[i].x);
				sum+=a[i].x;
				if(qu.size()>=n){
					sum-=qu.top();
					qu.pop();
				}
			}
		}
		//cout<<sum<<' ';
		ans=min(sum,ans);
		return;
	}
	cc[x]=1;
	dfs(x+1,sum+c[x]);
	cc[x]=0;
	dfs(x+1,sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>y>>z>>a[cnt].x;
		a[cnt].u=min(y,z);
		a[cnt].v=max(y,z);
		a[cnt].s=-1;
		cnt++;
	}
	sort(a,a+cnt,cmp2);
	cnt=n;
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>b[j].ve;
			b[j].nu=j+1;
		}
		sort(b,b+n,cmp);
		for(int j=0;j*(j-1)/2<n;j++){
			for(int kk=j+1;kk*(kk-1)/2<n;kk++){
				a[cnt].u=min(b[j].nu,b[kk].nu);
				a[cnt].v=max(b[j].nu,b[kk].nu);
				a[cnt].x=b[j].ve+b[kk].ve;
				a[cnt].s=i;
				cnt++;
			}
		}
	}
	//cout<<a[cnt].u<<' '<<a[cnt].v<<' '<<a[cnt].x<<'\n';
	sort(a,a+cnt,cmp1);
	dfs(0,0);
	cout<<ans;
	return 0;
} 

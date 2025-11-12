#include<bits/stdc++.h> 
using namespace std;
struct node{
	int x,i;
}e[100010];
int cmp(node a,node b){
	return a.x<b.x;
}
int t,n,c1,c2,c3,s,a[100010][4],MAX,b[100010],c[100010],d[100010],MIN,sum;
vector<int>f[100010];
void dfs(int k,int s){
	if(k>n){
		MAX=max(MAX,s);
		return;
	}
	if(c1<n/2){
		++c1;
		dfs(k+1,s+a[k][1]);
		--c1;
	}
	if(c2<n/2){
		++c2;
		dfs(k+1,s+a[k][2]);
		--c2;
	}
	if(c3<n/2){
		++c3;
		dfs(k+1,s+a[k][3]);
		--c3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		c1=c2=c3=s=0;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			MAX=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==MAX)b[++c1]=i;
			if(a[i][2]==MAX)c[++c2]=i;
			if(a[i][3]==MAX)d[++c3]=i;
			f[i].clear();
		}
		if(n<26){
			MAX=c1=c2=c3=0;
			dfs(1,0);
			cout<<MAX<<"\n";
			continue;
		}
		if(c1>n/2){
			for(int i=1;i<=c1;++i){
				e[i].x=a[b[i]][1]-max(a[b[i]][2],a[b[i]][3]);
				e[i].i=b[i];
			}
			sort(e+1,e+c1+1,cmp);
			for(int i=1;i<=c1-n/2;++i)
			if(a[e[i].i][2]>a[e[i].i][3])c[++c2]=e[i].i;
			else d[++c3]=e[i].i;
			for(int i=c1-n/2+1;i<=c1;++i)b[i-c1+n/2]=e[i].i;
			c1=n/2;
		}
		if(c2>n/2){
			for(int i=1;i<=c2;++i){
				e[i].x=a[c[i]][2]-max(a[c[i]][1],a[c[i]][3]);
				e[i].i=c[i];
			}
			sort(e+1,e+c2+1,cmp);
			for(int i=1;i<=c2-n/2;++i)
			if(a[e[i].i][1]>a[e[i].i][3])b[++c1]=e[i].i;
			else d[++c3]=e[i].i;
			for(int i=c2-n/2+1;i<=c2;++i)c[i-c2+n/2]=e[i].i;
			c2=n/2;
		}
		if(c3>n/2){
			for(int i=1;i<=c3;++i){
				e[i].x=a[d[i]][3]-max(a[d[i]][1],a[d[i]][2]);
				e[i].i=d[i];
			}
			sort(e+1,e+c3+1,cmp);
			for(int i=1;i<=c3-n/2;++i)
			if(a[e[i].i][1]>a[e[i].i][2])b[++c1]=e[i].i;
			else c[++c2]=e[i].i;
			for(int i=c3-n/2+1;i<=c3;++i)d[i-c3+n/2]=e[i].i;
			c3=n/2;
		}
		for(int i=1;i<=c1;++i)f[b[i]].push_back(1);
		for(int i=1;i<=c2;++i)f[c[i]].push_back(2);
		for(int i=1;i<=c3;++i)f[d[i]].push_back(3);
		for(int i=1;i<=n;++i){
			sum=MAX=0;
			for(int j=0;j<f[i].size();++j)
			if(f[i][j]==1){
				sum+=a[i][1];
				MAX=max(MAX,a[i][1]);
			}
			else if(f[i][j]==2){
				sum+=a[i][2];
				MAX=max(MAX,a[i][2]);
			}
			else{
				sum+=a[i][3];
				MAX=max(MAX,a[i][3]);
			}
			s-=sum-MAX;
		}
		for(int i=1;i<=c1;++i)s+=a[b[i]][1];
		for(int i=1;i<=c2;++i)s+=a[c[i]][2];
		for(int i=1;i<=c3;++i)s+=a[d[i]][3];
		cout<<s<<"\n";
	}
	return 0;
}

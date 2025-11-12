#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long u,v,w;
};
bool com(edge a,edge b){
	return a.w<b.w;
}
edge b[int(2e6)];
int a[10234];
int find(int q){
	if(a[q]==q) return q;
	a[q]=a[a[q]];
	return find(a[q]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int nn=n,nm=m;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n+k;i++){
		a[i]=i;
	}
	for(int i=0;i<m;i++){
		edge temp;
		cin>>temp.u>>temp.v>>temp.w;
		b[i]=temp;
		
	}
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			edge temp;
			cin>>temp.w;
			temp.u=nn+1;
			temp.v=j;
			b[nm]=temp;
			nm++;
		}
		nn++;
	}
	sort(b,b+nm,com);
	long long ans=0;
	for(int i=0;i<nm;i++){
		if(find(b[i].u)!=find(b[i].v)){
			//clog<<find(b[i].u)<<" "<<find(b[i].v)<<endl;
			a[find(b[i].u)]=b[i].v;
			ans+=b[i].w;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

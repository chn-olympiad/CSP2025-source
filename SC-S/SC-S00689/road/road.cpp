#include<bits/stdc++.h>
using namespace std;
int n,m,k,lenn=0,ans=0;
int w[10005],e[10005];
struct node{
	int i,j,k;
} a[1000005];
int b[10005];
bool my(node q,node w){
	return q.k<w.k;
}
int pp(int ww){
	if(b[ww]==ww) return ww;
	b[ww]=pp(b[ww]);
	return b[ww];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].i>>a[i].j>>a[i].k;
	}
	sort(a+1,a+1+m,my);
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(pp(a[i].i)!=pp(a[i].j)){
			b[a[i].j]=b[pp(a[i].i)];
			ans+=a[i].k;
		}
	}
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
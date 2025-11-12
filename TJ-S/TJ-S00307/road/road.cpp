#include<bits/stdc++.h>
using namespace std;
int n,m,k,h=0,g=0,mi=INT_MAX,q,t[20];
struct node{
	int a,b,c;
}s[100010];
int cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
	}
	sort(s+1,s+m+1,cmp);
	h=h+s[1].c+s[2].c;
	for(int i=1;i<=k;i++){
		cin>>q;
		for(int j=1;j<=n;j++){
			cin>>t[j];
		}
		if(q<mi){
			mi=q;
			sort(t+1,t+n+1);
			g=t[1]+t[2];
		}
	}
	cout<<h+g+mi;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

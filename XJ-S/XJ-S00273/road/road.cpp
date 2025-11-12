#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct mapp{
	int x,y,q;
};mapp a[10005],b[10005];
bool cmp(mapp x,mapp y){
	return x.q<y.q;
}
int find(int a,int c[]){
	return c[c[a]];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0,c[10005];
	cin>>n>>m>>k;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].q;		
		
	}
	for(int i=0;i<=n;i++){
		c[i]=i;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		int a1=a[i].x;
		int b1=a[i].y;
		if(a1>b1){
			int c1=a1;
			a1=b1;
			b1=c1;
		}
		if(find(a1,c)!=find(b1,c)){
			c[c[b1]]=c[c[a1]];
			c[a1]=c[c[a1]];
			c[b1]=c[c[b1]];
			cnt+=a[i].q;
		}
	}
	
	cout<<cnt;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,h,i,j,mi,sum,b[1000001],c[10010][20],k,s,mi2;
map<int,int>f[100001];
struct no{
	int a,b,c;
}a[1000001];
bool cmp(no t,no w){
	return t.c<w.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>h;
	for(i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	for(i=1;i<=h;i++){
		cin>>b[i];
		for(j=1;j<=n;j++)cin>>c[i][j];
	}
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++){
		a[i].c+=a[i-1].c;
		if(f[i-1][a[i].a]==0){
			for(j=i;j<=m;j++)f[j][a[i].a]=1;
		}
		if(f[i-1][a[i].b]==0){
			for(j=i;j<=m;j++)f[j][a[i].b]=1;
		}
	}
	sum=2e9;
	for(i=1;i<=m;i++){
		mi=2e9;
		for(j=1;j<=h;j++){
			s=b[j];mi2=2e9;
			for(k=1;k<=n;k++)
				if(f[i][k]==0)s+=c[j][k];
				else mi2=min(mi2,c[j][k]);
			mi=min(mi,s+mi2);
		}
		sum=min(sum,mi+a[i].c);
	}
	cout<<sum;
	return 0;
}

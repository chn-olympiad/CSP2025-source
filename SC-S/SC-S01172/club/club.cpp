#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair<long,long>
using namespace std;
const int N=1e5+5;
struct o{
	ll sum,c[4];
}f[N][5];
struct Node{
	ll w[4],mx;
}a[N];
bool cmp(Node a,Node b){
	if(a.mx!=b.mx)
	return a.mx>b.mx;
	else return a.w[1]+a.w[2]+a.w[3]>b.w[1]+b.w[2]+b.w[3];
}
ll n,mx=-1e9;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		mx=-1e9;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				f[i][j].sum=0;
				for(int k=1;k<=3;k++)
					f[i][j].c[k]=0;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i].w[j],a[i].mx=max({a[i].w[1],a[i].w[2],a[i].w[3]});
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=3;i++){
			f[1][i].sum=a[1].w[i];
			f[1][i].c[i]=1;
		}
		for(int i=2;i<=n;i++)
			for(int j=1;j<=3;j++)
				for(int k=1;k<=3;k++)
					if(f[i-1][k].c[j]<n/2)
						if(f[i][j].sum<f[i-1][k].sum+a[i].w[j]){
							f[i][j]=f[i-1][k];
							f[i][j].sum+=a[i].w[j];
							f[i][j].c[j]++;
						}
		for(int i=1;i<=3;i++)
			mx=max(f[n][i].sum,mx);
		cout<<mx<<"\n";
	}
	return 0;
}
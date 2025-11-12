#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long sum=0,ans=0;
struct bp{
	long long u,v;
	long long w;
}ar[10005];
struct ap{
	long long c;
	long long l[1005];
}arr[10005];
bool b[1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ar[i].u>>ar[i].v>>ar[i].w;
		if(!b[ar[i].u]&&!b[ar[i].v]){
			sum+=ar[i].w;
			b[ar[i].u]=1;
			b[ar[i].v]=1;
		}
	}  
	cout<<sum;
	ans=sum;
	for(int i=1;i<=k;i++){
		cin>>arr[i].c;
		int cnt=0;
		for(int j=1;j<=m;j++){
			cin>>arr[i].l[++cnt];
			if(arr[i].l[cnt]<ar[i].w) ans-=(ar[i].w-arr[i].l[cnt]);
		}
		ans=min(ans+arr[i].c,sum);
	} 
	cout<<ans;
	return 0;
}

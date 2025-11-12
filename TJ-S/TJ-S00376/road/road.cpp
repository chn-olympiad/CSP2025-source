#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w,type;
}a[1001010];
int city[1000110];
long long n,m,k,now=0,maxx,ans=0;
bool cmp(road x,road y){
	return x.w<y.w;
}
int c[1000110],cotry[1001010];
int shr[1100][1100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+m,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			if((city[a[i].u]>=2)&&(city[a[i].v]>=2)){
				continue;
			}
			now++;
			ans+=a[i].w;
			city[a[i].u]++;
			city[a[i].v]++;
			if(now==(n-1)){
				cout<<ans;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			shr[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[m+i].w;
			a[m+i].w+=c[i]; 
			a[m+i].u=n+i;
			a[m+i].v=j;
			a[m+i].type=10086;
		}
		 
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=n;k++){
//				if(j==k){
//					continue;
//				}
//				shr[j][k]=min(shr[j][k],(cotry[i][j]+cotry[i][k]));
//			}
//		}
	}
	sort(a+1,a+1+m+k,cmp);
	for(int i=1;i<=k+m;i++){
		if((city[a[i].u]>=2)&&(city[a[i].v]>=2)){
			continue;
		}
		now++;
		ans+=a[i].w;
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<" "<<a[i].type<<endl;
		if(a[i].type==10086){
			if(cotry[i]==999){
				ans-=c[i];
			}
			cotry[i]=999;
		}
		city[a[i].u]++;
		city[a[i].v]++;
		if(now==(n-1)){
			cout<<ans;
			return 0;
		}
	}
//	for(int i=1;i<=m;i++){
//		if((city[a[i].u]>=2)&&(city[a[i].v]>=2)){
//			continue;
//		}
//		now++;
//		
//		if(shr[a[i].u][a[i].v]<a[i].w){
//			ans+=shr[a[i].u][a[i].v];
//		}else{
//			ans+=a[i].w;
//		}
//		city[a[i].u]++;
//		city[a[i].v]++;
//		if(now==(n-1)){
//			cout<<ans;
//			return 0;
//		}
//	}
	return 0;
}


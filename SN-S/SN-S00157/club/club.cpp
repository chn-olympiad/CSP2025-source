#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005][5],xx,yy,zz,sum[200005][5];
int maxx(int x,int y,int z){
	return max(max(x,y),z);
}
struct s{
	int name,num;
}cnt[100005];
bool cmp(s q,s w){
	return q.num>w.num;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans;
	cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			sum[i][1]=abs(a[i][1]-a[i][2]);
			sum[i][2]=abs(a[i][2]-a[i][3]);
			sum[i][3]=abs(a[i][1]-a[i][3]);
			cnt[i].num=maxx(sum[i][1],sum[i][2],sum[i][3]);
			cnt[i].name=i;
		}
		sort(cnt+1,cnt+n+1,cmp);
		 for(int i=1;i<=n;i++){
		 	int zzz=0;
			 if(maxx(a[cnt[i].name][1],a[cnt[i].name][2],a[cnt[i].name][3])==a[cnt[i].name][1]and zzz==0 and xx<n/2){
			 	xx++;
			 	ans+=a[cnt[i].name][1];
			 	zzz++;
			 }
			 	if(maxx(a[cnt[i].name][1],a[cnt[i].name][2],a[cnt[i].name][3])==a[cnt[i].name][1]and zzz==0 and xx>=n/2){
			 	if(max(a[cnt[i].name][2],a[cnt[i].name][3])==a[cnt[i].name][2]){
			 		yy++;
			 		ans+=a[cnt[i].name][2];
			 		zzz++;
				 }
				 else{
				 zz++;
			 	ans+=a[cnt[i].name][3];	
			 	zzz++;
				 }
			 }
			 
			 if(maxx(a[cnt[i].name][1],a[cnt[i].name][2],a[cnt[i].name][3])==a[cnt[i].name][2]and zzz==0 and yy<n/2){
			 	yy++;
			 	ans+=a[cnt[i].name][2];
			 	zzz++;
			 }
			 	if(maxx(a[cnt[i].name][1],a[cnt[i].name][2],a[cnt[i].name][3])==a[cnt[i].name][2]and zzz==0 and yy>=n/2){
			 	if(max(a[cnt[i].name][1],a[cnt[i].name][3])==a[cnt[i].name][1]){
			 		xx++;
			 		ans+=a[cnt[i].name][1];
			 		zzz++;
				 }
				 else{
				 zz++;
			 	ans+=a[cnt[i].name][3];	
			 	zzz++;
				 }
			 }
			 
			 
			if(maxx(a[cnt[i].name][1],a[cnt[i].name][2],a[cnt[i].name][3])==a[cnt[i].name][3]and zzz==0 and zz<n/2){
			 	zz++;
			 	ans+=a[cnt[i].name][3];
			 	zzz++;
			 }
			 	if(maxx(a[cnt[i].name][1],a[cnt[i].name][2],a[cnt[i].name][3])==a[cnt[i].name][2]and zzz==0 and zz>=n/2){
			 	if(max(a[cnt[i].name][1],a[cnt[i].name][2])==a[cnt[i].name][1]){
			 		xx++;
			 		ans+=a[cnt[i].name][1];
			 		zzz++;
				 }
				 else{
				 yy++;
			 	ans+=a[cnt[i].name][2];	
			 	zzz++;
				 }
			 }
			 zzz=0;
		 }
		 cout<<ans<<"\n"<<zz;
		 ans=0;
		 for(int i=1;i<=n;i++){
		 	cnt[i].name=0;
		 	cnt[i].num=0;
		 	for(int j=1;j<=3;j++){
			 sum[i][j]=0;
			 a[i][j]=0;
		 }
	}
	xx=0;
	yy=0;
}
}

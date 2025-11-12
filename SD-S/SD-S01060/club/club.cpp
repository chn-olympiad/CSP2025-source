#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010][10];
int f[100010];
bool cmp1(int s,int t){
	return a[s][1]>a[t][1];
}
bool cmp2(int s,int t){
	return a[s][2]>a[t][2];
}
bool cmp3(int s,int t){
	return a[s][3]>a[t][3];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int k=n/2;
		int x[100010],y[100010],z[100010];
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			cnt1++;
			x[cnt1]=i;				
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			    cnt2++;
				y[cnt2]=i;
				
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){		
				cnt3++;
				z[cnt3]=i;	
			}
		}
		long long ans=0;
		if(cnt1<=k&&cnt2<=k&&cnt3<=k){
			for(int i=1;i<=cnt1;i++) ans+=a[x[i]][1];
			for(int i=1;i<=cnt2;i++) ans+=a[y[i]][2];
			for(int i=1;i<=cnt3;i++) ans+=a[z[i]][3];
			printf("%lld\n",ans);
			continue;
		}
		else if(cnt1>k){
			for(int i=1;i<=cnt2;i++) ans+=a[y[i]][2];
			for(int i=1;i<=cnt3;i++) ans+=a[z[i]][3];
		//	sort(x+1,x+1+cnt1,cmp1); 
		//	for(int i=1;i<=k;i++) ans+=a[x[i]][1];
		//	for(int i=k+1;i<=cnt1;i++) ans+=max(a[x[i]][2],a[x[i]][3]);
		for(int i=1;i<=cnt1;i++){
			for(int j=min(k,i);j>=max(0,i-k);j--){
				if(j==0) {
				f[j]=f[j]+max(a[x[i]][2],a[x[i]][3]);
				continue;
			}
				f[j]=max(f[j]+max(a[x[i]][2],a[x[i]][3]),f[j-1]+a[x[i]][1]);
			}
		}
		ans+=f[k];
		}
		else if(cnt2>k){
			for(int i=1;i<=cnt1;i++) ans+=a[x[i]][1];
			for(int i=1;i<=cnt3;i++) ans+=a[z[i]][3];
		//	sort(y+1,y+1+cnt2,cmp2); 
		//	for(int i=1;i<=k;i++) ans+=a[y[i]][2];
		//	for(int i=k+1;i<=cnt2;i++) ans+=max(a[y[i]][1],a[y[i]][3]);
			for(int i=1;i<=cnt2;i++){
				for(int j=min(k,i);j>=max(0,i-k);j--){
							if(j==0) {
				f[j]=f[j]+max(a[y[i]][1],a[y[i]][3]);
				continue;
			}
					f[j]=max(f[j]+max(a[y[i]][1],a[y[i]][3]),f[j-1]+a[y[i]][2]);
				}
			}
			ans+=f[k];
		}
		else if(cnt3>k){
			for(int i=1;i<=cnt2;i++) ans+=a[y[i]][2];
			for(int i=1;i<=cnt1;i++) ans+=a[x[i]][1];
			//sort(z+1,z+1+cnt3,cmp3); 
			//for(int i=1;i<=k;i++) ans+=a[z[i]][3];
			//for(int i=k+1;i<=cnt3;i++) ans+=max(a[z[i]][1],a[z[i]][2]);
			for(int i=1;i<=cnt3;i++){
				for(int j=min(i,k);j>=max(0,i-k);j--){
							if(j==0) {
				f[j]=f[j]+max(a[z[i]][1],a[z[i]][2]);
				continue;
			}
					f[j]=max(f[j]+max(a[z[i]][1],a[z[i]][2]),f[j-1]+a[z[i]][3]);
				}
			}
			ans+=f[k];
		}
		printf("%lld\n",ans);
		for(int i=0;i<=k;i++) f[i]=0;
	}
	return 0;
} 

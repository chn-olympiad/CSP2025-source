#include<bits/stdc++.h>
using namespace std;
const int N=200010;
struct node{
	int x,y,z;
}a[N];
int mid1[N],mid2[N],mid3[N];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int t=n/2;
		int sum1=0,sum2=0,sum3=0;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].z&&a[i].x>=a[i].y){
				sum1++,ans+=a[i].x;
				if(a[i].y>=a[i].z) mid1[++cnt1]=a[i].x-a[i].y;
				else mid1[++cnt1]=a[i].x-a[i].z;
			}
			else if(a[i].y>=a[i].z){
				sum2++,ans+=a[i].y;
				if(a[i].x>=a[i].z) mid2[++cnt2]=a[i].y-a[i].x;
				else mid2[++cnt2]=a[i].y-a[i].z;
			}
			else{
				sum3++,ans+=a[i].z;
				if(a[i].x>=a[i].y) mid3[++cnt3]=a[i].z-a[i].x;
				else mid3[++cnt3]=a[i].z-a[i].y;
			}
		}
		if(sum1>t){
			sort(mid1+1,mid1+cnt1+1,cmp);
			for(int i=1;i<=sum1-t;i++) ans-=mid1[i];
		}
		if(sum2>t){
			sort(mid2+1,mid2+cnt2+1,cmp);
			for(int i=1;i<=sum2-t;i++) ans-=mid2[i];
		}
		if(sum3>t){
			sort(mid3+1,mid3+cnt3+1,cmp);
			for(int i=1;i<=sum3-t;i++) ans-=mid3[i];
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}

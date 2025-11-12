#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c,l,ma1,ma2;
}arr[414514];
bool cmp(node a,node b){
	return a.l>b.l;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
			long long a[4]={0,arr[i].a,arr[i].b,arr[i].c};
			sort(a+1,a+4);
//			cout<<a[1]<<a[2]<<a[3]<<" ";
			arr[i].l=a[3]-a[2];
		}
		sort(arr+1,arr+1+n,cmp);
//		cout<<1;
		int cnt1=0,cnt2=0,cnt3=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(arr[i].a>max(arr[i].b,arr[i].c)){
				if(cnt1<n/2){
					cnt1++;
					ans+=arr[i].a;
				}else{
					if(arr[i].b>arr[i].c){
						cnt2++;
						ans+=arr[i].b;
					}else{
						cnt3++;
						ans+=arr[i].c;
					}
				}
			}else if(arr[i].b>max(arr[i].a,arr[i].c)){
				if(cnt2<n/2){
					cnt2++;
					ans+=arr[i].b;
				}else{
					if(arr[i].a>arr[i].c){
						cnt1++;
						ans+=arr[i].a;
					}else{
						cnt3++;
						ans+=arr[i].c;
					}
				}
			}else if(arr[i].c>max(arr[i].b,arr[i].a)){
				if(cnt3<n/2){
					cnt3++;
					ans+=arr[i].c;
				}else{
					if(arr[i].b>arr[i].a){
						cnt2++;
						ans+=arr[i].b;
					}else{
						ans+=arr[i].a;
						cnt1++;
					}
				}
			}else if(arr[i].a==arr[i].b){
				ans+=arr[i].a;
				if(cnt1<cnt2)
					cnt1++;
				else
					cnt2++;
			}else if(arr[i].a==arr[i].c){
				ans+=arr[i].a;
				if(cnt1<cnt3)
					cnt1++;
				else
					cnt3++;
			}else if(arr[i].c==arr[i].b){
				ans+=arr[i].b;
				if(cnt3<cnt2)
					cnt3++;
				else
					cnt2++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

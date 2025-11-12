#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+100;
int t,n;
struct node{
	int a,b,c,mx;
}arr[maxn];
bool cmp(node x,node y){
	return x.mx<y.mx;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
			arr[i].mx=max(arr[i].a,max(arr[i].b,arr[i].c));
		}
			
		sort(arr+1,arr+1+n,cmp);
		for(int i=1;i<=n;i++){
			int a=arr[i].a,b=arr[i].b,c=arr[i].c,f=0;
			if(cnt1<n/2){
				if(a>=b&&a>=c){
					cnt1++;
					ans+=a;
					f=1;
				}else if(a>=b&&cnt3>=n/2){
					cnt1++;
					ans+=a;
					f=1;
				}else if(a>=c&&cnt2>=n/2){
					cnt1++;
					ans+=a;
					f=1;
				}else if(cnt2>=n/2&&cnt3>=n/2){
					cnt1++;
					ans+=a;
					f=1;
				}
			}
			if(!f&&cnt2<n/2){
				if(b>=a&&b>=c){
					cnt2++;
					ans+=b;
					f=1;
				}else if(b>=a&&cnt3>=n/2){
					cnt2++;
					ans+=b;
					f=1;
				}else if(b>=c&&cnt1>=n/2){
					cnt2++;
					ans+=b;
					f=1;
				}else if(cnt1>=n/2&&cnt3>=n/2){
					cnt2++;
					ans+=b;
					f=1;
				}
			}
			if(!f&&cnt3<n/2){
				if(c>=b&&c>=a){
					cnt3++;
					ans+=c;
					f=1;
				}else if(c>=b&&cnt1>=n/2){
					cnt3++;
					ans+=c;
					f=1;
				}else if(c>=a&&cnt2>=n/2){
					cnt3++;
					ans+=c;
					f=1;
				}else if(cnt2>=n/2&&cnt1>=n/2){
					cnt3++;
					ans+=c;
					f=1;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

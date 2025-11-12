#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct stu{
	int a,b,c;
	int jizhun,max_1,num_1;
	bool operator <(const stu &k){
		return max_1>k.max_1;
	}
}mp[maxn];
stu cmp[maxn];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&mp[i].a,&mp[i].b,&mp[i].c);
			int mid;
			if(mp[i].a>=mp[i].b){
				if(mp[i].a<=mp[i].c){
					mid=mp[i].a;
				}
				else mid=mp[i].b;
			}
			else{
				if(mp[i].b<=mp[i].c){
					mid=mp[i].b;
				}
				else mid=max(mp[i].a,mp[i].c); 
			}
			mp[i].jizhun=mid;
			mp[i].a-=mid,mp[i].b-=mid,mp[i].c-=mid;
			if(mp[i].a>mp[i].b&&mp[i].a>mp[i].c){
				mp[i].max_1=mp[i].a;
				mp[i].num_1=1;
			} 
			else if(mp[i].b>=mp[i].a&&mp[i].b>mp[i].c){
				mp[i].max_1=mp[i].b;
				mp[i].num_1=2;
			}
			else {
				mp[i].max_1=mp[i].c;
				mp[i].num_1=3;
			}
		}
//		for(int i=1;i<=n;i++){
//			printf("{%d %d %d %d %d}\n",mp[i].a,mp[i].b,mp[i].c,mp[i].max_1,mp[i].num_1);
//		}
		sort(mp+1,mp+1+n);
//		for(int i=1;i<=n;i++){
//			printf("{%d %d %d %d}\n",mp[i].max_1,mp[i].num_1,mp[i].jizhun,i);
//		}
		int cnt=0,ant[4];
		memset(ant,0,sizeof(ant));
		int bn=n/2;
		long long ans=0;
		do{
			cnt++;
			ans+=(mp[cnt].max_1+mp[cnt].jizhun);
			ant[mp[cnt].num_1]++;
			if(ant[1]>=bn||ant[2]>=bn||ant[3]>=bn){
				break;
			}
		}while(cnt<=n);
		if(cnt==n){
			printf("%lld\n",ans);
		}
		else {
//			printf("[%d %d %d]",ant[1],ant[2],ant[3]);
			for(int i=cnt+1;i<=n;i++){
				if(ant[1]==bn){
					ans+=(max(mp[i].b,mp[i].c)+mp[i].jizhun);
				}
				else if(ant[2]==bn){
					ans+=(max(mp[i].a,mp[i].c)+mp[i].jizhun);
				}
				else ans+=(max(mp[i].a,mp[i].b)+mp[i].jizhun);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
const int N=1e5+10;
int T,n;
int a[N][4];
//int sum;
int f(int u,int num1,int num2,int num3,int sum){
	if(u==n+1){
		return sum;
	}else{
		int ans=-0x3f3f3f3f;
		if(num1<n/2) ans=std::max(f(u+1,num1+1,num2,num3,sum+a[u][1]),ans);
		if(num2<n/2) ans=std::max(f(u+1,num1,num2+1,num3,sum+a[u][2]),ans);
		if(num3<n/2) ans=std::max(f(u+1,num1,num2,num3+1,sum+a[u][3]),ans);
		return ans;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		printf("%d\n",f(1,0,0,0,0));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#include <queue>
//#include <map>
//typedef std::pair<int,int> pii;
//const int N=1e5+10;
//struct Node{
//	pii fir,sec,thi;
//	int Min1,Min2;
//}a[N];
//int T,n;
//int num[4],sum[4];
//std::priority_queue<int> pq[4];
//std::map<int,int> mp;
//int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d",&n);
//		for(int i=1;i<=n;i++){
//			scanf("%d%d%d",&a[i].fir.first,&a[i].sec.first,&a[i].thi.first);
//			a[i].fir.second=1,a[i].sec.second=2,a[i].thi.second=3;
//			if(a[i].thi.first>a[i].sec.first) std::swap(a[i].sec,a[i].thi);
//			if(a[i].sec.first>a[i].fir.first) std::swap(a[i].sec,a[i].fir);
//			if(a[i].thi.first>a[i].fir.first) std::swap(a[i].fir,a[i].thi);
//			a[i].Min1=a[i].thi.first-a[i].sec.first;
//			a[i].Min2=a[i].sec.first-a[i].thi.first;
//			mp[a[i].Min1]=
//		}
//		std::sort(a+1,a+1+n,[](const Node &a,const Node &b){
//			if(a.fir.first!=b.fir.first) return a.fir.first>b.fir.first;
//			if(a.sec.first!=b.sec.first) return a.sec.first>b.sec.first;
//			if(a.thi.first!=b.thi.first) return a.thi.first>b.thi.first;
//			return true;
//		});
////		for(int i=1;i<=n;i++){
////			printf("i=%d\n\ta[i].fir.first=%d a[i].fir.second=%d\n\ta[i].sec.first=%d a[i].sec.second=%d\n\ta[i].thi.first=%d a[i].thi.second=%d\n\n\n",i,a[i].fir.first,a[i].fir.second,a[i].sec.first,a[i].sec.second,a[i].thi.first,a[i].thi.second);
////		}
//		for(int i=1;i<=n;i++){
//			if(num[a[i].fir.second]<n/2) sum[a[i].fir.second]+=a.fir.first,pq[a[i].fir.first].push(Min1);
//			else{
//				//change itself or let other change
//				int c11=a[i].fir.first-a[i].sec.first;
//				int c21=;
//			}
//		}
//	}
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//}

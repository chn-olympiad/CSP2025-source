#include<cstdio>//some problen on #3, but nerver mind(90-100?)
#include<algorithm>
#include<cstring>
int fr(){
	int c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
using namespace std;
const int N=1e5+5;
struct node{
	pair<int,int> f[2];
	int dx;
}arr[N];
node stk[4][N];
int cnt[4];
bool cmp2(node a,node b){
	return a.dx>b.dx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=fr();
	while(T--){
		memset(cnt,0,sizeof(cnt));
		int n;
		n=fr();
		int a,b,c;
		for(int i=1;i<=n;i++){
			a=fr();b=fr();c=fr();
			int mx=max(a,max(b,c));
			if(mx==a){
				arr[i].f[0]=make_pair(1,a);
				if(max(b,c)==b)
					arr[i].f[1]=make_pair(2,b);
				else
					arr[i].f[1]=make_pair(3,c);
			}
			else if(mx==b){
				arr[i].f[0]=make_pair(2,b);
				if(max(a,c)==a)
					arr[i].f[1]=make_pair(1,a);
				else
					arr[i].f[1]=make_pair(3,c);
			}
			else if(mx==c){
				arr[i].f[0]=make_pair(3,c);
				if(max(a,b)==a)
					arr[i].f[1]=make_pair(1,a);
				else
					arr[i].f[1]=make_pair(2,b);
			}
			arr[i].dx=arr[i].f[0].second-arr[i].f[1].second;
		//	printf("[dx:%d]\n",arr[i].dx);
		}
		for(int i=1;i<=n;i++){
			int will=arr[i].f[0].first;
			stk[will][++cnt[will]]=arr[i];
		}
		int over;
		if(cnt[0]>=max(cnt[1],cnt[2])) over=0;
		else if(cnt[1]>=max(cnt[0],cnt[2])) over=1;
		else over=2;
		if(cnt[over]>n/2){
			sort(stk[over]+1,stk[over]+1+cnt[over],cmp2);
			while(cnt[over]>n/2){
				int ci=stk[over][cnt[over]].f[1].first;
				stk[over][cnt[over]].f[0].second=stk[over][cnt[over]].f[1].second;
				stk[ci][++cnt[ci]]=stk[over][cnt[over]--];
			}
		}
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=cnt[i];j++){
				ans+=stk[i][j].f[0].second;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

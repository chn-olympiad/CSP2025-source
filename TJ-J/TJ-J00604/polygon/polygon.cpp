#include<cstdio>
#include<algorithm>
const int maxn=5005;
const int INF=0x3f3f3f3f,mod=998244353;
int n;
int m;
int a[maxn];
int len1,len2,sum,maxa;
int ans=0;
void dfs(){
	if(len2==m||len1==n){
		if(len2==m){
			if(sum>2*maxa) ans++;
		}
		return;
	}
	sum+=a[++len1];
	int t=maxa;
	len2++;
	if(len2>=1) maxa=std::max(maxa,a[len1]);
	dfs();
	if(len2>=1) maxa=std::min(maxa,t);
	len2--;
	sum-=a[len1--];
	
	len1++;
	dfs();
	len1--;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		m=i;
		sum=0,len1=0,len2=0;
		maxa=-INF;
		dfs();
	}
	printf("%d\n",ans);
	return 0;
}

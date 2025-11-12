#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,cnt,te,vis1[5],vis2[100005];
struct node{
	int x,id,stu;
}a[400005];
bool cmp(node X,node Y){
	return X.x>Y.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0,cnt=0,vis1[1]=1,vis1[2]=1,vis1[3]=1;
		memset(vis2,0,sizeof vis2);
		scanf("%lld",&n);
		for(int i=0;i<n*3;i){
			te=(i+3)/3;
			scanf("%lld",&a[++i].x); a[i].id=1; a[i].stu=te;
			scanf("%lld",&a[++i].x); a[i].id=2; a[i].stu=te;
			scanf("%lld",&a[++i].x); a[i].id=3; a[i].stu=te;
		}
		sort(a+1,a+3*n+1,cmp);
		for(int i=1;i<=3*n;i++){
			if(cnt>=n) break;
			if(vis1[a[i].id]<=n/2&&!vis2[a[i].stu]){
				ans+=a[i].x,cnt++;
				vis1[a[i].id]++;
				vis2[a[i].stu]=1;
			}
		}	
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

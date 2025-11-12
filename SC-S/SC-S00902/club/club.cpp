#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,k,a[N][4],t[N],cnt[4],ans;
vector<int> e[4];
bool cmp(int x,int y){
	return t[x]<t[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n); k=n/2;
		ans=0;
		for(int i=1;i<=3;i++) e[i].clear();
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			int mx1=0;
			if(a[i][1]==mx) mx1=max(a[i][2],a[i][3]);
			else if(a[i][2]==mx) mx1=max(a[i][1],a[i][3]);
			else mx1=max(a[i][1],a[i][2]);
			t[i]=mx-mx1;
//			cout<<t[i]<<endl;
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=max(a[i][3],a[i][2])) e[1].emplace_back(i),ans+=a[i][1];
			else if(a[i][2]>=max(a[i][1],a[i][3])) e[2].emplace_back(i),ans+=a[i][2];
			else e[3].emplace_back(i),ans+=a[i][3];
		}
//		cout<<ans<<endl;
		for(int i=1;i<=3;i++){
			cnt[i]=e[i].size();
			sort(e[i].begin(),e[i].end(),cmp);
		}
		int tmp=max(cnt[1],max(cnt[2],cnt[3]));
		if(tmp<=k){
			printf("%d\n",ans);
			continue;
		}
		int xx=0;
		for(int i=1;i<=3;i++) if(cnt[i]>k) xx=i;
		int tot=0;
		for(int i:e[xx]){
//			cout<<t[i]<<endl;
			ans-=t[i]; tot++;
			if(tmp-tot<=k){
				printf("%d\n",ans);
				break;
			}
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}  
#include<bits/stdc++.h>
using namespace std;
#define maxn 114514
struct abc{
	int satis[4];
}a[maxn];
int n;
int club[4];
int ans;
void dfs(int k,int satis){
	if(k>n){
		ans=max(ans,satis);
		return;
	}
	for(int i=1;i<=3;i++){
		if(club[i]<n/2){
			club[i]++;
			dfs(k+1,satis+a[k].satis[i]);
			club[i]--;
		}
	}
}
bool cmp(abc a,abc b){
	return a.satis[1]>b.satis[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(club,0,sizeof(club));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].satis[1]>>a[i].satis[2]>>a[i].satis[3];
		}
		if(n>200){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].satis[1];
			}
			cout<<ans<<endl;
		}else{
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}

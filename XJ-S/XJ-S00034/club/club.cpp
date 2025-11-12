#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,ans;
int a[N][4];

bool check_spa(){
	for(int i=1;i<=n;i++){
		if(a[i][2] || a[i][3]){
			return 0;
		}
	}
	return 1;
}
int b[N];
bool cmp(int _x1,int _x2){
	return _x1>_x2;
}

void dfs(int k,int cnt1,int cnt2,int cnt3,int tot){
	if(k>n){
		ans=max(ans,tot);
		return;
	}
	if(cnt1 < n/2){
		dfs(k+1,cnt1+1,cnt2,cnt3,tot+a[k][1]);
	}
	if(cnt2 < n/2){
		dfs(k+1,cnt1,cnt2+1,cnt3,tot+a[k][2]);
	}
	if(cnt3 < n/2){
		dfs(k+1,cnt1,cnt2,cnt3+1,tot+a[k][3]);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		ans=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		
		if(check_spa()){
			for(int i=1;i<=n;i++){
				b[i]=a[i][0];
			}
			sort(b+1,b+1+n,cmp);
			int ansa=0;
			for(int i=1;i<=n/2;i++){
				ansa+=b[i];
			}
			printf("%d\n",ansa);
			continue;
		}
		
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
} 

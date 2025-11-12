#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
int a[100005][3],b[100005],c[100005],tot;
int t[3],ans,th;
void solve(){
	t[0]=t[1]=t[2]=0;
	ans=0;tot=0;
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			t[0]++;c[i]=0;
			ans+=a[i][0];
		}
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			t[1]++;c[i]=1;
			ans+=a[i][1];
		}
		else{
			t[2]++;c[i]=2;
			ans+=a[i][2];
		}
	}
	if(t[0]<=n/2&&t[1]<=n/2&&t[2]<=n/2){
		printf("%d\n",ans);
	}
	else{
		if(t[0]>=n/2){
			th=0;	
		}
		if(t[1]>=n/2){
			th=1;	
		}
		if(t[2]>=n/2){
			th=2;	
		}
		for(int i=1;i<=n;i++){
			if(c[i]==th){
				b[++tot]=1e9;
				for(int j=0;j<=2;j++){
					if(j!=th){
						b[tot]=min(b[tot],a[i][th]-a[i][j]);
						
					}
				}
			}
		}
		//cerr<<"\n";
		sort(b+1,b+tot+1,greater<int>());
		while(t[th]>n/2){//cerr<<b[tot]<<" ";
			ans-=b[tot--];//cerr<<t[th];
			t[th]--;
			
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		solve();
	}
	return 0;
}


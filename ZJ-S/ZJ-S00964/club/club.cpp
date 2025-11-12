#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn][3],sta[3][maxn],val[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int top[3]={0,0,0},ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int cur=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=cur;
			if(a[i][0]==cur) sta[0][++top[0]]=i;
			else if(a[i][1]==cur) sta[1][++top[1]]=i;
			else sta[2][++top[2]]=i;
		}
		int lim=(n>>1);
		if(top[0]>lim){
			for(int i=1;i<=top[0];i++){
				int u=sta[0][i];
				val[i]=a[u][0]-max(a[u][1],a[u][2]);
			}
			sort(val+1,val+1+top[0]);
			for(int i=1;i<=top[0]-lim;i++){
				ans-=val[i];
			}
		}
		else if(top[1]>lim){
			for(int i=1;i<=top[1];i++){
				int u=sta[1][i];
				val[i]=a[u][1]-max(a[u][0],a[u][2]);
			}
			sort(val+1,val+1+top[1]);
			for(int i=1;i<=top[1]-lim;i++){
				ans-=val[i];
			}
		}
		else if(top[2]>lim){
			for(int i=1;i<=top[2];i++){
				int u=sta[2][i];
				val[i]=a[u][2]-max(a[u][0],a[u][1]);
			}
			sort(val+1,val+1+top[2]);
			for(int i=1;i<=top[2]-lim;i++){
				ans-=val[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
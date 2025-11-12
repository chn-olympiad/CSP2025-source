#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int x[4],sum[3],s;
}a[200001];
bool cmp(node s1,node s2){
	if(s1.s!=s2.s) return s1.s>s2.s;
	return max(max(s1.x[2],s1.x[1]),s1.x[3])>max(max(s2.x[2],s2.x[1]),s2.x[3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int cnt=0,vis[3];
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			a[i].sum[1]=a[i].x[1]-a[i].x[2];
			a[i].sum[2]=a[i].x[2]-a[i].x[3];
			a[i].s=max(abs(a[i].sum[1]),abs(a[i].sum[2]));
		} 
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			int t;
			int maxx=max(max(a[i].x[1],a[i].x[2]),a[i].x[3]);
			int minn=min(min(a[i].x[1],a[i].x[2]),a[i].x[3]);
			int midd=a[i].x[1]+a[i].x[2]+a[i].x[3]-minn-maxx;
			for(int j=1;j<=3;j++)
				if(maxx==a[i].x[j]) t=j;
			if(vis[t]<int(n/2)){
				cnt+=maxx;
				vis[t]++;
			}
			else{
				for(int j=1;j<=3;j++)
					if(midd==a[i].x[j]) t=j;
				if(vis[t]<int(n/2)){
					cnt+=midd;
					vis[t]++;
				}
				else{
					for(int j=1;j<=3;j++)
						if(minn==a[i].x[j]) t=j;
					if(vis[t]<int(n/2)){
						cnt+=minn;
						vis[t]++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

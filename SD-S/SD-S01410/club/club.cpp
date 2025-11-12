#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
long long t,n,cnt[5];
struct node{
	long long x,index;
}c[N],a[N][5];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].x;
				a[i][j].index=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			c[i].x=a[i][1].x-a[i][2].x;
			c[i].index=i;
		}
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[a[c[i].index][1].index]>=(n/2)){
				ans+=a[c[i].index][2].x;
				cnt[a[c[i].index][2].index]++;
			}
			else{
				ans+=a[c[i].index][1].x;
				cnt[a[c[i].index][1].index]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

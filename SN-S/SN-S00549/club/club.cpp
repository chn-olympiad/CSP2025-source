#include<bits/stdc++.h>
using namespace std;
struct club{
	int x,y,z;
}a[100005];
int cmp(club x,club y){
		return x.x-x.y>y.x-y.y;
}
int b[105],n;
int ans=-1;
int l[15];
void dfs(int d){
	if(d==0){
		cout<<endl;
		int ans2=0;
		for(int i=1;i<=n;i++){
			l[b[i]]++;
			if(l[b[i]]>n/2){
				ans2=0;
				for(int i=1;i<=14;i++){
					l[i]=0;
				}
				return;
			}
			if(b[i]==1){
				ans2+=a[i].x;
			}
			if(b[i]==2){
				ans2+=a[i].y;
			}
			if(b[i]==3){
				ans2+=a[i].z;
			}
		}
		ans=max(ans,ans2);
		for(int i=1;i<=14;i++){
			l[i]=0;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		b[d]=i;
		dfs(d-1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int k=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n>10){
			sort(a+1,a+n+1,cmp);
			int k=0;
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					k+=a[i].x;
				}
				else{
					k+=a[i].y;
				}
			}
			cout<<k;
		}
		else{
			dfs(n);
			cout<<ans;
			ans=-1;
		}
		cout<<'\n';
	}
	return 0;
}

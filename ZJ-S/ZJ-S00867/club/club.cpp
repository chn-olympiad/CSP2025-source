#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],r[4],b[100010],ans;
void dfs(int now,int step){
	if(now==n+1){
		ans=max(ans,step);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(r[i]<n/2){
			r[i]++;
			dfs(now+1,step+a[now][i]);
			r[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		r[1]=0,r[2]=0,r[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				r[1]++;
			}
			if(a[i][1]<=a[i][2]&&a[i][2]>=a[i][3]){
				ans+=a[i][2];
				r[2]++;
			}
			if(a[i][3]>=a[i][2]&&a[i][1]<=a[i][3]){
				ans+=a[i][3];
				r[3]++;
			}
		}
		if(r[1]<=n/2&&r[2]<=n/2&&r[3]<=n/2){
			cout<<ans<<endl;
		}else{
			if(n<=10){
				ans=0;
				r[1]=0,r[2]=0,r[3]=0;
				dfs(1,0);
				cout<<ans;
			}else{
				ans=0;
				for(int i=1;i<=n;i++){
					b[i]=a[i][1];
				}
				sort(b+1,b+n+1);
				for(int i=n;i>=n/2;i--){
					ans+=b[i];
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

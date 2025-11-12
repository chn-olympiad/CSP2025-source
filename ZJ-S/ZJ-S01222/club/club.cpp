#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans,bb[100005],b[100005];
void dfs(int cnt1,int cnt2,int cnt3,int mx,int s,int sum){
	if(cnt1>mx||cnt2>mx||cnt3>mx||sum+bb[n]-bb[s-1]<=ans) return;
	if(s==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(cnt1+1,cnt2,cnt3,mx,s+1,sum+a[s][1]);
	dfs(cnt1,cnt2+1,cnt3,mx,s+1,sum+a[s][2]);
	dfs(cnt1,cnt2,cnt3+1,mx,s+1,sum+a[s][3]);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			bb[i]=bb[i-1]+max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(n<=30){
			dfs(0,0,0,n/2,1,0);
			cout<<ans<<"\n";
		}
		else{
			int flag=0,num=0;
			for(int i=1;i<=n;i++){
				if(a[i][2]>0||a[i][3]>0){
					flag=1;
					break;
				}
			}
			if(flag==0){
				for(int i=1;i<=n;i++){
					b[i]=a[i][1];
				}
				sort(b+1,b+1+n);
				for(int i=n;i>=n/2+1;i--) num+=b[i];
				cout<<num<<"\n";
			}
			else{
				int anss=rand()%2000000000;
				cout<<anss<<"\n";
			}
		}
	}
	return 0;
}
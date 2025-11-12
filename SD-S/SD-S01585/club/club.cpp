#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct node{
	int val,id,zu;
}a[300005];
int n,t,f[201][101][101],dp[100005];
int cnt[4],ans;
bool cmp(node x,node y){
	return x.val>y.val;
}
bool flag[100005],flagk[4],pan2,pan3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=200){
			memset(f,0,sizeof(f));
			for(int gt=1,x,y,z;gt<=n;gt++){
				cin>>x>>y>>z;
				for(int i=0,k;i<=min(n/2,gt);i++){
					for(int j=0;j<=min(n/2,gt);j++){
						k=gt-i-j;
						if(k<0){
							continue;
						}
						if(i>0){
							f[gt][i][j]=max(f[gt-1][i-1][j]+x,f[gt][i][j]);
						}
						if(j>0){
							f[gt][i][j]=max(f[gt-1][i][j-1]+y,f[gt][i][j]);
						}
						if(k>0){
							f[gt][i][j]=max(f[gt-1][i][j]+z,f[gt][i][j]);
						}
//						if(gt==1){
//							cout<<"!!!!!"<<'\n';
//						}
					}
				}
			}
//			for(int gt=1;gt<=n;gt++){
//				cout<<gt<<":_________"<<endl;
//				for(int i=0,k;i<=min(n/2,gt);i++){
//					for(int j=0;j<=min(n/2,gt);j++){
//						k=gt-i-j;
//						if(k<0){
//							continue;
//						}
//						cout<<gt<<" "<<i<<" "<<j<<" "<<f[gt][i][j]<<"   __    ";;
////						anss=max(anss,f[n][i][j]);
//					}
//					cout<<endl;
//				}
//			}
			int anss=0;
			for(int i=0,k;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					k=n-i-j;
					if(k>n/2||k<0){
						continue;
					}
//					cout<<i<<" "<<j<<" "<<f[n][i][j]<<"   __    ";;
					anss=max(anss,f[n][i][j]);
				}
//				cout<<endl;
			}
			cout<<anss<<'\n';
			continue;
		}
		ans=0;
		pan2=1,pan3=1;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>x>>y>>z;
			if(y!=0){
				pan2=0;
			}
			if(z!=0){
				pan3=0;
			}
			a[3*(i-1)+1].id=i;
			a[3*(i-1)+1].val=x;
			a[3*(i-1)+1].zu=1;
			a[3*(i-1)+2].id=i;
			a[3*(i-1)+2].val=y;
			a[3*(i-1)+2].zu=2;
			a[3*(i-1)+3].id=i;
			a[3*(i-1)+3].val=z;
			a[3*(i-1)+3].zu=3;
		}
		if(pan3&&pan2==0){
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int j=min(n/2,i);j>=0;j--){
					if(i-j>n/2){
						continue;
					}
					if(j==0){
						dp[j]=dp[j]+a[3*(i-1)+1].val;
					}
					else{
						dp[j]=max(dp[j]+a[3*(i-1)+1].val,dp[j-1]+a[3*(i-1)+2].val);
					}
//					cout<<i<<" "<<j<<" "<<dp[j]<<'\n';
				} 
			}
			cout<<dp[n/2]<<'\n';
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		memset(flag,0,sizeof(flag));
		memset(flagk,0,sizeof(flagk));
		if(pan2&&pan3){
			sort(a+1,a+1+n*3,cmp);
			for(int i=1;i<=n*3;i++){
				if(flag[a[i].id]){
					continue;
				}
				if(flagk[a[i].zu]){
					continue;
				}
				ans+=a[i].val;
				cnt[a[i].zu]++;
				flag[a[i].id]=1;
				if(cnt[a[i].zu]>=n/2){
					flagk[a[i].zu]=1;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+1+n*3,cmp);
		for(int i=1;i<=n*3;i++){
			if(flag[a[i].id]){
				continue;
			}
			if(flagk[a[i].zu]){
				continue;
			}
			ans+=a[i].val;
			cnt[a[i].zu]++;
			flag[a[i].id]=1;
			if(cnt[a[i].zu]>=n/2){
				flagk[a[i].zu]=1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}



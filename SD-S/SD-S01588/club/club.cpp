#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005][5];
int sum[5];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=3;i++)sum[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][1]){
				sum[1]++;
				ans+=a[i][1];
			}
			if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][2]){
				sum[2]++;
				ans+=a[i][2];
			}
			if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][3]){
				sum[3]++;
				ans+=a[i][3];
			}
		}
		int k;
		int max1=max(sum[1],max(sum[2],sum[3]));
		if(max1==sum[1])k=1;
		if(max1==sum[2])k=2;
		if(max1==sum[3])k=3; 
		int q=sum[k];
		if(q>n/2){
			int p=q-n/2;
			vector<int>s;
			for(int i=1;i<=n;i++){
				if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][k]){
					if(k==3){
						s.push_back(min(a[i][k]-a[i][1],a[i][k]-a[i][2]));
					}
					if(k==2){
						s.push_back(min(a[i][k]-a[i][1],a[i][k]-a[i][3]));
					}
					if(k==1){
						s.push_back(min(a[i][k]-a[i][2],a[i][k]-a[i][3]));
					}
				}
			}
			sort(s.begin(),s.end());
			for(int i=0;i<p;i++){
				ans-=s[i];
			} 
		}
		cout<<ans<<endl; 
	}
	return 0;
}


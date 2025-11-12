#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000086][3],b1,b2,flag,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][1]==a[i][2]==0){
				continue;
			}
			flag=1;
		}
		if(n==2){
			if(a[0][0]>a[0][1]&&a[0][0]>a[0][2]){
				b1=0;
			}else if(a[0][1]>a[0][0]&&a[0][1]>a[0][2]){
				b1=1;
			}else if(a[0][2]>a[0][1]&&a[0][2]>a[0][0]){
				b1=2;
			}if(a[1][0]>a[1][1]&&a[1][0]>a[1][2]){
				b2=0;
			}else if(a[1][1]>a[1][0]&&a[1][1]>a[1][2]){
				b2=1;
			}else if(a[1][2]>a[1][1]&&a[1][2]>a[1][0]){
				b2=2;
			}if(b1!=b2){
				sum+=a[0][b1];
				sum+=a[1][b2];
				cout<<sum;
				continue;
			}else{
				sum+=max(a[0][b1],a[1][b2]);
				if(sum==a[0][b1]){
					if(b1==1){
						sum+=max(a[0][0],a[0][2]);
					}if(b1==2){
						sum+=max(a[0][1],a[0][0]);
					}if(b1==0){
						sum+=max(a[0][2],a[0][1]);
					}
				}else{
					if(b2==1){
						sum+=max(a[1][0],a[1][2]);
					}if(b2==2){
						sum+=max(a[1][1],a[1][0]);
					}if(b2==0){
						sum+=max(a[1][2],a[1][1]);
					}
				}
			}
			cout<<sum<<'\n';
			continue;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
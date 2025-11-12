#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int a[100005][4],k[100005],tt[100005];
priority_queue<int,vector<int>,greater<int> >q[4];
int n;
long long sum=0;
void ff(int ak,int ap){
	for(int i=1;i<=n;i++){
		if(a[i][ap]==ak){
			if(ap==1){
				if(a[i][2]>a[i][3]){
					q[2].push(a[i][2]);
				}else{
					q[3].push(a[i][3]);
				}
			}else if(ap==2){
				if(a[i][1]>a[i][3]){
					q[1].push(a[i][1]);
				}else{
					q[3].push(a[i][3]);
				}
			}else{
				if(a[i][1]>a[i][2]){
					q[1].push(a[i][1]);
				}else{
					q[2].push(a[i][2]);
				}
			}
			
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--){
		int cnt2=0,cnt3=0;
		sum=0;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==0){
				cnt2++;
			}else if(a[i][3]==0){
				cnt3++;
			}
			
			if(a[i][1]>a[i][2]){
				if(a[i][2]>a[i][3]){
					a[i][0]=a[i][1];
					k[i]=1;
				}else if(a[i][2]==a[i][3]){
					a[i][0]=a[i][1];
					k[i]=1;
				}else{
					if(a[i][1]>a[i][3]){
						a[i][0]=a[i][1];
						k[i]=1;
					}else if(a[i][1]==a[i][3]){
						a[i][0]=0;
						k[i]=0;
						sum+=a[i][1];
					}else{
						a[i][0]=a[i][3];
						k[i]=3;
					}
				}
			}else if(a[i][1]==a[i][2]){
				if(a[i][2]>a[i][3]){
					a[i][0]=0;
					k[i]=0;
					sum+=a[i][1];
				}else if(a[i][2]==a[i][3]){
					a[i][0]=0;
					k[i]=0;
					sum+=a[i][1];
				}else{
					a[i][0]=a[i][3];
					k[i]=3;
				}
			}else{
				if(a[i][2]>a[i][3]){
					a[i][0]=a[i][2];
					k[i]=2;
				}else if(a[i][2]==a[i][3]){
					a[i][0]=0;
					k[i]=0;
					sum+=a[i][2];
				}else{
					a[i][0]=a[i][3];
					k[i]=3;
				}
			}
		}
		
		if(n==2){
			cout<<max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))))<<"\n";
			continue;
		}else if(n==4){
			long long ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int f=1;f<=3;f++){
						for(int r=1;r<=3;r++){
							if((i==j&&i==f)||(i==j&&i==r)||(i==r&&i==f)||(j==f&&j==r)){
								continue;
							}
							ans=max(ans,(long long)a[1][i]+a[2][j]+a[3][f]+a[4][r]);
						}
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		
		if(cnt2==n){
			for(int i=1;i<=n;i++){
				tt[i]=a[i][1];
			}
			sort(tt+1,tt+n+1);
			long long ans=0;
			for(int i=n/2+1;i<=n;i++){
				ans+=tt[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		
		for(int i=1;i<=n;i++){
			if(q[1].size()<n/2&&q[2].size()<=n/2&&q[3].size()<=n/2){
				if(k[i]!=0){
					q[k[i]].push(a[i][0]);
				}
			}else{
				if(q[1].size()>=n/2&&k[i]==1){
					if(q[1].top()<a[i][0]){
						ff(q[1].top(),1);
						q[1].pop();
						q[1].push(a[i][0]);
					}else{
						if(a[i][2]>a[i][3]){
							q[2].push(a[i][2]);
						}else{
							q[3].push(a[i][3]);
						}
					}
				}else if(q[2].size()>=n/2&&k[i]==2){
					if(q[2].top()<a[i][0]){
						ff(q[2].top(),2);
						q[2].pop();
						q[2].push(a[i][0]);
					}else{
						if(a[i][1]>a[i][3]){
							q[1].push(a[i][1]);
						}else{
							q[3].push(a[i][3]);
						}
					}
				}else if(q[3].size()>=n/2&&k[i]==3){
					if(q[3].top()<a[i][0]){
						ff(q[3].top(),3);
						q[3].pop();
						q[3].push(a[i][0]);
					}else{
						if(a[i][1]>a[i][2]){
							q[1].push(a[i][1]);
						}else{
							q[2].push(a[i][2]);
						}
					}
				}else{
					if(k[i]!=0){
						q[k[i]].push(a[i][0]);
					}
				}
			}
		}
		
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				sum+=q[i].top();
				q[i].pop();
			}
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,num[200005];
struct node{
	int a,b,c;
}p[200005];

bool cmp(node x,node y){
	return x.a>y.a;
}

bool cmp1(node x,node y){
	return x.b>y.b;
}

bool cmp2(node x,node y){
	return x.c>y.c;
}

bool cmp3(node x,node y){
	return x.a>y.a;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		bool x=1,y=1;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].b!=0)x=0;
			if(p[i].c!=0)y=0;
		}
		
		if(x&&y){
			sort(p+1,p+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=p[i].a;
			}
			cout<<ans<<endl;
		}
		else if(n>200){
			int num=0;
			for(int i=1;i<=n;i++){
				if(p[i].a<=p[i].b&&p[i].a<=p[i].c){
					num+=p[i].a;
					p[i].b=p[i].b-p[i].a;
					p[i].c=p[i].c-p[i].a;
					p[i].a=0;
				}
				else if(p[i].b<=p[i].a&&p[i].b<=p[i].c){
					num+=p[i].b;
					p[i].c=p[i].c-p[i].b;
					p[i].a=p[i].a-p[i].b;
					p[i].b=0;
				}
				else{
					num+=p[i].c;
					p[i].a=p[i].a-p[i].c;
					p[i].b=p[i].b-p[i].c;
					p[i].c=0;
				}
			}
			
			sort(p+1,p+n+1,cmp3);
			int sum1=0,sum2=0,sum3=0,ans3=num;
			for(int i=1;i<=n;i++){
				if(sum1<n/2&&p[i].a>=p[i].b&&p[i].a>=p[i].c){
					ans3+=p[i].a;
					sum1++;
				}
				else if(sum2<n/2&&p[i].b>=p[i].c){
					ans3+=p[i].b;
					sum2++;
				}
				else{
					if(sum3<n/2){
						ans3+=p[i].c;
						sum3++;
					}
					else{
						if(sum1<n/2&&sum2<n*2){
							if(p[i].b>=p[i].a){
								ans3+=p[i].b;
								sum2++;
							}
							else{
								ans3+=p[i].a;
								sum1++;
							}
						}
						else if(sum2<n/2){
							ans3+=p[i].b;
							sum2++;
						}
						else{
							ans3+=p[i].a;
							sum1++;	
						}
					}
				}
			}
			
			sort(p+1,p+n+1,cmp1);
			sum1=0,sum2=0,sum3=0;
			int ans1=num;
			for(int i=1;i<=n;i++){
				if(sum2<n/2&&p[i].b>=p[i].a&&p[i].b>=p[i].c){
					ans1+=p[i].b;
					sum2++;
				}
				else if(sum3<n/2&&p[i].c>=p[i].a){
					ans1+=p[i].c;
					sum3++;
				}
				else{
					if(sum1<n/2)sum1++;
					else{
						if(sum2<n/2&&sum3<n*2){
							if(p[i].b>=p[i].c){
								ans1+=p[i].b;
								sum2++;
							}
							else{
								ans1+=p[i].c;
								sum3++;
							}
						}
						else if(sum2<n/2){
							ans1+=p[i].b;
							sum2++;
						}
						else{
							ans1+=p[i].c;
							sum3++;	
						}
					}
				}
			}
			
			sort(p+1,p+n+1,cmp2);
			sum1=0,sum2=0,sum3=0;
			int ans2=num;
			for(int i=1;i<=n;i++){
				if(sum3<n/2&&p[i].c>=p[i].a&&p[i].c>=p[i].b){
					ans2+=p[i].c;
					sum3++;
				}
				else if(sum2<n/2&&p[i].b>=p[i].a){
					ans2+=p[i].b;
					sum2++;
				}
				else{
					if(sum1<n/2)sum1++;
					else{
						if(sum2<n/2&&sum3<n*2){
							if(p[i].c>=p[i].b){
								ans2+=p[i].b;
								sum2++;
							}
							else{
								ans2+=p[i].c;
								sum3++;
							}
						}
						else if(sum2<n/2){
							ans2+=p[i].b;
							sum2++;
						}
						else{
							ans2+=p[i].c;
							sum3++;	
						}
					}
				}
			}
			
			cout<<max(ans3,max(ans1,ans2))<<endl;
		}
		else{
			int dp[205][205][205]={0};
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=min(n/2,i-j);k++){
						if(j>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j-1][k][i-j-k]+p[i].a);
						if(k>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k-1][i-j-k]+p[i].b);
						if(i-j-k>0)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k][i-j-k-1]+p[i].c);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(n-j-i<=n/2)ans=max(ans,dp[i][j][n-i-j]);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

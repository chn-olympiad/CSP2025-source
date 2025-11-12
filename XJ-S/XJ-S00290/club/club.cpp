#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=7009;
int t;
struct f{
	int id2=0,val=0;
}pd[4];
struct q1{
	int u=0,v=0,w=0;
}a[maxn]={}; 
struct q{
	int x=0,y=0,z=0;
	int ma=0;
}dp[maxn][3]={}; 

bool cmp1(f e1,f e2){
	if(e1.val<e2.val){
		return 0;
	}
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			int o,p,q4;
			cin>>o>>p>>q4;
			a[j].u=o;
			a[j].v=p;
			a[j].w=q4;
		}
		pd[0].val=a[1].u,pd[0].id2=1;
		pd[1].val=a[1].v,pd[1].id2=2;
		pd[2].val=a[1].w,pd[2].id2=3;
		sort(pd,pd+3,cmp1);
		dp[1][0].x=1,dp[1][1].y=1,dp[1][1].z=1;
		dp[1][0].ma=pd[0].val;
		dp[1][1].ma=pd[1].val;
		dp[1][2].ma=pd[2].val;
		int valma=pd[0].val;
		for(int j=2;j<=n;j++){	
			pd[0].val=a[j].u,pd[0].id2=1;
			pd[1].val=a[j].v,pd[1].id2=2;
			pd[2].val=a[j].w,pd[2].id2=3;
			sort(pd,pd+3,cmp1);
			int v1=pd[0].id2,v2=pd[1].id2,v3=pd[2].id2;
			//cout<<"dsjflfjd  "<<v1<<" "<<v2<<" "<<v3<<endl;
			for(int w2=0;w2<=2;w2++){
				if(v1==1 and v2==2 and v3==3){
					//cout<<dp[j][w2].x<<endl;
					if(dp[j-1][w2].x+1<=n/2){
						dp[j][w2].ma=dp[j-1][w2].ma+pd[0].val;
						dp[j][w2].x++;
						//cout<<dp[j][w2].x<<endl;
					}
					else if(dp[j-1][w2].x+1>n/2){
						if(dp[j-1][w2].y+1<=n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[1].val;
							dp[j][w2].y++;
						}
						else if(dp[j-1][w2].y+1>n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[2].val;
							dp[j][w2].z++;
						}
					}
				}
				else if(v1==1 and v2==3 and v3==2){
					if(dp[j-1][w2].x+1<=n/2){
						dp[j][w2].ma=dp[j-1][w2].ma+pd[0].val;
						dp[j][w2].x++;
					}
					else if(dp[j-1][w2].x+1>n/2){
						if(dp[j-1][w2].z+1<=n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[2].val;
							dp[j][w2].z++;
						}
						else if(dp[j-1][w2].z+1>n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[1].val;
							dp[j][w2].y++;
						}
					}
				}
				if(v1==3 and v2==1 and v3==2){
					if(dp[j-1][w2].y+1<=n/2){
						dp[j][w2].ma=dp[j-1][w2].ma+pd[1].val;
						dp[j][w2].y++;
					}
					else if(dp[j-1][w2].y+1>n/2){
						if(dp[j-1][w2].z+1<=n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[2].val;
							dp[j][w2].z++;
						}
						else if(dp[j-1][w2].z+1>n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[0].val;
							dp[j][w2].x++;
						}
					}
				}
				if(v1==3 and v2==2 and v3==1){
					if(dp[j-1][w2].z+1<=n/2){
						dp[j][w2].ma=dp[j-1][w2].ma+pd[2].val;
						dp[j][w2].z++;
					}
					else if(dp[j-1][w2].z+1>n/2){
						if(dp[j-1][w2].y+1<=n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[1].val;
							dp[j][w2].y++;
						}
						else if(dp[j-1][w2].y+1>n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[0].val;
							dp[j][w2].x++;
						}
					}
				}
				if(v1==2 and v2==3 and v3==1){
					if(dp[j-1][w2].z+1<=n/2){
						dp[j][w2].ma=dp[j-1][w2].ma+pd[2].val;
						dp[j][w2].z++;
					}
					else if(dp[j-1][w2].z+1>n/2){
						if(dp[j-1][w2].x+1<=n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[0].val;
							dp[j][w2].x++;
						}
						else if(dp[j-1][w2].x+1>n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[1].val;
							dp[j][w2].y++;
						}
					}
				}
				if(v1==2 and v2==1 and v3==3){
					if(dp[j-1][w2].y+1<=n/2){
						dp[j][w2].ma=dp[j-1][w2].ma+pd[1].val;
						dp[j][w2].y++;
					}
					else if(dp[j-1][w2].y+1>n/2){
						if(dp[j-1][w2].x+1<=n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[0].val;
							dp[j][w2].x++;
						}
						else if(dp[j-1][w2].x+1>n/2){
							dp[j][w2].ma=dp[j-1][w2].ma+pd[2].val;
							dp[j][w2].z++;
						}
					}
				}
				
				//cout<<dp[j][0].ma<<" "<<dp[j][1].ma<<" "<<dp[j][2].ma<<endl;
			
			}
		}
		cout<<max(dp[n][0].ma,max(dp[n][1].ma,dp[n][2].ma))<<endl;
		
	}
	return 0;
} 
//我真没想到我会考0分 怎么会啊 

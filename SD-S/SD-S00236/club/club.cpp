#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
struct node{
	int w;
	bool operator<(const node &x)const{
		return x.w>w;
	} 
};
int a[N][5];
priority_queue<node> q[4][4];//hou gei qian 
void so(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			while(q[i][j].size()){
				q[i][j].pop();
			}
		}
	}
	int n;cin>>n;
	int sm23=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		sm23+=a[i][3];
	}
	int ans=0;
	int cx1=0,cx2=0,cx3=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			if(cx1==n/2){
				bool tf=0;
				int as=ans+max(a[i][2],a[i][3]);
				if(q[1][2].top().w>q[1][3].top().w){
					if(ans+q[1][2].top().w+a[i][1]>as){
						ans=ans+q[1][2].top().w+a[i][1];
						q[1][2].pop();
						cx2++;tf=1;
						q[1][2].push({-a[i][1]+a[i][2]});
					}
				}
				else{
					if(ans+q[1][3].top().w+a[i][1]>as){
						ans=ans+q[1][3].top().w+a[i][1];
						q[1][3].pop();
						cx3++;tf=1;
						q[1][3].push({-a[i][1]+a[i][3]});
					}
				}
				if(!tf){
					ans=as;
				}
			}
			else{
				ans+=a[i][1];
				q[1][2].push({-a[i][1]+a[i][2]});
				q[1][3].push({-a[i][1]+a[i][3]});
				cx1++;
			}
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			if(cx2==n/2){
				bool tf=0;
				int as=ans+max(a[i][1],a[i][3]);
				if(q[2][1].top().w>q[2][3].top().w){
					if(ans+q[2][1].top().w+a[i][2]>as){
						ans=ans+q[2][1].top().w+a[i][2];
						q[2][1].pop();
						cx1++;tf=1;
						q[2][1].push({-a[i][2]+a[i][1]});
					}
				}
				else{
					if(ans+q[2][3].top().w+a[i][2]>as){
						ans=ans+q[3][2].top().w+a[i][2];
						q[2][3].pop();
						cx3++;tf=1;
						q[2][3].push({-a[i][2]+a[i][3]});
					}
				}
				if(!tf){
					ans=as;
				}
			}
			else{
				ans+=a[i][2];
				q[2][1].push({-a[i][2]+a[i][1]});
				q[2][3].push({-a[i][2]+a[i][3]});
				cx2++;
			}
		}
		else{
			if(cx3==n/2){
				bool tf=0;
				int as=ans+max(a[i][1],a[i][2]);
//				cout<<as<<endl;
//				cout<<ans+q[3][2].top().w+a[i][3]<<endl;
				if(q[3][1].top().w>q[3][2].top().w){
					if(ans+q[3][1].top().w+a[i][3]>as){
						ans=ans+q[3][1].top().w+a[i][3];
						q[3][1].pop();
						cx1++;tf=1;
						q[3][1].push({-a[i][3]+a[i][1]});
					}
				}
				else{
					if(ans+q[3][2].top().w+a[i][3]>as){
						ans=ans+q[3][2].top().w+a[i][3];
						q[3][2].pop();
						cx2++;tf=1;
						q[3][2].push({-a[i][3]+a[i][2]});
					}
				}
				if(!tf){
					ans=as;
				}
			}
			else{
				ans+=a[i][3];
				q[3][1].push({-a[i][3]+a[i][1]});
				q[3][2].push({-a[i][3]+a[i][2]});
				cx3++;
			}
		}
//		cout<<ans<<endl; 
//		cout<<i<<" "<<cx1<<" "<<cx2<<" "<<cx3<<endl;
	}
//	cout<<q[1].size()<<" "<<q[2].size()<<" "<<q[3].size()<<endl;
//	cout<<cx1<<" "<<cx2<<" "<<cx3<<endl;
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
//	t=1;
	for(int i=1;i<=t;i++){
		so();
	}
	return 0;
}


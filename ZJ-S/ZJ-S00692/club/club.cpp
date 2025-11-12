#include <bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int x;
	int y;
	int z;
	int lost;
}a[100005];
int sum[5];
int T;
int n;
int gr[5][100005];
void get_prefer(int i){
	if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
		gr[1][i]=1;
		a[i].lost=min(a[i].x-a[i].y,a[i].x-a[i].z);
	}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
		gr[2][i]=1;
		a[i].lost=min(a[i].y-a[i].x,a[i].y-a[i].z);//a[i].lost:the max of a[i]-the second max of a[i] 
	}else{
		gr[3][i]=1;
		a[i].lost=min(a[i].z-a[i].y,a[i].z-a[i].x);
	}
}
bool cmp(node a,node b){
	return a.lost<b.lost;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=3;i++){
			sum[i]=0;
			for(int j=1;j<=n;j++){
				gr[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].id=i;	
		}
		for(int i=1;i<=n;i++){
			get_prefer(i);
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				sum[i]+=gr[i][j];
			}
		}
		long long ans=0;
		for(int j=1;j<=n;j++){
				if(gr[1][j])ans+=a[j].x;
				if(gr[2][j])ans+=a[j].y;
				if(gr[3][j])ans+=a[j].z;
		}
		if(sum[1]<=n/2&&sum[2]<=n/2&&sum[3]<=n/2){
			cout<<ans<<endl;
		}else{
//			cout<<"else"<<endl;
			int total_lost=0;
			for(int i=1;i<=3;i++){
				if(sum[i]>=n/2){
					int k=sum[i];//the number  of max-people group(>n/2)
					sort(a+1,a+1+n,cmp);
					for(int j=1;j<=n;j++){
						if(gr[i][a[j].id]){
							total_lost+=a[j].lost;
//							cout<<"ai lost"<<a[j].lost<<endl;
							k--;
							if(k==n/2)break;
						}
					}
				}
			}
			cout<<ans-total_lost<<endl;	
		}
	}
	return 0;
}

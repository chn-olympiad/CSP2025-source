#include<iostream>
#include<cmath>

using namespace std;

const int N=1e5+5;
int t,n,a[N][8],top1,top2,top3,mx,mxid,tt1,tt2,tt3,ans,flagtt;

int od(int i,int p,int sum1,int sum2,int sum3){
	if(sum1>n/2||sum2>n/2||sum3>n/2||i>n){
		return 0;
	}
	if(i==0){
		return max(max(od(i+1,1,sum1+1,sum2,sum3),od(i+1,2,sum1,sum2+1,sum3)),od(i+1,3,sum1,sum2,sum3+1));
	}
	return a[i][p]+max(max(od(i+1,1,sum1+1,sum2,sum3),od(i+1,2,sum1,sum2+1,sum3)),od(i+1,3,sum1,sum2,sum3+1));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		top1=top2=top3=tt1=tt2=tt3=ans=flagtt=mx=mxid=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]){
				a[i][4]=1;
				flagtt++;
			}else{
				a[i][4]=0;
			}
			a[i][5]=abs(a[i][1]-a[i][2]);
			top1=max(top1,a[i][1]);
			top2=max(top2,a[i][2]);
			top3=max(top3,a[i][3]);
		}
		if(top1==0&&top2==0&&top3==0){
			cout<<0<<endl;
			return 0;
		}
		if(top2==0&&top3==0){
			for(int i=1;i<=n/2;i++){
				mx=mxid=0;
				for(int j=1;j<=n;j++){
					if(a[j][1]>mx){
						mx=a[j][1];
						mxid=j;
					}
				}
				ans+=a[mxid][1];
				a[mxid][1]=-1;
			}
		}else if(top3==0){
			if(flagtt>n/2){
				for(int i=1;i<=n/2;i++){
					mx=mxid=0;
					for(int j=1;j<=n;j++){
						if(a[j][5]>mx&&a[j][4]==1){
							mx=a[j][5];
							mxid=j;
						}
					}
					ans+=a[mxid][1];
					a[mxid][4]=2;
				}
				for(int i=1;i<=n;i++){
					if(a[i][4]!=2){
						ans+=a[i][2];
					}
				}
			}else{
				for(int i=1;i<=n/2;i++){
					mx=mxid=0;
					for(int j=1;j<=n;j++){
						if(a[j][5]>mx&&a[j][4]==0){
							mx=a[j][5];
							mxid=j;
						}
					}
					ans+=a[mxid][2];
					a[mxid][4]=2;
				}
				for(int i=1;i<=n;i++){
					if(a[i][4]!=2){
						ans+=a[i][1];
					}
				}
			}
		}else{
			ans=od(0,0,0,0,0);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


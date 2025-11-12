#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100005;
int a[N][4];
int ans[N];
int oa[N],ob[N];
int max[N];
bool tpa=1;
bool tpb=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int sum=0;
		int sumx=0,sumy=0;
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)ans[j]=0;
		
		int lim=n/2;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
				if(k==1)sumx+=a[j][k];
				if(k==2)sumy+=a[j][k];	}
		}
		for(int j=1;j<=n;j++){
			if(a[j][3]!=0){
				tpb=0;
				break;
			}
			if(a[j][1]!=0){
				tpa=0;
			}
		}
		if(tpa==1&&tpb==1){
			for(int j=1;j<=n;j++){
				ans[j]=a[j][2];
			}
			sort(ans+1,ans+1+n);
			for(int j=lim+1;j<=n;j++){
				sum+=ans[j];
			}
			cout<<sum<<endl;
		}
		else cout<<sumy<<endl;
	}
	return 0;
}
 

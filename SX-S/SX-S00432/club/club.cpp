#include<bits/stdc++.h>
using namespace std;
int t,n,maxn=INT_MIN,mj,mj1,ans,c[4];
struct my{
	int a;
}arr[100005][4];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0,c[1]=0,c[2]=0,c[3]=0,maxn=INT_MIN;
		for(int j=1;j<=n;j++){
			cin>>arr[j][1].a>>arr[j][2].a>>arr[j][3].a;
		}
		for(int j=1;j<=n;j++){
			for(int j1=1;j1<=3;j1++){
				if(maxn<arr[j][j1].a&&arr[j][j1].a!=-1){
					maxn=arr[j][j1].a;
					mj=j;
					mj1=j1;
				}
			}
		}
		while(maxn!=-1){
			//printf("maxn:%d mj:%d mj1:%d ans:%d c1:%d c2:%d c3:%d\n",maxn,mj,mj1,ans,c[1],c[2],c[3]);
			if(c[mj1]<n/2){
				ans+=maxn;
				arr[mj][1].a=-1;
				arr[mj][2].a=-1;
				arr[mj][3].a=-1;
				c[mj1]++;
			}
			if(c[mj1]>=n/2){
				arr[mj][mj1].a=-1;
			}
			maxn=INT_MIN;
			for(int j=1;j<=n;j++){
				for(int j1=1;j1<=3;j1++){
					if(maxn<arr[j][j1].a){
						maxn=arr[j][j1].a;
						mj=j;
						mj1=j1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int p=0,t,n,maxn=INT_MIN,mj,mj1,ans,c[4],max2n=INT_MIN,m2j,m2j1,_max2n=INT_MIN,_m2j,_m2j1;
struct my{
	int a;
}arr[100005][4];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0,c[1]=0,c[2]=0,c[3]=0,maxn=INT_MIN;
		for(int j=1;j<=n;j++){
			cin>>arr[j][1].a>>arr[j][2].a>>arr[j][3].a;
		}
		for(int j=1;j<=n;j++){
			for(int j1=1;j1<=3;j1++){
				if(maxn<arr[j][j1].a&&arr[j][j1].a!=-1){
					maxn=arr[j][j1].a;
					mj=j;
					mj1=j1;
				}
			}
		}
		while(maxn!=-1&&p<=n){
			printf("maxn:%d mj:%d mj1:%d ans:%d c1:%d c2:%d c3:%d\n",maxn,mj,mj1,ans,c[1],c[2],c[3]);
			if(c[mj1]<n/2&&maxn>=_max2n+max2n){
				ans+=maxn;
				arr[mj][1].a=-1;
				arr[mj][2].a=-1;
				arr[mj][3].a=-1;
				c[mj1]++;
				p++;
			}
			else if(c[_m2j1]<n/2&&c[m2j1]<n/2&&maxn<_max2n+max2n){
				ans+=_max2n;
				ans+=max2n;
				arr[m2j][1].a=-1;
				arr[m2j][2].a=-1;
				arr[m2j][3].a=-1;
				c[m2j1]++;
				arr[_m2j][1].a=-1;
				arr[_m2j][2].a=-1;
				arr[_m2j][3].a=-1;
				c[_m2j1]++;
				p+=2;
			}
			else{
				arr[mj][mj1].a=-1;
			}
			maxn=INT_MIN;
			for(int j=1;j<=n;j++){
				for(int j1=1;j1<=3;j1++){
					if(maxn<arr[j][j1].a){
						maxn=arr[j][j1].a;
						mj=j;
						mj1=j1;
					}
					if(_max2n<arr[j][j1].a&&_max2n<maxn&&j==mj){
						_max2n=arr[j][j1].a;
						_m2j=j;
						_m2j1=j1;
					}
					if(max2n<arr[j][j1].a&&max2n<maxn&&j!=mj){
						max2n=arr[j][j1].a;
						m2j=j;
						m2j1=j1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int dp[n][1030],t,n,a[n][4],i_,j_;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int i1=1;i1<=t;i1++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(i1==1){
			int maxn=INT_MIN;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(maxn<a[i][j]){
						maxn=a[i][j];
					}
				}
			}
			dp[1][1]=maxn;
		}
		else{
			for(int _1=1;_1<=j;_1+=2){
				int maxn=INT_MIN;
				for(int i=1;i<=n;i++){
					if(maxn<a[_1][i]){
						maxn=a[_1][i];
					}
				}
				dp[i1][_1]=maxn+dp[i1-1][_1];
				
			}
		}
	}
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int T;
int p(int a,int b,int c){
	if(a>=b&&a>=c)return 1;
	if(b>=a&&b>=c)return 2;
	if(c>=a&&c>=b)return 3;
	return 0;
}
int maxs(int a,int b,int c){
	if((a>=b&&b>=c)||(c>=b&&b>=a)){
		return b;
	}
	else if((b>=a&&a>=c)||(a>=b&&c>=a)){
		return a;
	}
	return c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T){
		int n,a[100005][4];//入 
		int minn=0;//n/2组 
		int m[4],t[50005],sum=0,ans=0;//统计所有 
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
			t[i]=0;
		}//初始化
		m[0]=m[1]=m[2]=m[3]=0;
		for(int i=1;i<=n;i++){
			m[p(a[i][1],a[i][2],a[i][3])]++;
			a[i][0]=p(a[i][1],a[i][2],a[i][3]);
		}
		if(m[1]>=n/2||m[2]>=n/2||m[3]>=n/2){
			int y=p(m[1],m[2],m[3]);
			int k=max(max(m[1],m[2]),m[3])-(n/2);
			for(int i=1;i<=n;i++){
				sum+=max(max(a[i][1],a[i][2]),a[i][3]);
				t[i]=max(max(a[i][1],a[i][2]),a[i][3])-maxs(a[i][1],a[i][2],a[i][3]);
				if(a[i][0]!=y){
					t[i]=0x7fffffff;
				}
			}//k个t[i] 的最小值 
			sort(t+1,t+n+1);
			for(int i=1;i<=k;i++){
				minn+=t[i];
			}
			ans=sum-minn;
		}
		else{
			for(int i=1;i<=n;i++){
				sum+=max(max(a[i][1],a[i][2]),a[i][3]);
			}
			ans=sum;
		}
		cout<<ans<<endl;
//		cout<<sum<<endl;
//		cout<<minn<<endl;
//		cout<<m[1]<<" "<<m[2]<<" "<<m[3]<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<max(max(a[i][1],a[i][2]),a[i][3])<<" "<<max(max(a[i][1],a[i][2]),a[i][3])-maxs(a[i][1],a[i][2],a[i][3])<<"="<<t[i]<<endl;
//			
//		}
		T--;
	}
	return 0;
}

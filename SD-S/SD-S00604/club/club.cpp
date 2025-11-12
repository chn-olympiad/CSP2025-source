#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[100010][10],b[10][100010],x[100010],t,n,idx,idx1,idx2,idx3,ans; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		idx1=0,idx2=0,idx3=0,idx=0,ans=0;
		memset(b,0,sizeof(b));
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) b[1][i]++,idx1++,ans+=a[i][1];
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]) b[2][i]++,idx2++,ans+=a[i][2];
			else b[3][i]++,idx3++,ans+=a[i][3];
		}
		if(idx1>n/2){
			for(int i=1;i<=n;i++){
				if(b[1][i]==1){
					x[++idx]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
			}
			sort(x+1,x+idx+1);
			for(int i=1;i<=idx1-n/2;i++) ans-=x[i];
		}
		else if(idx2>n/2){
			for(int i=1;i<=n;i++){
				if(b[2][i]==1){
					x[++idx]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
			} 
			sort(x+1,x+idx+1);
			for(int i=1;i<=idx2-n/2;i++) ans-=x[i];
		}
		else if(idx3>n/2){
			for(int i=1;i<=n;i++){
				if(b[3][i]==1){
					x[++idx]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
				}
			} 
			sort(x+1,x+idx+1);
			for(int i=1;i<=idx3-n/2;i++) ans-=x[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

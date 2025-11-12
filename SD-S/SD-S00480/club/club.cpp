#include<bits/stdc++.h>
using namespace std;
int t,n,a[100050][5],b[100050];
long long sum,ans[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;++k){
		sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(a[1][2]==0&&a[1][3]==0){
			for(int i=1;i<=n;++i){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=n;++i){
				a[i][1]=b[i];
			}
			for(int i=(n/2)+1;i<=n;++i){
				sum+=a[i][1];
			}
		}
		else{
			for(int i=1;i<=n;++i){
				sum+=max(max(a[i][1],a[i][2]),a[i][3]);
			}
		}
		ans[k]=sum;
	}
	for(int k=1;k<=t;++k){
		cout<<ans[k]<<endl;
	}
	return 0; 
}

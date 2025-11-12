#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],f=1;
long long d[100005],cnt;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(j==1) cin>>a[i];
				else if(j==2) {
					cin>>b[i];
					if(b[i]!=0) f=0;
				}
				else{
					cin>>c[i];
					if(c[i]!=0) f=0;
				}
			}
		}
		if(n==2){
			cout<<max(max(a[1]+b[2],a[1]+c[2]), max(max(a[2]+b[1],a[2]+c[1]),max(b[1]+c[2],b[2]+c[1])));
		}else if(f==1){
			int y=n/2;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=y;i++){
				cnt+=a[i];
			}
			cout<<cnt<<"\n";
		}else{
			for(int i=1;i<=n;i++){
				cnt+=max(max(a[i],b[i]),c[i]);
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}

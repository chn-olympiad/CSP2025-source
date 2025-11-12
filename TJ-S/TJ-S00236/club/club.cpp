#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n=0,d=0,f=0,g=0,a[100005],ans=0;
		cin>>n;
		cin>>d>>f>>g;
		if(n==2){
			int z,x,c;
			cin>>z>>x>>c;
			int l[6]={d+x,d+c,f+z,f+c,g+z,g+x};
			for(int i=0;i<6;i++){
				ans=max(ans,a[i]);
			}
		}else if(g==0 and f==0){
			int a[100005];
			a[0]=d;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			sort(a,a+n);
			for(int i=n;i>=n/2;i--){
				ans+=a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

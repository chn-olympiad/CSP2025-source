#include<bits/stdc++.h>
using namespace std;
int t,f=0;
int n;
struct E{
	int a1,a2,a3;
}a[500005];
int x[500005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a3!=0||a[i].a2!=0){
				f=1;
			}
		}
		if(f==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				x[i]=a[i].a1;
			}
			sort(x+1,x+n+1);
			for(int i=n;i>n/2;i--){
				ans+=x[i];
				cout<<ans<<" ";
			}
			cout<<ans;
		}else{
			cout<<a[1].a1;
		}
	}
	return 0;
}

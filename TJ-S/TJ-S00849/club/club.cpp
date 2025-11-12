#include<bits/stdc++.h>
using namespace std;
const int N=210;
int t,n;
long long ans,maxn;
int c[3];
bool flag[N][3];
struct aaa{
	int a1,a2,a3,vau;
};
aaa a[N];
bool ff(aaa a1,aaa a2){
	return a1.vau>a2.vau;
}
int main(){
	freopen("club.in",-r,stdin);
	freopen("club.out",-s,stdin);
	cin>>t;
	for(int o=1;o<=t;o++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].vau=a[i].a1+a[i].a2+a[i].a3;
		}
		sort(a+1,a+1+n,ff);
		cout<<a[1].vau<<" "<<a[2].vau<<" ";
		for(int i=1;i<=n;i++){
			if(c[1]+1<=n/2){
				if((a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)||(c[2]=n/2&&a[i].a1>=a[i].a3)||(c[3]=n/2&&a[i].a1>=a[i].a2)){
					ans+=a[i].a1;
					c[1]++;
					continue;
				}
			}if(c[2]+1<=n/2){
				if((a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)||(c[1]=n/2&&a[i].a2>=a[i].a3)||(c[3]=n/2&&a[i].a2>=a[i].a1)){
					ans+=a[i].a2;
					c[2]++;
					continue;
				}
			}if(c[3]+1<=n/2){
				if((a[i].a3>=a[i].a1&&a[i].a3>=a[i].a2)||(c[2]=n/2&&a[i].a3>=a[i].a1)||(c[2]=n/2&&a[i].a3>=a[i].a1)){
					ans+=a[i].a3;
					c[3]++;
					continue;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

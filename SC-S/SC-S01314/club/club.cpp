#include<bits/stdc++.h>
using namespace std;
struct qw{
	int a[5];
	int maxn=0;
	int maxn1;
};
int p[100005];
qw a[10000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int pd=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].a[j];
				if(j==2&&a[i].a[j]!=0)pd=1;
				if(a[i].a[j]>a[i].maxn){
					a[i].maxn=a[i].a[j];
					a[i].maxn1=j;
				}
				
			}
		}
		if(n==2){
			int h=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j)continue;
					int ls=a[1].a[i]+a[2].a[j];
					if(ls>h)h=ls;
				
				}
			}
			cout<<h<<endl;
		}
		else if(pd==0){
			for(int i=1;i<=n;i++){
				p[i]=a[i].maxn;
			}
			sort(p+1,p+n+1);
			int h=0;
			cout<<n/2<<endl;
			int g;
			if(n%2==0)g=n/2;
			else g=n/2+1;
			for(int i=n;i>g;i--){
				h+=p[i];
			}
			cout<<h<<endl;
		}
		else{
			int h=0;
			for(int i=n;i>=1;i--){
				h+=a[i].maxn;
			}
			cout<<h<<endl;
		}
	}
	return 0;
} 
#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005];
int b[100005];
int c[100005];
int sum=-1;
void fac(int count,int t1,int t2,int t3){
	if((t1>=n/2&&t2>=n/2&&t3>=n/2) || (t1+t2+t3)>=n) {
		sum=max(count,sum);
		return ;
	}
	if(t1+1<=n/2) {
		fac(count+a[t1+t2+t3+1],t1+1,t2,t3);
	}
	if(t2+1<=n/2) {
		fac(count+b[t1+t2+t3+1],t1,t2+1,t3); 
	}
	if(t3+1<=n/2) {
		fac(count+c[t1+t2+t3+1],t1,t2,t3+1); 
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int p=1;p<=T;p++) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			cin>>a[i]>>b[i]>>c[i];
		}
		sum=-1;
		fac(0,0,0,0);
		cout<<sum<<endl;
	}
return 0;
}
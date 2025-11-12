#include<bits/stdc++.h>
using namespace std;
int a[9999],b[9999],n,c,xz;

void gg(int g,int d,int sum){
	if(d>=xz){
		if(sum>2*b[d-1]) {
//			for(int i=1;i<=d-1;i++) cout<<b[i]<<" ";
//			cout<<"\n";
			c=(c+1)%998244353;
		}
		
		return ;
	}
	for(int i=g+1;i<=n;i++){
		b[d]=a[i];
		gg(i,d+1,sum+a[i]);
	}
	
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=4;i<=n+1;i++) {
		xz=i;
		gg(0,1,0);
	}
	cout<<c;
	
	return 0;
}


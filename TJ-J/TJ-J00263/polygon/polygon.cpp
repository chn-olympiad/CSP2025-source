#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],b[5005];
long long z;
void xh(int sh){
	if(sh==0){ 
		int d=0,h=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				h+=a[i];
				d=max(d,a[i]);
			}
		}
		if(h>(2*d)){
			z++;
		}
	}
	else{
		b[sh]=1;
		xh(sh-1);
		b[sh]=0;
		xh(sh-1);
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	xh(n);
	cout<<z;
	return 0;
}

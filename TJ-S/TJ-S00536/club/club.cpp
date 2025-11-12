#include <bits/stdc++.h>
using namespace std;
int t,x,k,h,d;
int a[10005],b[10005],c[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x;
		if(x==2){
			for(int j=1;j<=2;j++){
				cin>>a[j]>>b[j]>>c[j];
				if(d==1) k+=max(b[i],c[i]);
				if(d==2) k+=max(a[i],c[i]);
				if(d==3) k+=max(b[i],c[i]);
				if(a[i]>max(b[i],c[i]) and d==0) {
					k+=a[i];
					d=1;
				}
				if(b[i]>max(a[i],c[i]) and d==0){
					k+=b[i];
					d=2;
				}
				if(c[i]>max(b[i],a[i]) and d==0){
					k+=c[i];
					d=3;
				}
			}
		}
		else{
			for(int j=1;j<=x;j++){
				cin>>a[j]>>b[j]>>c[j];
				if(b[j]==0 and c[j]==0) h++;
			}
			if(h==x){
				sort(a+1,a+1+x);
				for(int j=x;j>x/2;j--){
					k+=a[j];
				}
			}
		}
		cout<<k<<endl;
		k=0;
		h=0; 
		d=0;
	} 
	return 0;
}

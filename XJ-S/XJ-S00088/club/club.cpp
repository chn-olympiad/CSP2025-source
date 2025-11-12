#include<bits/stdc++.h>
using namespace std;
int t,ma,a[4];
int f(){
	for(int i=1;i<=3;i++){
		if(ma==a[i]) return i;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n=0,b[4]={0,0,0,0},m=0,h=0;
		cin>>n;
		h=n/2;
		while(n--){
			for(int j=1;j<=3;j++){
				cin>>a[j];
			}
			ma=0;
			ma=max(a[1],a[2]);
			ma=max(ma,a[3]);
			if(b[f()]<h){
				b[f()]++;
			}else if(b[f()]==h){
				if(f()==1){
					ma=max(a[2],a[3]);
				}else if(f()==2){
					ma=max(a[1],a[3]);
				}else if(f()==3){
					ma=max(a[2],a[1]);
				}
			}
			m+=ma;
		}
		cout<<m<<endl;
	}
	return 0;
}

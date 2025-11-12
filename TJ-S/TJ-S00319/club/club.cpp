#include<bits/stdc++.h>;
using namespace std;
long long t,a[100900],b[100900],c[100900],ma_a=-1,ma_b=-1;
long long ma_c=-1,pa,pb,pc,n;
long long d[110][110],e[110][110],f[110][110];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		if(n==2){
			cin>>a[1]>>a[2]>>a[3];
			cin>>b[1]>>b[2]>>b[3];
			for(int i=1;i<=3;i++){
				if(a[i]>ma_a){
					pa=i;
					ma_a=a[i];
				}
				if(b[i]>ma_b){
					pb=i;
					ma_b=b[i];
				}
			}
			sort(a+1,a+1+n);
			sort(b+1,b+1+n);
			if(pa!=pb) cout<<ma_a+ma_b;
			else{
				if(ma_a+b[2]>ma_b+a[2]){
					cout<<ma_a+b[2];
				}
				else{
					cout<<ma_b+a[2];
				}
			}
		}
		if(n==4){

		}
		if(n==10){
			
		}
		if(n==30){
			
		}
	}
	return 0;
}


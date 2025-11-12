#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t , n , a , b , c , m , ma , ty , aa[100001][4]={} , px[100001]={};
	long long int w;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		w=0;
		m=0;
		a=0;
		b=0;
		c=0;
		for(int j=1;j<=n;j++){
			cin >> aa[j][1] >> aa[j][2] >> aa[j][3];
			w+=max(max(aa[j][1],aa[j][2]),aa[j][3]);
			if(aa[j][1]>=aa[j][2] && aa[j][1]>=aa[j][3]){
				a++;
				aa[j][0]=1;
			}else if(aa[j][2]>=aa[j][1] && aa[j][2]>=aa[j][3]){
				b++;
				aa[j][0]=2;
			}else if(aa[j][3]>=aa[j][1] && aa[j][3]>=aa[j][2]){
				c++;
				aa[j][0]=3;
			}
		}
		if(max(max(a,b),c)<=n/2){
			cout << w << endl;
		}else{
			if(a>n/2){
				for(int q=1;q<=n;q++){
					if(aa[q][0]==1){
						px[m]=aa[q][1]-max(aa[q][2],aa[q][3]);
						m++;
					}
				}
				for(int q=1;q<=a-n/2;q++){
					ma=2111111;
					for(int r=0;r<m-1;r++){
						if(px[r]<ma){
							ty=r;
							ma=px[r];
						}
					}
					w-=ma;
					px[ty]=2111111;
				}
			}
			if(b>n/2){
				for(int q=1;q<=n;q++){
					if(aa[q][0]==2){
						px[m]=aa[q][2]-max(aa[q][1],aa[q][3]);
						m++;
					}
				}
			    for(int q=1;q<=b-n/2;q++){
					ma=2111111;
					for(int r=0;r<m-1;r++){
						if(px[r]<ma){
							ty=r;
							ma=px[r];
						}
					}
					w-=ma;
					px[ty]=2111111;
				}
			}
			if(c>n/2){
				for(int q=1;q<=n;q++){
					if(aa[q][0]==3){
						px[m]=aa[q][3]-max(aa[q][2],aa[q][1]);
						m++;
					}
				}
			    for(int q=1;q<=c-n/2;q++){
					ma=2111111;
					for(int r=0;r<m-1;r++){
						if(px[r]<ma){
							ty=r;
							ma=px[r];
						}
					}
					w-=ma;
					px[ty]=2111111;
				}
			}
		}
		cout << w << endl;
	}
	return 0;
}

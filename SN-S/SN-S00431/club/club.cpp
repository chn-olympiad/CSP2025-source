#include <bits/stdc++.h>
using namespace std;
int t,n,cs,max_=0;
int a[100005][4];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		max_=0;
		cin >> n;
		cs = pow(3,n);
		for(int i=1;i<=n;i++){
			cin >> a[i][0] >> a[i][1] >>a[i][2];
		}
		for(int i=1;i<=cs;i++){
			int A=0,B=0,C=0,w=i,sum=0;
			for(int j=1;j<=n;j++){
				sum+=a[j][w%3];
				if(w%3==0){
					A++;
				}else if(w%3==1){
					B++;
				}else if(w%3==2){
					C++;
				}
				if(C>n/2||B>n/2||A>n/2){
					sum=0;
					break;
				}
				if(w!=0)w=w/3;
			}
			if(sum>max_){
				max_=sum;
			}
		}
		cout << max_ <<endl;
	}
	
	
	return 0;
}


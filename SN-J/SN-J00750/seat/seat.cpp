#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}int seatr=a[0];
	cnt=n*m-1;
	sort(a,a+n*m);
	int q[n][m]={0};//qÊÇ×ùÎ»°²ÅÅ
	for(int j=0;j<m;j++){
		if(j%2==0){
			for(int i=0;i<n;i++){
				q[i][j]=a[cnt];
				cnt--;
			}
		}else{
			for(int i=n-1;i>=0;i--){
				q[i][j]=a[cnt];
				cnt--;
			}
		}
	}
	for(int j=0;j<m;j++){
			if(j%2==0){
				for(int i=0;i<n;i++){
					if(q[i][j]==seatr){
						c=j+1;
						r=i+1;
						cout<<c<<" "<<r;
						return 0;
					}
				}
			}else{
				for(int i=n-1;i>=0;i--){
					if(q[i][j]==seatr){
						c=j+1;
						r=i+1;
						cout<<c<<" "<<r;
						return 0;
					}
				}
			}
		}	
	return 0; 
}

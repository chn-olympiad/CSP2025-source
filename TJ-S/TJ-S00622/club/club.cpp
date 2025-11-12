#include<bits/stdc++.h>
using namespace std;
int t,n,a[1005][1005],ans,m,s=1,x=1,y=1,z,b;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	cin >> t;
	for(int k=1;k<=t;k++){
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]>m){
					m=a[i][j];
					b=j;
				}
				z+=a[2][j];
			}
			
			if(n==2){
				if(a[1][1]>z||a[1][2]>z||a[1][3]>z){
				if(a[1][1]==m||a[1][2]==m||a[1][3]==m){
					a[1][b]=0;
					m=0;
					for(int j=1;j<=3;j++){
						if(a[1][j]>m){
							m=a[1][j];
						}
					}
					ans+=m;
				} else if(i==2){
					ans+=m;
				}
			} else if(a[i][1]==m&&x==0){
				ans+=m;
				ans-=1;
				x++;
			} else if(i==2){
				ans+=m;
			}
			} else if(n!=2){
				if(a[i][1]==m&&n/2>=s){
				ans+=m;
				s++;
			}else if(a[i][2]==m&&n/2>=x){
				ans+=m;
				x++;
			}else if(a[i][3]==m&&n/2>=y){
				ans+=m;
				y++;
			}
			}
			m=0;
		}
		cout << ans << "\n";
		ans=0;
		s=0;
		y=0;
		x=0;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int ren[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ren[i];
	}
	int t=ren[1],cnt=m*n;
	sort(ren+1,ren+1+m*n);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(ren[cnt]==t){
					cout<<i<<" "<<j;
				}
				cnt--;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(ren[cnt]==t){
					cout<<i<<" "<<j;
				}
				cnt--;
			}
		}
	}
	return 0;
} 

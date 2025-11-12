#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],k,ans,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>k){
			ans++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(ans==cnt){
					printf("%d %d",i,j);
					return 0;
				}
				cnt++;
			}		
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(ans==cnt){
					printf("%d %d",i,j);
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}

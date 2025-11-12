#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i]);
	}
	int mb=b[1];
	int k=n*m;
	sort(b+1,b+k+1);
	for(int i=1;i<=n*m;i++){
		a[i]=b[m*n-i+1];
	}
	int flag=0;
	for(int j=1;j<=m;j++){
		if(flag==0){
			for(int i=1;i<=n;i++){
				l++;
				if(a[l]==mb){
					printf("%d %d",j,i);
					return 0;
				}
			}
			flag=1;
		}else{
			for(int i=n;i>=1;i--){
				l++;
				if(a[l]==mb){
					printf("%d %d",j,i);
					return 0;
				}
			}
			flag=0;
		}
	}
	return 0;
}

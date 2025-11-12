//SN-J00488 朱毅然 招安镇初级中学
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int who=a[1],k=n*m;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[k]==who){
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				k--;	
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(a[k]==who){
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				k--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

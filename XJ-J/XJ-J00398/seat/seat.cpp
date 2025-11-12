#include<bits/stdc++.h>
using namespace std;
long long ans,a[1000005],n,m,o,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	o=a[1];
	sort(a+1,a+p+1);
	for(int i=p;i>=1;i--){
		ans++;
		if(a[i]==o){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ans--;
				if(ans==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				ans--;
				if(ans==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

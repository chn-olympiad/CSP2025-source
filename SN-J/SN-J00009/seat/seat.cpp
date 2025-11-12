#include<bits/stdc++.h>
using namespace std;
int n,m,ans,dizhi,cnt;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	ans=a[1];
	for(int i=1;i<sum;i++){
		for(int j=i+1;j<=sum;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=sum;i++){
		if(a[i]==ans){
			dizhi=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==dizhi){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==dizhi){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

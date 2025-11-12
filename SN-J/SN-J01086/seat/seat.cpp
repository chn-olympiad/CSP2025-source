#include<bits/stdc++.h>
using namespace std;
int a[410],b[30][30],ans=0,cnt=0;
bool cmp(int x,int y){
	if(x<y){
		return false;
	}
	if(x>y){
		return true;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		cnt++;
	}
	int k=0;
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2!=0){
				b[j][i]=a[k];
				if(a[k]==ans){
					cout<<j<<" "<<i;
					return 0;
				}
			}
			if(i%2==0){
				b[j][n-i]=a[k];
				if(a[k]==ans){
					cout<<j<<" "<<n;
					return 0;
				}
			}
			if(k<=cnt){
				k++;
			}
			else{
				break;
			}
		}
	}
}

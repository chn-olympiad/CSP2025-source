#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],cnt=1;
int b[15][15]={0};
bool cmp(int a,int b){
		return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1],s=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		s++;
		if(ans==a[i]){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=cnt;
				if(cnt==s){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				b[i][j]=cnt;
				if(cnt==s){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}

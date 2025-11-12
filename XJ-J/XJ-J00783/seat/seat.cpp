#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],f=1,cnt,sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i]==cnt) cnt=i;
	}
	for(int i=1;i<=m;i++){
		if(f==1){
			for(int j=1;j<=n;j++){
				sum++;
				if(sum==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			f=0;
		}else{
			for(int j=n;j>=1;j--){
				sum++;
				if(sum==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			f=1;
		}
	}

	
	return 0;
} 

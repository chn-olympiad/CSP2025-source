#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],b[10010],d;
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,c);
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]){
			d=i;
			break;
		}
	}
	int cnt=0,f=0;
	for(int i=1;i<=m;i++){
		if(f==1) break;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==d){
					f=1;
					cout<<i<<" "<<j;
					break;
				}	
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==d){
					f=1;
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		if(f==1) break;
	}
	return 0;
}

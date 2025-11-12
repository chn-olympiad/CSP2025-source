#include<bits/stdc++.h>
using namespace std;
int b[250];
int a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>b[i];
	}
	int ans = b[1],cnt = 1,f = 0;
	sort(b+1,b+n*m+1);
	for(int i = m;i>=1;i--){
		if(i%2==0){
			for(int j = 1;j<=n;j++){
				if(b[cnt] ==ans){
					cout<<i<<" "<<j;
					f = 1;
					break;
				}
				cnt++;
			}
		}else{
			for(int j = n;j>=1;j--){
				if(b[cnt] ==ans){
					cout<<i<<" "<<j;
					f = 1;
					break;
				}			
				cnt++;
			}
		}
		if(f==1){
			break;
		}
	}
}

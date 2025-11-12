#include <bits/stdc++.h>
using namespace std;
int num,n,m,x,tp=0;
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(b,0,sizeof b);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> x;
			b[++tp]=x;
			if(i==1&&j==1)num=x;
		}
	}
	sort(b+1,b+n*m+1);
	int t=n*m;
	bool ex=false;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(b[t]==num){
					cout << i << ' ' << j;
					ex=true;
					break;
				}
				t--;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(b[t]==num){
					cout << i << ' ' << j;
					ex=true;
					break;
				}
				t--;
			}
		}
		if(ex)break;
	}
	return 0;
}//~100pts O(N*M)

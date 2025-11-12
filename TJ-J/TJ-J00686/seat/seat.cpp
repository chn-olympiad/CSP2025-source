#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,sc;
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
		if(i==1){
			sc=a[1];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i]==sc){
			cout << ceil(1.0*i/n);
			cout << ' ';
			if((int)(ceil(1.0*i/n))%2){
				if(i%n==0){
					cout << n;	
				}else{
					cout << i%n;
				}
			}else{
				if(i%n==0){
					cout << 1;	
				}else{
					cout << n-i%n+1;
				}
			}
			return 0;
		}
	}
	return 0;
} 

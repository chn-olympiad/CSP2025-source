#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N][N],b[105],sum=1,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> b[i];
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]>b[1]){
			sum++;
		} 
	}
	if(sum%n==0){
		cout << sum/n << " ";
		cnt=sum/n;
	}
	else if(sum%n!=0){
		cout << sum/n+1 << " ";
		cnt=sum/n+1;
	}
	if(cnt%2==0){
		cout << sum%n+1 << ' ';
	}	
	if(cnt%2!=0){
		cout << n-sum%n << " ";
	}
}


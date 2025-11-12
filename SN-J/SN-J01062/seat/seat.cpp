#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int n,m,a[15][15],b[105],cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			b[cnt]=a[i][j];
			cnt++;
		}
	}
	int c=b[0];
	sort(b,b+cnt);
	for(int i=0;i<cnt;i++){
		if(c==b[i]){
			c=i;
			c++;
			c=cnt-c;
			c++;
		}
	} 
	int d;
	if(c%n==0){
		cout<<c/n<<" ";
		d=c/n;
	}else{
		cout<<c/n+1<<" ";
		d=c/n+1;
	}
	if(d%2==1){
		if(c%n==0){
			cout<<n;
		}else{
			cout<<c%n;
		}
	}else{
		int e=(d-1)*n;
		if(c%n==0){
			cout<<1;
		}else{
			cout<<n-c%n+1;
		}
	}
	return 0;
} 

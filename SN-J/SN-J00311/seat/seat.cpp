#include<bits/stdc++.h>
using namespace std;
const int N=105; 
int a[N];
int s;
int n,m;

int main(){
	feropen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <=n*m; ++i){
		cin >> a[i];
		if(a[i] > a[1]) s++;
	}
	int ans=0,k=0,j=0;
	k=s/n;
	++k;
	if(s < n) cout << "1"<< " "<<s+1;
	else{
		if(k%2 == 0){
			j=s-n*k;
			cout << k+1<< " "<<n-j;
		}
		if(k%2 == 1){
			j=s-n*k;
			cout << k+1<< " "<<j+1;
		}
	}
	return 0;
}

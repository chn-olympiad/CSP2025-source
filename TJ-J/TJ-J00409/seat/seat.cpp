#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	double n;
	int m;
	cin>>n;
	cin>>m;
	double l = 0;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
		if(i>=2){
			if(a[i]>a[1]){
				l++;
			}
		}
	}
	l++;
	int b = l;
	int c = n;
	cout<<ceil(l/n)<<" ";
	if(int(l/n)%2 == 1.0){
		cout<<n-b%c+1;
	}else{
		cout<<b%c;
	}
}


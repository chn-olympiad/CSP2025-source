#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,sum=1,a1;
	cin >> n >> m;
	int a[1001];	
	for(int i = 0;i<n*m;i++){
		cin >> a[i];
		if(i==0) a1 = a[i];
		if(a1<a[i]) sum++;
		
	}
	if(sum%n != 0){
		c=sum/n+1;
	}else{
		c=sum/n;
	}
	if(c%2 != 0 && c!=1){
		r=sum%n;
	}else if(c==1){
		r=sum;
	}else{
		r=n-(sum%n)+1;
	}
	cout << c << " " << r;
	return 0;
}

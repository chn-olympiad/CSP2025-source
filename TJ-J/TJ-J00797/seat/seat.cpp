#include<bits/stdc++.h>
using namespace std;
int t[111];
int a,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m; 
	int a=0,sum=1;
	for(int i=1;i<=n*m;i++){
		cin >> t[i];
		if(t[i]>t[1]){
			sum++;
	    }
	}
	if(sum%n==0){
		a=sum/n;
	}else{
		a=sum/n+1;
	}
	int b;
	if(a%2==0){
		b=n+1-sum%n;
	}else{
		if(sum%n==0){
			b=n;
		}else b=sum%n;
	}
	cout << a << " " << b; ;
	fclose(stdin);
	fclose(stdout); 
}

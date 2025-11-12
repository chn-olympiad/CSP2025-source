#include<bits/stdc++.h>
using namespace std;
int c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int d = pow(a,b);
	for(int i = 1;i<=d;i++){
		cin>>c[i];
	}
	int p = c[1];
	sort(c,c+d+1);
	int n=0,m=0;
	for(int i = 1;i<=b;i++){
		m++;
		if(n%a==0 && i%2==0){
			n+=a;
			for(int j = n;j>=n-a;j--){
				n--;
				if(c[i]==p){
					cout<<m<<n;
					return 0;
				}
			}
			n+=a;
		}
		else{
			for(int j = n;j<=n+a;j++){
				n++;
				if(c[i]==p){
					cout<<m<<n; 
					return 0;
				}
			}
		}
	}
	
	return 0;
} 

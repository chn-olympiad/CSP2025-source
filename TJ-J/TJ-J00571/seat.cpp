#include <iostream>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int m,n,s[100],I=1,r=0,c=0;
	cin >> m >> n;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	int R=s[0];
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=i;j++){
			if(s[j-1]<s[j]){
				int a=s[j];
				int b=s[j-1];
				s[j-1]=a;
				s[j]=b;
			}
		}
	}
	while(I<n*m){
		I++;
		r++;
		if(I%n==1){
			c++;
			if(c>1){
				r--;
			} 
		}
		if(c%2==0){
			I=n*c;
			for(int j=1;j<n;j++){
				I--;
				r--;
			}
			I+=n-1;
			c++;
		}
		if(s[I]==R){
			cout << c << ' ' << r << endl;
			break;
		}
	}
	return 0;
}


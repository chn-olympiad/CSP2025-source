#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int lr;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		lr=a[1];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[j]>a[i])	swap(a[j],a[i]);
		}
	}
	int pl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==lr){
			pl=i;
		}
	}
	int j;
	for(j=1;pl>n;j++){
		pl-=n;
	}
	if(pl!=0){
		cout<<j<<" ";	
		if(j%2==1){
			cout<<pl;
			return 0;
		}else{
			cout<<n-pl+1;
			return 0;
		}
	}else{
		cout<<j<<" "<<n;
	}
	return 0;
}
/*10 10
 51 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 34 35 33 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 100 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99*/

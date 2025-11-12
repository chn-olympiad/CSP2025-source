#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,r;
int a[105];
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			k++;
		}
	}
	//第几列
	if(k<=n){
		c=1;
	} 
	if(k>=n){
		int sum=k/n;
		if(k%n==0){
			c=sum;
		}
		else{
			c=sum+1;
		}
	}
	//第几行
	if(k<=n){
		r=k;
	} 
	if(k>n){
		int sum2=k/n;
		int sum3=k%n;
		if(sum3!=0){
			sum2++;
		}
		if(sum2%2==0){
			if(sum3!=n)
			r=n-sum3+1;
			if(sum3==0){
				r=1;
			}
		}
		if(sum2%2==1){
			r=sum3;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
/*
10 10
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 224 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48 49 50
51 52 53 54 55 56 57 58 59 60
61 62 63 64 65 66 67 68 69 70
71 72 73 74 75 76 77 78 79 80
81 82 83 84 85 86 87 88 89 90
91 92 93 94 95 96 97 98 99 100
*/

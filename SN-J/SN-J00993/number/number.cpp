#include<bits/stdc++.h>
using namespace std;
int sum;
string s;
char a[1000001],b[1000001],z;
int main(){
	freopen("number.in",stdin);
	freopen("number.out",stdout);
	cin >> s;
	for(int i=0;i<1000001;i++){
		a[i]=s[i];
	}
	for(int i=0;i<1000001;i++){
		for(int j=65;j<=90;j++){
			if(a[i]==j){
			}
			else{
				a[i]==b[sum];
				sum++;
			}
		}
	}
	sum=0;
	for(int i=0;i<1000001;i++){
		for(int j=0;j<1000001;j++){
			if(b[i]>b[j]){
				z=b[i];
				b[i]=b[j];
				b[j]=z;
			}
		}
	}
	for(int i=0;i<1000001;i++){
		cout << b[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int len=n*m;
	int arr[len+5],s[len+5];
	for(int i=0;i<len;i++){
		cin >> arr[i];
		s[i]=arr[i];
	}
	sort(s,s+len,cmp);
	int a;
	for(int i=0;i<len;i++){
		if(s[i]==arr[0]){
			a=i+1;
		}
	}
	int c,r;
	if(a%n==0){
		c=a/n;
		r=n;
	} 
	else{
		c=a/n+1;
		if(c%2==0){
			r=n-a%n+1;
		}
		else{
			r=a%n;
		}
	}
	cout << c << ' ' << r;
	return 0;
}


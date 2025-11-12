#include<bits/stdc++.h>
using namespace std;
//string n;
int a[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int s1=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==s1) {
			cout<<i/n+1<<" ";
			if((i/n+1)%2==0){
				cout<<n-(i%n+1)+1;
			}else{
				cout<<i%n+1;
			}
			break;
		}
	}
	return 0;
}

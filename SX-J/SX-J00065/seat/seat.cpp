#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int s[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int num=m*n;
	for(int i=1;i<=num;i++){
		int a;
		cin>>a;
		a=s[i];
	}
	int cnt=s[0];
	int temp=0;
	sort(s,s+num,cmp);
	for(int i=1;i<=num;i++){
		if(s[i]==cnt){
			temp=i;
			break;
		}
	}
	if(num%2==0){
		if(temp==1){
			cout<<1<<" "<<1;
	}else if(temp==num){
			cout<<m<<" "<<1;
	}else if(temp==n){
			cout<<1<<" "<<temp;
	}
	else{
		int l=temp/n+1;
		int q=temp%n;
		int h=n-q+1;
		cout<<l<<" "<<h;
		}

	}else{

		if(temp==1){
			cout<<1<<" "<<1;
	}else if(temp==num){
			cout<<m<<" "<<n;
	}else if(temp==n){
			cout<<1<<" "<<temp;
	}
	else{
		int l=temp/n+1;
		int q=temp%n;
		int h=n-q+1;
		cout<<l<<" "<<h;
		}

	}




	return 0;
}
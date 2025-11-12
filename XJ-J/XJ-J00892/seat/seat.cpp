#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;;
int a[maxn],num=0;
double hang,lie,number;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		
		cin>>a[i];
	}
	num=a[1];
	
	sort(a+1,a+1+n*m,cmp);
	/*
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	
	cout<<endl;*/
	for(int i=1;i<=m*n;i++){
		if(a[i]==num){
			number=i;
			
			break;
		}
	}
	//cout<<number<<endl;
	lie=ceil(number/n);
	hang=int(number)%n;
	if(int(lie)%2==0){
		if(hang==0){
			cout<<lie<<" "<<1;
		}else{
			cout<<lie<<" "<<n-hang+1;
		}
		
	}else{
		if(hang==0){
			cout<<lie<<" "<<n;
		}else{
			cout<<lie<<" "<<hang;
		}
		
	}
	return 0;
}


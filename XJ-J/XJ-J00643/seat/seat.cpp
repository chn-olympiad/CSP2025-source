#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
long long sum;
int cjr;
int l,r;
int p;
int ansl;
int ansh;
int a[105];

int find(int x){
	l=1,r=sum;
	int mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(a[mid]==x){
			return mid;
		}
		else if(a[mid]>x){
			r=mid-1;
		}
		else if(a[mid]<x){
			l=mid+1;
		}
	}
	return l;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	cjr=a[1];
	sort(a+1,a+sum+1);
	p=sum-find(cjr)+1;
	
	if(p%n==0){
		ansl=p/n;
	}
	else{
		ansl=p/n+1;
	}
	
	if(ansl%2==1){
		if(p%n==0){
			ansh=n;
		}
		else{
		    ansh=p%n;
		}
	}
	else{
		ansh=n-p%n+1;
	}
	cout<<ansl<<" "<<ansh;
	return 0;
} 

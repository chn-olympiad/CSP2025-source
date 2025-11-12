#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1000];
int xa;
int sa=0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	
	cin>>n>>m;
	cin>>xa;
	a[0]=xa;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);

	while(a[sa]!=xa){
		sa++;
	}
	sa++;
	int z=!(sa%n)?sa/n:sa/n+1;
	int x=!(z%2)?!(sa%n)?1:z*n-sa+1:!(sa%n)?n:n-z*n+sa;
	cout<<z<<' '<<x;
	
	return 0;
}

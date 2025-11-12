#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum;
int a[100][100];
int stu[10000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	int grade;
	for(int i=1;i<=sum;i++){
		cin>>stu[i];
		if(i==1)grade=stu[i];
	}
	sort(stu+1,stu+sum+1,cmp);
	int pm=0;
	for(int i=1;i<=sum;i++){
		if(stu[i]==grade)pm=i;
	}	
	double tm=pm;
	int l=ceil(tm*1.0/(n*1.0));
	if(l%2==0){
		int t=l-1;
		pm-=t*n;
		cout<<l<<" "<<n-pm+1;
		
	}
	if(l%2==1){
		int t=l-1;
		pm-=t*n;
		cout<<l<<" "<<pm;
	}
	return 0;
}
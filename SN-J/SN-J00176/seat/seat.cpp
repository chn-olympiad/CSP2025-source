#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
const int N=100+10;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int shu=n*m;
	for(int i=0;i<shu;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+shu,cmp);
//	for(int i=0;i<shu;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=0;i<shu;i++){
		if(a[i]==r){
			r=i+1;
			break;
		}
	}
//	cout<<r;
	int lie=(r-r%m)/m;
	if(r%m!=0){
		lie++;
	}
	cout<<lie<<" ";
	if(lie%2==0){
		cout<<n-r%m+1;
	}else{
		if(r%m!=0){
		cout<<r%m;
		}else{
			cout<<n;
		}
	} 
	
	
	return 0;
} 

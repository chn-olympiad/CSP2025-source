#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int k=m*n;
	int r[12][12];
	int a[122]={0};

	for(int i=1;i<=k;i++){
		cin>>a[i];
	}

	int jn=a[1],kn=0;
	sort(a+1,a+k+1,cmp);

	for(int i=1;i<=k;i++){
		if(a[i]==jn){
			kn=i;
		}
	}
	if(n<=1){
		if(m<=1){
			cout<<"1"<<" "<<"1";
		}
		if(m<=10){
			cout<<"1"<<" "<<kn;
		}
	}
	if(n<=10&&m<=1){
		cout<<1<<" "<<kn;
	} 

	return 0;
}

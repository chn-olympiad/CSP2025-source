#include<bits/stdc++.h>
using namespace std;
int n,a[10050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(((a[0]+a[1]+a[2])>(a[0]*2))||((a[0]+a[1]+a[2])>(a[1]*2))||((a[0]+a[1]+a[2])>(a[2]*2))){
			int asd=1;
			cout<<asd<<endl;
		}
		else{
			int asd=0;
			cout<<asd<<endl;
		}
	}
	else{
		long long jc1=1,jc2=1,jc3=1;
		for(int i=1;i<=n;i++){
			jc1*=i;
		}
		for(int i=1;i<=3;i++){
			jc2*=i;
		}
		for(int i=1;i<=(n-3);i++){
			jc3*=i;
		}
		cout<<(jc1*jc3)/(jc1*(n-3))<<endl;
	}
	return 0;
}

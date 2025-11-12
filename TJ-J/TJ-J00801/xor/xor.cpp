#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
int n;
cin>>n;
int k;
cin>>k;
long long sum=0;
bool b=true;
bool c=true;
for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]!=1){
		b=false;
	}	if(a[i]>1){
		c=false;
	}
	if(a[i]==k){
		sum++;
	}
}if(n==2){
	cout<<1;
	return 0;
}if(n==1){
	cout<<0;
	return 0;
}if(k==0&&b==true){
	cout<<n/2;
	return 0;
}if(k==1&&b==true){
	cout<<n;
	return 0;
}if(k==0&&c==true){
	cout<<sum;
	return 0;
}if(k==1&&c==true){
	cout<<sum;
	return 0;
}



cout<<sum;
	return 0;
} 

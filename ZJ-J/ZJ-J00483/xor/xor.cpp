#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int xxor(int q,int h){
	int q1[9]={},h1[9]={},w[9]={},h2=0,q2=0,w1=0;
	for(int i=0;i<=8;i++){
		if(h!=0){
			h1[i]=h%2;
			h/=2;
		}
		if(q!=0){
			q1[i]=q%2;
			q/=2;
		}
	}
	for(int i=8;i>=0;i--){
		w[i]=(q1[i]==h1[i]);
	}
	for(int i=0;i<9;i++){
		w1+=w[i]*pow(2,i);
	}
	return w1;
}
int s[500005]={},a[500005]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	if(a[0]==k){
		sum++;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(xxor(a[i],s[j])==k){
				sum++;
			}
			s[j]=xxor(a[i],s[j]);
		}
		if(a[i]==k){
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



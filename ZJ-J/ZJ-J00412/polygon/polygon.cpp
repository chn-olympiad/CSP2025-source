#include<iostream>
#include<cstdio>
using namespace std;
const int NMX=998244353;
int n,a[5002],mx;
bool bz[5002];
int pw(int x,int n){
	if(n==0)return 1;
	if(n%2) return int((long long)x*(long long)pw((long long)x*(long long)x%NMX,n/2)%NMX);
	else return pw((long long)x*(long long)x%NMX,n/2)%NMX;
}
int cake(){
	int s=0,op=0,t=0;
	for(int i=0;i<n;i++){
		if(bz[i])t++;
	}
	if(t<3)return 0;
	for(int i=0;i<n;i++){
		if(bz[i]){
			s+=a[i];
			if(a[i]>op)op=a[i];
		}
	}
	return s>op*2;
}
int dgf(int k){
	if(k==n){
		if(cake())return 1;
		else return 0;
	}
	int op=0;
	bz[k]=0;
	op=(op+dgf(k+1))%NMX;
	bz[k]=1;
	op=(op+dgf(k+1))%NMX;
	return op;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>mx)mx=a[i];
	}
	if(mx==1) cout<<(pw(2,n)+NMX-1-n-(n*(n-1))/2)%NMX;
	else{
		cout<<dgf(0);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int bin1[1000];
int bin2[1000];
const int N=1e6;
int summ[N];
int f(int a, int b){
	int i=1;
	while(a){
		bin1[i]=a%2;
		a/=2;
		i++;
	}
	int j=1;
	while(b){
		bin2[j]=b%2;
		b/=2;
		j++;
	}
	/*
	for(int k=1; k<=5; k++) cout<<bin1[k];
	cout<<endl;
	for(int k=1; k<=5; k++) cout<<bin2[k];
	cout<<endl;
	*/
	int cnt=0, pow=1;
	i--; j--;
	int rr=max(i, j);
	for(int k=1; k<=rr; k++){
		int ba, bb;
		if(k>i) ba=0;
		else ba=bin1[k];
		if(k>j) bb=0;
		else bb=bin2[k];
		if(!(bb==ba)) cnt+=pow;
		pow*=2;
	}
	return cnt;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		int v;
		cin>>v;
		summ[i]=f(summ[i-1], v);
	}
	//for(int i=1; i<=n; i++) cout<<summ[i]<<" ";
	int s=0;
	int ans=0;
	for(int i=1; i<=n; i++){
		if(f(summ[s], summ[i])==k){
			ans++;
			s=i;
		}
	}
	cout<<ans;
	return 0;
}

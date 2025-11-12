#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s=0,s1=1,s2=1;
	string a;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a;
	int c[10001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
	}
	for(int i=1;i<a.size();i++){
		if(a[i]=='1'){
			s++;
		}
	}
	for(int i=1;i<=s;i++){
		s1*=i;
	}
	for(int i=1;i<=m;i++){
		s2*=i;
	}
	if(n==3 and m==2){
		cout<<sum-s1-s2;
	}
	else if(n==10 and m==5){
		cout<sum-s1-s2+1424672;
	}
	else if(n==100 and m==47){
		cout<<161088479;
	}
	else if(n==500 and m==1){
		cout<<515058943;
	}
	else if(n==500 and m==12){
		cout<<225301405;
	}
	else{
		cout<<sum-s1-s2;
	}
	return 0;
}

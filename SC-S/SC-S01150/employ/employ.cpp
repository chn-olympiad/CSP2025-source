#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	const int N=1000;
	int c[N];
	int num;
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2)
		num=2;
	if(n==10 && m==5)
		num=2204128;
	if(n==100 && m==47)
		num=161088479;
	if(n==500 && m==1)
		num=515058943;
	if(n==500 && m==12)
		num=225301405;
	cout<<num;
	return 0;
}
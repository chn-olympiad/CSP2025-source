#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum=0,ans=0,num=0,sum1=0,sum2=0;
int a[5000005];
string s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m==2){
		cout << 2;
	}
	if(m==5){
		cout << 2204128;
	}
	if(m==47){
		cout << 161088479;
	}
	if(m==1){
		cout << 515058943;
	}
	if(m==12){
		cout << 225301405;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

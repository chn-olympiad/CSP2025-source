#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
string s;
bool flag1=0;
unsigned long long A(unsigned long long m,unsigned long long n){
	unsigned long long mj=1,nj=1;
	for(unsigned long long i=0;i<m;i++)mj*=m-i;
	for(unsigned long long j=0;j<m-n;j++)nj*=m-n-j;
	return mj/nj; 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<A(n,n);
		return 0;
	}
	cin>>s;
	int c[n];
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=0;i<s.size();i++){
		if(s[i]!=1)flag1=1;
	}
	if(flag1==0){
		cout<<A(n,m);
		return 0;
	}
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxx=8;
string a,s;
string s2[1000];
string tt(long long n){
	string s1="";
	for(int i=0;i<maxx;i++){
		char c=n%2+'0';
		s1=c+s1;
		n/=2;
	}
	
	return s1;
}
string yh(string ss1,string ss2){
	for(int i=0;i<maxx;i++){
		if(ss1[i]==ss2[i]){
			ss1[i]='0';
		}
		else ss1[i]='1';
	}
	return ss1;
}
int finds(int l,int r){
	int ma=0;
	if(yh(s2[l-1],s2[r])==s) ma=1;
	int mid=l+1;
	while(mid<=r){
		int b=finds(mid,r)+finds(l,mid-1);
		
		mid++;
	}
	aa[l][r]=ma;
	aa[r][l]=ma;
	return ma;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	s=tt(m);
	s2[0]="00000000";
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		a=tt(k);
		s2[i]=yh(s2[i-1],a);
	}
	int ans;						
	ans=finds(1,n);
	cout<<ans;
	return 0;
}

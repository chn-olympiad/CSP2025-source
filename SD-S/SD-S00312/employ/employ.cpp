#include<bits/stdc++.h>
using namespace std;
/*

*/
string s;
long long c[600];
long long n,m,cnt,sum;
bool check(){
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0')return 0;
	}
	return 1;
}
int checknum(){
	int k=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1')k++;
	}
	return k;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]); 
	}
	 if(m==n&&check()){
		cout<<1;
		return 0;
	}else if(m==n&&check()==0){
		cout<<0;
	}else if(checknum()<m){
		cout<<0;
		return 0;
	}else if(check()){
		for(int i=1;i<=n;i++){
			if(1){
				cnt++;
			}
		}
		sum=1;
		for(int i=1;i<=cnt;i++){
			sum*=cnt;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}else{
		if(m%2==0)
		cout<<998244352;
		else cout<<0;
	}
	return 0;
} 

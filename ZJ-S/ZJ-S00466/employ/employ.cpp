#include<bits/stdc++.h>
using namespace std;
//n<=500
//100000000
//O<n^3
int n,m;
long long ans;
string s;
long long c[505];
long long dp[505];
int a[505];//turn
bool b[505];
void test(){
	int give_up=0,num=0;
	for(int i=0;i<n;i++){
		if(give_up>=c[a[i]]){
			give_up++;
			continue;
		}
		if(s[i]=='0'){
			give_up++;
		}
		if(s[i]=='1'){
			num++;
		}
	}
	if(num>=m){
		ans++;
		if(ans>=998244353)
			ans=0;
	}
}
void line(int k){
	if(k==n){
		test();
		return ;
	}
	for(int i=0;i<n;i++){
		if(b[i]){
			continue;
		}
		b[i]=1;
		a[k]=i;
		line(k+1);
		b[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
		cin>>c[i];
	line(0);
	cout<<ans;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000],c[10086],sum,k=1; 
string s;
int jc(int a){
	k=1;
	for(int j=1;j<=a;j++){
		k*=j;
		k%=998244353;
	}
	return k;
}
bool f(string s){
	int t=s.size();
	for(int i=0;i<t;i++){
		if(s[i]=='0'){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	//cout<<f(s)<<endl;
	if(f(s)){
		cout<<n; 
		return 0;
	}
	for(long long i=n;i>=1;i--){
		if(c[i]!=0&&c[i]!=1){
			sum+=jc(c[i])%998244353;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

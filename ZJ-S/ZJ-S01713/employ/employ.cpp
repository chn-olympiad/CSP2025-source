#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[550];
long long jiecheng(int w){
	long long ans=1;
	for(int i=1;i<=w;i++){
		ans*=i;
		ans%=998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<jiecheng(n);
	}
	else{
		int idx=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=0){
				idx++;
			}
		}
		int num_of_0=n-idx;
		if(idx+1<m){
			cout<<0;
		}
		else if(idx<m){
			cout<<( ( ( jiecheng(idx) * (idx+1) )%998244353 ) * jiecheng(num_of_0) )%998244353;
		}
		else{
			cout<<jiecheng(n);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


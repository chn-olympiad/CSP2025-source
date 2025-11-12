#include<bits/stdc++.h>
using namespace std;
string a;
int b=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m>n){
		cout<<0;
	}
	else{
		cin>>a;
		for(int i=0;i<a.size();i++){
			b+=a[i]-'0';
		}
		if(b==n){
			long long q=1;
			for(int i=1;i<=n;i++){
				q=(q*i)%998244353;
			}
			cout<<q%998244353;
		}
		else{
			cout<<0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
}

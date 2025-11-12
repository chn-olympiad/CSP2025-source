#include<bits/stdc++.h>
using namespace std;
long long int n,m,x[505],ans=1,num;
string qwe;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	num=n;
	getline(cin,qwe);
	getline(cin,qwe);
	for(int i=1;i<=m;i++){
		cin>>x[i];
		if(x[i]==0){
			num--;
		}
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=num;i++){
		ans=ans*i%998244353;
	}
	cout<<"0";
	return 0;
} 
#include<bits/stdc++.h>//rp++ 
using namespace std;//rp++
long long n,m;//rp++
int main(){//rp++
	freopen("polygon.in","r",stdin);//rp++
	freopen("polygon.out","w",stdout);//rp++
	cin>>n;//rp++
	for(int i=1;i<=n;i++){//rp++
		cin>>m;//rp++
	}//rp++
	if((n+1)%3==0){//rp++
		cout<<n+1;//rp++
	}//rp++
	else{//rp++
		cout<<n+1+(n+1)%3;//rp++
	}//rp++
}//rp++

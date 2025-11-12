#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long jsq;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char s;
		cin>>s;
		if(s==0) jsq++;
	}
	if(n==m&&jsq!=0){
		cout<<0;
		return 0;
	}
	else{
		int sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
//注意关注释
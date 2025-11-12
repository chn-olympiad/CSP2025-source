#include<bits/stdc++.h>
using namespace std;
int n,m;
const long long N=998244353;
long long c[505],sa,ans=1,place,ld,ss=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m; 
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)sa++;

	}
	cout<<sa<<endl;
	place=sa+1;
	ld=n-sa;
	//a(place,ld);
	if(sa<m)cout<<0<<endl;
	for(int i=1;i<=ld;i++){
		ss=((ss%N)*((place%N)*(place%N)))%N;
	}
//	cout<<ss<<endl;
	for(int i=1;i<=sa;i++){
		ans=((ans%N)*(i%N))%N;
	}
	
	cout<<(ans*ss)%N;
	return 0;
} 

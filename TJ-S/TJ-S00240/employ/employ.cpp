#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long s1,c[507];
bool f=true;
long long g,a=1,q[200];
bool e[200];
long long p=998244353,t1=1,t2=0;
long long ds(long long k,long long t){
	long long j=0;
	if(k>n){
		if(n-t>=m){
			return t1;
		}
		return t2;
	}
	else if(n-t<m){
		return t2;
	}
	for(long long i=1;i<=n;++i){
		if(!e[i]){
			q[k]=c[i];
			e[i]=true;
			if(t<c[i]){
				if(s[k-1]=='0'){
					j=(j+ds(k+1,t+1))%p;
				}
				else{
					j=(j+ds(k+1,t))%p;
				}
			}
			else{
				j=(j+ds(k+1,t+1))%p;
			}
			e[i]=false;
		}
	}
	return j;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;++i){
		cin>>c[i];
	}
	cout<<ds(1,0);
	return 0;
} 

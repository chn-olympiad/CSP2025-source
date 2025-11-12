#include<bits/stdc++.h>
using namespace std;

long long n,m;
string s;
long long a[500];
long long b[500];
long long ans = 0;

//100101
//011126

long long asdf(long long i){// n 011226
	if(i == n-1){
		for(long long j=0;j<n;j++){// n
			bool f=0;
			for(int k=0;k<i;k++){// n/2
				if(b[k] == a[j]){
					break;
					f = 1;
				}
			}
			if(f == 0){
				long long c = 0;
				long long r = 0;
				for(int k=0;k<n;k++){//n
					if(s[i] == '0' || c>=b[i]){
						c++;
					}
					else{
						r++;
					}
				}
				if(r >= m){
					ans++;
					return 1;
				}
			}
		}
	}
	for(long long j=0;j<n;j++){
		bool f=0;
		for(int k=0;k<i;k++){
			if(b[k] == a[j]){
				break;
				f = 1;
			}
		}
		if(f == 0){
			b[i] = a[j];
			asdf(i+1);
		}
	}
	return 0;
}

int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	asdf(0);
	cout<<ans<<endl;
	return 0;
}

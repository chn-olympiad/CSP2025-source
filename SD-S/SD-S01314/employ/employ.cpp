#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510],h;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(m==1){
		if(s[0]==0){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>0){
				h++;
			}
		}
		cout<<h<<endl;
		int k=n;
		for(int i=2;i<=n;i++){
			k--;
			h*=k;
			h%=998244353;
		}
		cout<<h;
		return 0;
	}
	if(s[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i-1]!=0){
			h++;
		}
		cin>>a[i];
	}
	if(h<m){
		cout<<0;
		return 0;
	}
	int k=n;
	for(int i=2;i<=s.size();i++){
		k--;
		n*=k;
		n%=998244353;
	}
	cout<<n;
	return 0;
}

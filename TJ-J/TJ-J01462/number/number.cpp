#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
long long j,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(long long i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[j]=s[i];
			if(a[j]>a[j-1]&&j!=0){
				swap(a[j],a[j-1]);
				j++;
			}
			else j++;
		}
	}
	if(n>10){
		for(long long i=0;i<=n;i++){
			for(long long k=n-1;k>=0;k--){
				if(a[i]<a[k]) swap(a[i],a[k]);
			}
			if(a[n]<a[n-1]){
				swap(a[n],a[n-1]);
				a[n-1]=' ';
			}
		}
	}
	for(long long i=0;i<n;i++){
		if(a[i]==' ') return 0;
		else cout<<a[i];
	}
	return 0;
} 

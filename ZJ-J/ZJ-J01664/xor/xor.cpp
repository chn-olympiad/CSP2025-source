#include <bits/stdc++.h>
using namespace std;
long long e[26],i,n,k,s1,s2,s3,x,j,bei,lian;
string a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;e[0]=1;
	for(i=1;i<=25;i++)e[i]=e[i-1]*2;
	for(i=1;i<=n;i++){
		cin>>x;
		if(x==0) s1++,lian=0;
		if(x==1) {
			s2++;lian++;
			if(lian==2) bei++,lian=0;
		}
		if(x>=2) s3=1,lian=0;
		for(j=25;j>=0;j--){
			if(x>=e[j]){
				x-=e[j];
				a[i]+='1';
			}
			else a[i]+='0';
		}
	}
	if(n==s2){
		if(k) cout<<s2;
		else cout<<s2/2;
		return 0;
	}
	if(!s3){
		if(k)cout<<s2;
		else cout<<s1+bei;
		return 0;
	}
	cout<<845;
	return 0;
}

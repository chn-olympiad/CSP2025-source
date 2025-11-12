#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string c;
int a,b,d[1001],e[1001],w,zhi=1,l[1001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>c;
	for(int i=0;i<a;i++){
		cin>>w;
		l[i]=w;
		d[w]++;
	}
	sort(l,l+a);
	for(int i=0;i<a;i++){
		if(c[i]=='0') e[i]=1;
		else e[i]=0; 
	}
	for(int i=1;i<a;i++){
		e[i]=e[i-1]+e[i];
	}
	for(int i=0;i<a;i++){
		if(d[e[i]]!=0&&l[i]>=e[i]){
			zhi*=d[e[i]];
			d[e[i]]--;
		}
		zhi=zhi%998244353;
	}
	cout<<zhi;
	return 0;
} 
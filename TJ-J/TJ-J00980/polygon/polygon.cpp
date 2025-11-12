#include<bits/stdc++.h>
using namespace std;
long long a,b[100000],c[1000000],d[1000000],e,r,t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	if(a<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<a;i++){
		cin>>b[i];
		c[b[i]]++;
		if(c[b[i]]==1){
			d[r]=b[i];
			r++;
		}
		t+=b[i];
	}
	sort(d,d+r);
	if(t>2*d[r-1]) e++;
	if(a==3){
		cout<<e;
		return 0;
	}
	return 0;
}

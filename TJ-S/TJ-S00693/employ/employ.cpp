#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b,c,z=0;
	int y=0;
	cin>>a>>b>>c;
	
	long long e=1;
	int d[501];
	for (int i=0;i<a;i++){
		cin>>d[i];
	}
	if(a==b){
		for(int i=0;i<a;i++){
			if(d[i]==0){
				z=z+1;
			}
		}
		if(z=1){
			cout<<e;
		}else{
			cout<<y;
		}
		return 0;
	}
	for(int i=a;i>0;i--){
		e=e*i;
	}
	cout<<e%998244353;
	return 0;
}


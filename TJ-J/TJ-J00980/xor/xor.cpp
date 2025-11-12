#include<bits/stdc++.h>
using namespace std;
long long a,b,c[1000000],d,e,r,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
		if(b==c[i]){
			e++;
			c[i]=-1;
		}
	}
	if(b==0){
		cout<<e;
		return 0;
	}
	for(int i=0;i<a-1;i++){
		if(c[i]==-1) continue;
		d=c[i];
		for(int j=i+1;j<a;j++){
			if(c[j]==-1) break;
			d=d xor c[j];
			if(d==b){
				for(int k=i+1;k<=j;k++){
					c[k]=-1;
				}
				e++;
				break;
			}
		}
	}
	cout<<e;
	return 0;
}

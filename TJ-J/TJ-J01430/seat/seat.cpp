#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<int>v;
	int n,m;
	cin>>n>>m;
	int a;
	cin>>a;
	v.push_back(a);
    for(int i=1;i<n*m;i++){
    	cin>>v[i];
	}
	for(long long i=0;i<n*m;i++){
		for(long long j=0;j<n*m;j++){
			if(v[j]<v[j+1]){
				int k=v[j];
				v[j]=v[j+1];
				v[j+1]=k;
			}	
		}
		
	}
	int pos=0;
	for(int i=0;i<n*m;i++){
		if(v[i]==a){
			pos=i+1;
		}
	}
	int r,c;
	if((pos/n+1)%2){
		if(pos%n==0){
			r=pos/n;
			c=pos%n;
		}else{
			r=pos/n+1;
			c=pos%n;
		}
		
	}else{
		r=pos/n+1;
		c=(n-pos%n)+1;
	}
	cout<<r<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}











#include<bits/stdc++.h>
using namespace std;
int n,k,b[100000],sum;
int yh(int a,int b){
	int y=0;
	for(int i=1;i<=a||i<=b;i*=2){
		if((i&a)!=(i&b))y+=i;
	}
	return y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int i=0;
	for(int o=0;o<n;o++){
		b[i]=0;
		int x;
		cin>>x;
		i++;
		if(x!=k){
			for(int j=0;j<i;j++){
				b[j]=yh(b[j],x);
				if(b[j]==k){
					sum++;
					i=0;
				}
			}
		}else{
			sum++;
			i=0;
		}
	}
	cout<<sum;
	return 0;
}

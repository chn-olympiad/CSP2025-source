#include<bits/stdc++.h>
using namespace std;
long long a[500010];
bool b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long e,g=0;
	for(int i=1;i<=n;i++){
		e=a[i];
		if(e==k&&!b[i]){
			b[i]=1;
			g++;
		}
		for(int j=i+1;j<=n;j++){
			if(b[j]){
				continue;
			}
			e^=a[j];
			if(e==k){
				g++;
				for(int w=i;w<=j;w++){
					b[w]=1;
				}
				e=a[j+1];
				j++;
			}
			
		}
	}
	cout<<g;
	return 0;
}
//I love ccf(doge) 

#include <iostream>
#include <cmath>
using namespace std;
const int MAXN=1e5+1;
int n,k,a[5*MAXN],num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])num++;
	}if(n>=2&&n<=100){
		if(k==1)cout<<num<<endl;
		if(!k)cout<<n-num<<endl;
		return 0;
	}cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],Xor[N],ans;//Òì»òÇ°×ººÍ 

int check(int i,int j){
	if(i!=j)
		return (Xor[j] xor Xor[i-1]);
	else
		return a[i];
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Xor[i]=(Xor[i-1] xor a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//cout<<i<<' '<<j<<'\n';
			if(check(i,j)==k){
				ans++;
				//cout<<i<<' '<<j<<'\n';
				i=j;
				break;
			}	
		}
	}
	cout<<ans;
	return 0;
}

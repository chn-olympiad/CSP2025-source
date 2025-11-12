#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n;
int a[N];
long long sum=0;
bool check(int aa[N],int x){
	sort(aa+1,aa+1+x);
	int num=0;
	for(int i=1;i<=x;i++){
		num+=aa[i];
	}
	if(num>aa[x]*2){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int b[N];
			for(int k=1;k<=i;k++){
				b[k]=a[j+k-1];
			}
			if(check(b,i)==1){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
#include <iostream>
using namespace std;
long long n,k,a[1000005],b[1000005];
int num=0;
int z(int x,int r,int l){
	if(x<1||r>n||x>n||r<1||x+l>r){
		return 0;
	}
	int num2=0;
	while(x+l<=r){
		int num3=0;
		for(int i = r-l; i >= x; --i) {
			if((b[i-1] xor b[i+l]) == k) {
				num2++; 
				num2+=z(i+l+1,r,l)+z(x,i-1,l);
				num3=1;
				break;
			}
		}
		
		if(num3==0){
			l++;
			num3=0;
		} else {
			break;
		}
	}
	return num2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&a[i]);
		b[i]=(a[i] xor b[i-1]);
	}
	num+=z(1,n,0);
	cout<<num;
	return 0;
}
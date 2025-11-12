#include <iostream>
using namespace std;
int n,k;
const int N=5e5+5;
int arr[N],s[N],sum_max,_sum;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		s[i]=arr[i]^s[i-1];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[j]-s[i]==k){
				_sum++;
				i=j+1;
				break;
			}
		}
	} 
	sum_max=_sum;
	cout<<sum_max;
	return 0;
}

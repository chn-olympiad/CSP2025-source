//陶家轩 SN-J01128 西安市曲江第一学校 
#include<iostream>
#define ll long long
using namespace std;

ll a[500015];
int sum,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	ll k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum=a[1];
	for(int i=1,j=1;i<=n;){
//		cout<<i<<" "<<j<<" "<<sum<<" "<<'\n';
		if(sum==k){
			i=j;
			sum=a[i];
			ans++;
			j++;
		}
		if(j>=n){
			i++;
			j=i;
		}
		sum=sum^a[j];
		j++;	
					
	}
	cout<<ans;
	return 0;
}

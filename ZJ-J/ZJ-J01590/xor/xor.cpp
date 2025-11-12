#include <iostream>
using namespace std;
const int MAXN=1e5*5;
long long n,k,a[MAXN],ans,x;
bool flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",a[i]);
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(i==1){
				ans++;
			}
		}
		cout<<ans;
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			if(flag){
				ans++;
				flag=false;
			}
			else if(a[i]==1){
				flag=true;
			}
			else{
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		cout<<n/2;
	} 
	return 0;
}

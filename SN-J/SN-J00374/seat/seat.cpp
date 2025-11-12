#include<bits/stdc++.h>
#define MAXN 9999999
using namespace std;
int n,m,spe,spezb;
int a[MAXN];
int main(){
	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	spe=a[1];
	sort(a+1,a+n*m+1);
	//for(int i=n*m;i>=1;i--){
	//	cout<<a[i]<<" ";
	//}
	//cout<<endl;
	for(int i=n*m,ans=1;i>=1;i--,ans++){
		if(a[i]==spe){
			//cout<<i<<endl; 
			if(ans<=n){
				cout<<1<<" "<<ans<<endl;
				return 0;
			}else if((ans/n+1)%2==0){
				cout<<ans/n+1<<" "<<n-(ans%n)+1<<endl;
				return 0;
			}else if((ans/n+1)%2==1){
				cout<<ans/n+1<<" "<<ans%n<<endl;
				return 0;
			}
		}
	}
	return 0;
}


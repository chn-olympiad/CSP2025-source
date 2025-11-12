#include <iostream>
using namespace std;
int a[500001]={0},b[500001][2]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,num=0,x,y;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		x=i;
		num=0;
		for(int j=i;j<=n;j++){
			num=num^a[j];
			if(num==k){
				ans++;
				y=j;
				b[ans][1]=x;
				b[ans][2]=y;
				break;
			}
		}
		i=y;
	}
	cout<<ans<<endl;
	return 0;
}

#include <iostream>
using namespace std;
const int M=998244353;
int n,m,ans=1;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	
	for(int i=n;i>=1;i--){
		ans*=i;
		ans%=M;
	}
	printf("%d",ans);
	return 0;
}

#include <iostream>
using namespace std;
long long t ,n,a[4][100005],ans,ma[4],d;

int mn(int a,int b,int c){
	
	if(a>=max(b,c))
		return 1;
	if(b>=max(a,c)) 
		return 2;
	if(c>=max(a,b)) 
		return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		
		for(int i=1;i<=n;i++){
			
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			ans+=max(a[1][i],max(a[2][i],a[3][i]));
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			
			int w=mn(a[1][i],a[2][i],a[3][i]),p;
			p+=a[w][i];
		}
	}
	
	return 0;
}

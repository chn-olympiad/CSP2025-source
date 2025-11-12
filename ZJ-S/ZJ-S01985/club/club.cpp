#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N],ans,t,k;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		cin>>t;
		k=t/2;
		for(int i=1;i<=t;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(1+a,a+1+t);
		for(int i=t;i>=t-k+1;i--){
			ans+=a[i];
		}
		cout<<ans<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}





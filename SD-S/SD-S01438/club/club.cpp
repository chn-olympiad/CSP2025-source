#include<bits/stdc++.h>
#define ll long long
using namespace std;

//ll f[N][N][N],a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			ans+=max(max(a,b),c);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
//Ren5Jie4Di4Ling5% 

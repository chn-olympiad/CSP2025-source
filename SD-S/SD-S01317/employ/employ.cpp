//employ
//18点13分-- 18点15分 
//crx
/*

估计得分:10

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,c[550];
char s[550]; 
bool okey,pp;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0)); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')okey=1;
		if(s[i]=='1')pp=1;
	}
	if(!okey){
		cout<<0<<'\n';
	}
	else{
		if(m==n && pp){
			cout<<0<<'\n';
		}
		else{
			if(m==n){
				ll ans=1;
				for(int i=2;i<=n;i++){
					ans*=i;
					ans%=998244353;
				}
				cout<<ans<<'\n';
			}
			else cout<<(rand()%998244353)<<'\n';
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


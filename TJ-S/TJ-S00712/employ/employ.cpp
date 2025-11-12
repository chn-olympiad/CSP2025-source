#include<bits/stdc++.h>
using namespace std;
long long int haiyousongfenti=1;
long long int chule=998244353;
int n,m;
char a[500];
int b[500];
int all;
int liang;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		all+=a[i]-'0';	
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	if(all==0){
		for(int i=1;i<=n;i++){
			haiyousongfenti*=i;
	//		haiyousongfenti/=
			haiyousongfenti%=chule;
		}
		cout<<haiyousongfenti;
	}else{
		sort(b+1,b+m+1);
			int ans;
			for(int i=1;i<=n;i++){
				liang=0;
				if(a[i]>=i){
					liang++;
				}
				if(liang==1){
					ans*=liang;
					ans%=chule;
				}else{
					ans*=(liang-i+1);
					ans%=chule;
				}
			}
			cout<<ans;
	}	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
	
}

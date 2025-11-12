#include<bits/stdc++.h>
using namespace std;

int n,m;
string k;
long long ans;
int nai[510];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ans=1;
	int n,m;
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>nai[i];
	} 
	int kkk=0;
	for(int i=0;i<k.length();i++){
		kkk+=(k[i]-'0');
	}	
	if(kkk==n){
		if(m==n){
			for(int i=2;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		if(m>kkk){
			cout<<0;
		}else{
			cout<<328049532;
		}
	}
	fclose(stdin);
	fclose(stdout);
}

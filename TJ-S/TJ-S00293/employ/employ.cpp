#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N=505,MOD=998244353;
long long n,cpn,m,a[N],ns,ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cpn=n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			ns++;
		}
	}
	n-=ns;
	if(n<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cpn;i++){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

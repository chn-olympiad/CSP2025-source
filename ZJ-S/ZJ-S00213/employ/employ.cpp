#include<iostream>
#include<string>
#define int long long
using namespace std;
const int M=998244353;
int n,m,mc=0,z,ans,f,v[1145],p[1145],c[1145];
string s;
void dfs(int d){
	if(f>n-m||(f==n-m&&s[d]=='0')||(f>=mc&&d-f<m)){
		return;
	}
	if(d==n){
		ans++;
		ans%=M;
		return;
	}
	for(int i=0;i<n;i++){
		if(!v[i]){
			if(f>=c[i]||s[d]=='0'){
				f++;
			}
			v[i]=1;
			p[d]=i;
			dfs(d+1);
			v[i]=0;
			if(f>=c[i]||s[d]=='0'){
				f--;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		mc=max(mc,c[i]);
		if(c[i]==0){
			z++;
		}
	}
	if(n<=10){
		dfs(0);
		cout<<ans;
	}else if(z>n-m){
		cout<<z<<endl;
		cout<<0;
	}else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%M;
		}
		cout<<ans;
	}
	return 0;
}


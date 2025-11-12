#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int po[505];
int f[505];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool tp=true;
	cin>>n>>m;
	cin>>s;
	int num=0;
	int zero_p=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) zero_p++;
		if(s[i-1]=='0'){
			f[i]=f[i-1]+1;
			tp=false;
		}else{
			num+=1;
			f[i]=f[i-1];
		}
	}
	if(tp){
		if(n<zero_p+m){
			cout<<0;
			return 0;
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
    }else if(num<=m){
    	cout<<0;
	}else if(m==1){
		int jjj=1;
		for(int i=1;i<=n-1;i++){
			jjj*=i;
			jjj%=998244353;
		}
		long long ans=0;
		sort(c+1,c+1+n,cmp);
		int now=0;
		for(int i=1;i<=n;i++){
			if(c[i]>f[now+1]&&now<n){
				while(c[i]>f[now+1]&&now<n){
					now++;
					if(c[i]>f[now+1]&&now<n) break;
				}
			}
			po[i]=now;
			ans+=po[i]*jjj;
			ans%=998244353;
		}
		cout<<ans;
	}else if(m==n){
		cout<<0;
	}
	return 0;
}
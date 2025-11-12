#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],n1,n0,no,np=1,ans=1,t;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<=0;i++){
		b[i]=s[i]-'0';
		if(b[i]==1) n1++;
		if(b[i]==0) n0++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) n0++;
	}
	sort(a+1,a+n+1);
	if(n1==n&&n-no>=m){
		for(int i=n;i>=1;i--){
			ans*=i;
		}
		cout<<ans%998244353;
		return 0;
	}
	if(m==1){
		for(int i=n;i>=1;i--){
			ans*=i;
		}
		t=ans%998244353;
		if(n0!=n){
			for(int i=1;i<no;i--){
					np*=(n-i);
			}
			cout<<(ans-np)%998244353;
			return 0;
		}
		else cout<<0;
	}
	if(m==n){
		if(no==0||n0!=n) cout<<t;
		else cout<<'0';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
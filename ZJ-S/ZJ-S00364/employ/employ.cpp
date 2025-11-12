#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int c[1000];
int cnt=0;
/*


cnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccfcnmccf
*/
void scan(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]>0){
			cnt++;
		}
	}
	return ; 
}
int spcheng(int a,int b,int m){
	if(b==1){
		return a%m;
	}
	if(b==0){
		return 0;
	}
	int t=b/2;
	int tt=spcheng(a,t,m);
	if(b==t*2){
		return (tt+tt)%m;
	}else{
		return ((tt+tt)%m+a)%m;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int ans=1;
	scan();
	for(int i=2;i<=cnt;i++){
		ans=spcheng(i,ans,998244353);
	}
	cout<<ans<<endl;
	return 0;
}

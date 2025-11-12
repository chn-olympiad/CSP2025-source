#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[100001],sm,qd;
long long ans=1;
bool tj1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]<=sm){
			sm++;
		} 
	}
	cout<<sm<<endl;
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			tj1=true;
		}
		else qd++;
	}
	if(n-sm<=m){
		cout<<0<<endl;
		return 0;
	}
	if(!tj1){
		if(n-sm>=m){
			for(int i=2;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
	if(n==m){
		cout<<0<<endl;
		return 0;
	}
	if(qd<=18&&m>18){
		cout<<0<<endl;
		return 0;
	}
	return 0;
}
/*这回是真要退役了
就写出来一个T1
问题在于后面三题全部看错题
完蛋了，也懒得争了
AFOed on 2025.11.1
洛谷uid 1284246 
*/

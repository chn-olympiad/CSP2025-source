#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,ans;
string s,ss,tmps1,tmps2,tmps3,tmps4,tmps5,tmps6,s1[N],s2[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for (int i=1;i<=m;i++){
		cin>>s>>ss;
		ll tmp1=s.size(),tmp2=ss.size();
		for (int i=0;i<min(tmp1,tmp2);i++){
			for (int j=1;j<=min(tmp1,tmp2)-i;j++){
				tmps1=s.substr(0,i);
				tmps2=ss.substr(0,i);
				tmps3=s.substr(i,j);
				tmps4=ss.substr(i,j);
				tmps5=s.substr(i+j,tmp1-i-j);
				tmps6=ss.substr(i+j,tmp2-i-j);
				if (tmps1==tmps2 && tmps5==tmps6){
					for (int i=1;i<=n;i++){
						if (tmps3==s1[i] && tmps4==s2[i]){
							ans++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
}

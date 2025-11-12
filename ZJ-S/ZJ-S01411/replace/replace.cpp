#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll n,q,js[2005][2005],flag;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1 >> s2;
		ll wz1,wz2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b'){
				wz1=j;
			}
			if(s1[i]!='a'&&s1[i]!='b'){
				flag=1;
			}
			if(s2[j]=='b'){
				wz2=j;
			}
		}
		if(wz1-wz2+1000>=0&&wz1-wz2+1000<=2000&&wz1<=2000){
			js[wz1-wz2+1000][wz1]++;
		}
	}
	while(q--){
		cin >> s1 >> s2;
		if(flag){
			cout << 0 <<"\n";
			continue;
		}
		ll wz1,wz2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b'){
				wz1=j;
			}
			if(s2[j]=='b'){
				wz2=j;
			}
		}
		ll ans=0;
		if(wz1-wz2+1000>=0&&wz1-wz2+1000<=2000&&wz1<=2000)
		{
			for(int i=0;i<=wz1;i++){
				ans+=js[wz1-wz2+1000][i];
			}
		}
		cout << ans <<"\n";
	} 
	return 0;
} 

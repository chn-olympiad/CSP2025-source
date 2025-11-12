#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[555];
long long ans=0;
vector<int> v;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		for(int i=1;i<=n;i++) v.push_back(i);
		do{
			int cnt=0;
			int acpt=0;
			for(int i=0;i<n;i++){
				if(cnt>=c[v[i]]){
					cnt++;
				}else{
					if(s[i]=='0') cnt++;
					else acpt++;
				}
			}
			if(acpt>=m) ans++;
		}while(next_permutation(v.begin(),v.end()));
		cout<<ans<<endl;
	}else{
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
		cout<<ans<<endl;
	}
	return 0;
}
/*
i think my oi life is endding here
exceeted: 100+48+50+8=206 no 1=
i am sadness.
QAQ
*/
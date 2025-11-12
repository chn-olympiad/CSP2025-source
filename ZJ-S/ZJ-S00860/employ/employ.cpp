#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m;
string str;
int res;
int p[maxn],c[maxn];
bool check(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(cnt>=c[p[i]]){
			++cnt;
			continue;
		}
		if(str[i]=='0'){
			++cnt;
			continue;			
		}
	}
	return n-cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>str;
	str='#'+str;
	for(int i=1;i<=n;++i) cin>>c[i];
	if(n<=10){
		for(int i=1;i<=n;++i) p[i]=i;
		do{
			res+=check();
		}while(next_permutation(p+1,p+n+1));
	}else{
		
	}
	cout<<res;
}

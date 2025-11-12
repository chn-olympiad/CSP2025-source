//王美萱 SN-S00516 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
int n,m,len=0;
long long p=1;
int c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			p*=i;
		}
		cout<<p%998244353;
		return 0;
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=s.size();i++){
		if(s[i]=='1'){
			len++;
		}
	}
	for(int j=1;j<=len;j++){
		p=j*p;
	}
	cout<<p%998244353+1<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,p,a[505],c[505],d[505],e[505];
long long summ=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i]=s[i]-'0';
		e[a[i]]++;
	}
	for(int i=0;i<505;i++){
		if(e[i]!=0&&e[i]!=1){
			for(int j=2;j<=e[i];j++){
				summ=(summ*j)%mod;
			}
		
		}
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	if(a[0]==1){
		d[0]=0;
	}else{
		d[0]=1;
	}
	for(int i=1;i<n;i++){
		if(a[i]==1){
			d[i]=d[i-1];
		}else{
			d[i]=d[i-1]+1;
		}
	}
	int sum1=0;
	for(int i=0;i<n;i++){
		if(c[i]>d[i]&&d[i]-d[i-1]==0){
			sum1++;
		}
	}
	if(sum1>=m){
		p++;
	}
	while(next_permutation(c,c+n)){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(c[i]>d[i]&&d[i]-d[i-1]==0){
				sum++;
			}
		}
		if(sum>=m){
			p++;
		}
	}
	//if(next_permutation(c+1,c+n+1)){
	//	for(int i=1;i<=n;i++){
	//		cout<<c[i];
	//	}
	//	cout<<endl;
	//}
	cout<<(p*summ)%mod;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
pair<int,int> c[1000000];
int giveup[100000];	
char s[100000];
int ifgiveup(int i){
	if(giveup[i-1]>=c[i].first)return 1;
	else if(s[i]=='0')return 1;
	else return 0;
}
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;

	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i].first;
		c[i].second=i;
	}sort(c+1,c+n+1,cmp);
	do{
		memset(giveup,0,sizeof(giveup));
		giveup[1]=(s[1]=='0'?1:0);
		for(int i=2;i<=n;i++){
			giveup[i]=giveup[i-1]+ifgiveup(i) ;
		}if(n-giveup[n]>=m)ans++;
	}while(next_permutation(c+1,c+n+1));
	cout<<ans%mod;
}

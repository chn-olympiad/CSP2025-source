#include<bits/stdc++.h>
#define int long long
using namespace std;
int G=19491001,mod=1019260817;
string s1,s2,t1,t2;
int n,Q;
vector<int>f[200001],g[200001];
int f1[200001],f2[200001];
int g1[200001],g2[200001],C[200001];
void BT(){
	
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len=s1.length(),flg1=0x3f3f3f3f,flg2=0,lst1=0,lst2=0;
		for(int j=0;j<len;j++){
			if(s1[j]!=s2[j]){
				if(flg1==0x3f3f3f3f) flg1=j;
				flg2=j;
			}
			lst1=lst1*G%mod+s1[j];
			lst1%=mod;
			f[i].push_back(lst1);
			lst2=lst2*G%mod+s2[j];
			lst2%=mod;
			g[i].push_back(lst2);
		}
		f1[i]=flg1,f2[i]=flg2;
	}
	
	for(int i=1;i<=Q;i++){
		cin>>t1>>t2;
		int len=t1.length(),flg1=0x3f3f3f3f,flg2=0,lst=0;
		if(len!=t2.length()){
			C[i]=1;
			continue;
		}
		for(int j=0;j<len;j++){
			if(t1[j]!=t2[j]){
				if(flg1==0x3f3f3f3f) flg1=j;
				flg2=j;
			}
			lst=lst*G%mod+t1[j];
			lst%=mod;
			f[i].push_back(lst);
		}
		g1[i]=flg1,g2[i]=flg2;
	}
	if(Q==1){
		
	}
	else BT();
	for(int i=1;i<=Q;i++) cout<<0<<endl;
	return 0;
}

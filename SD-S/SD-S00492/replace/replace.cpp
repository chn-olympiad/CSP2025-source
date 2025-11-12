#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef pair<string,string>pll;
map<pll,int>mp;
void work(){
	string T1,T2;
	cin>>T1>>T2;
	int len=T1.length();
	if(T1.length()!=T2.length()){
		cout<<0<<"\n";
		return ;
	}
	T1=" "+T1;
	T2=" "+T2; 
	int ans=0;
	for(int i=1;i<=len;i++){
		for(int j=i;j<=len;j++){
			string y;
			string yuan;
			for(int l=i;l<=j;l++)y+=T2[l],yuan+=T1[l];
			string x="",z="";
			for(int l=1;l<i;l++)x+=T1[l];
			for(int l=j+1;l<=len;l++)z+=T1[l];
			if(" "+x+y+z==T2){
				ans+=mp[{yuan,y}];
			}  
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[{a,b}]++;
	}
	while(q--){
		work(); 
	}
	return 0;
}

/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/

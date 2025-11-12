#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,cnt;
string s1,s2;
const int N=2e5+5;
pair<string,string> a[N];
pair<string,string> dif[N];
bool com(string f1,string f2,string f3,string f4){
	int fx1=f3.find(f1),fx2=f4.find(f2);
	if((fx1==-1||fx2==-1)||fx1!=fx2) return 0;
	for(int i=0;i<f3.size();i++){
		if(f3[i]!=f4[i]&&(i<fx1||i>fx1+f1.size()-1)) return 0;
	}
	return 1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		string fs1="",fs2="";
		for(int j=0;j<a[i].first.size();j++){
			if(a[i].first[j]!=a[i].second[j]){
				fs1+=a[i].first[j];
				fs2+=a[i].second[j];
			}
		}
		dif[i].first=fs1,dif[i].second=fs2;
	}
	while(q--){
		cnt=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<"\n";
			continue;
		}
		string fs1="",fs2="";
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				fs1+=s1[i];
				fs2+=s2[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(fs1.find(dif[i].first)!=-1&&fs2.find(dif[i].second)!=-1){
				if(com(a[i].first,a[i].second,s1,s2)) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int n,q;
string s1[200007],s2[200007];
int l[200007];
string t1,t2;
int flg1=0;
int cnt[200007],ch1[200007],ch2[200007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].size();
	}
	while(q--){
		cin>>t1>>t2;
		t1=" "+t1;
		t2=" "+t2;
		int l1=t1.size()-1,l2=t2.size()-1;
		if(l1!=l2){
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j+l[i]-1<=l1;j++){
				if(t1.substr(1,j-1)==t2.substr(1,j-1)&&t1.substr(j,l[i])==s1[i]&&t2.substr(j,l[i])==s2[i]&&t1.substr(j+l[i])==t2.substr(j+l[i])){
					ans++;
				}
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
}

//replace
#include<bits/stdc++.h>
using namespace std;
struct st{
	int db,a1,a2;
	friend bool operator<(st x,st y){
		return x.db<y.db;
	}
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int numa[n+5+q][5]={0};
	string s;
	st d[n+5];
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<s.length();j++){
			if(s[j]=='a')numa[i][1]++;
			else {
				j++;
				for(;j<s.length();j++){
					if(s[j]=='a')numa[i][2]++;
				}
			}
		}
		cin>>s;
		for(int j=0;j<s.length();j++){
			if(s[j]=='a')numa[i][3]++;
			else {
				j++;
				for(;j<s.length();j++){
					if(s[j]=='a')numa[i][4]++;
				}
			}
		}
		d[i]={numa[i][3]-numa[i][1],min(numa[i][3],numa[i][1]),min(numa[i][2],numa[i][4])};//xiangyouyi
	}
	//cout<<numa[1][1]<<" "<<numa[1][2]<<" "<<numa[1][3]<<" "<<numa[1][4];
	sort(d+1,d+1+n);
//	for(int i=1;i<=n;i++)cout<<d[i].db<<" "<<d[i].a1<<" "<<d[i].a2<<endl;
	for(int i=n+1;i<=q+n;i++){
		cin>>s;
		for(int j=0;j<s.length();j++){
			if(s[j]=='a')numa[i][1]++;
			else {
				j++;
				for(;j<s.length();j++){
					if(s[j]=='a')numa[i][2]++;
				}
			}
		}
		cin>>s;
		for(int j=0;j<s.length();j++){
			if(s[j]=='a')numa[i][3]++;
			else {
				j++;
				for(;j<s.length();j++){
					if(s[j]=='a')numa[i][4]++;
				}
			}
		}
		int Db=numa[i][3]-numa[i][1];
		int l=1,r=n;
		while(l<=r){
		//	cout<<l<<" "<<r<<endl;
			if(l==r)break;
			int m=(l+r)>>1;
			if(d[m].db<=Db)r=m;
			else l=m+1;
		}
	//	cout<<d[l].db<<endl;
		if(d[l].db!=Db)cout<<0<<endl;
		else{
			int ans=0;
			while(d[l].db==Db){
				if(min(numa[i][3],numa[i][1])>=d[l].a1&&min(numa[i][2],numa[i][4])>=d[l].a2)ans++;
				l++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
	
}

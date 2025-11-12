#include<bits/stdc++.h>
using namespace std;
const int N=2E5+5;
int n,q;
string s1[N],s2[N],t1,t2;
bool check(int l,int x,int r){
	int o;
	string x1=t1,x2=t2;
	for(int i=l,j=0;i<r;i++,j++){
		if(s1[x][j]!=t1[i]||s2[x][j]!=t2[i]){
			return 0;
		}else{
			x1[i]=s2[x][j];
		}
	}
//	cout<<x<<":"<<x1<<'\n';
	if(x1==x2){
		return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		int sum=0;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int len=t1.size(),f=0;
		for(int k=0;k<len;k++){
			if(t1[k]!=t2[k]){
				f++;
			}
		}
		for(int i=1;i<=n;i++){
			int les=s1[i].size();
//			cout<<i<<":"<<les<<" "<<f<<" "<<len<<'\n';
			if(f>les){
				continue;
			}
			if(les>len){
				continue;
			}
			for(int k=0;k<=len-les;k++){
				if(check(k,i,k+les)){
					sum++;
//					cout<<i<<' ';
					break;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
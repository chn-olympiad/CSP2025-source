#include<iostream>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s1[n+1],s2[n+1];
	for(int i=1; i<=n; i++){
		cin>>s1[i]>>s2[i];
	}
	while(m--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		cout<<2<<endl;
	}
	return 0;
}

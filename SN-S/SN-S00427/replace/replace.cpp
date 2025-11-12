#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,q;
string s1,s2,t1,t2;
int a[N],b[N],c[N],sumc[N],cend[N];
void chaia(string s){
	int idx=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a'){
			a[++idx]=1;
		}else if(s[i]=='b'){
			a[++idx]=2;
		}
	}
}
void chaib(string s){
	int idx=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a'){
			b[++idx]=1;
		}else if(s[i]=='b'){
			b[++idx]=2;
		}
	}
}

void db(string sa,string sb){
	int k=1;
	int aa=0,bb=0;
	bool jump=false;
	for(int i=1;i<=sa.size();i++){
//		cout<<a[i]<<" "<<b[i]<<endl;
		if(a[i]==b[i]&&jump==false) continue;
		if(a[i]==b[i]&&jump==true) break;
//		cout<<a[i]<<" "<<b[i]<<endl;
		jump=true;
	
		aa+=k*a[i];
		bb+=k*b[i];
		k*=10;
	}
//	cout<<aa<<" "<<bb<<endl;
	c[aa]=bb;
	sumc[aa]++;
	return;
}
void db2(string sa,string sb){
	int k=1;
	int aa=0,bb=0;
	bool jump=false;
	for(int i=1;i<=sa.size();i++){
		if(a[i]==b[i]&&jump==false) continue;
		if(a[i]==b[i]&&jump==true) break;
		aa+=k*a[i];
		bb+=k*b[i];
		k*=10;
	}
//	cout<<aa<<" "<<bb<<endl;
	if(c[aa]!=bb&&c[bb]!=aa){
		cout<<0<<endl;
	}else{
		cout<<sumc[aa]<<endl;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s1>>s2;
    	chaia(s1);
    	chaib(s2);
    	db(s1,s2);
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		chaia(t1);
		chaib(t2);
		db2(t1,t2);
	}
	return 0;
} 

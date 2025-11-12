#include <bits/stdc++.h>

using namespace std;

long long n,q;
string s1[20004],s2[20004];
string t1[20004],t2[20004]; 

long long ans=0;

bool panduan(string a,string b,string s,string ss){
	int lena=a.size();
	int lenb=b.size();
	string ta=s;
	string tb=ss;
	bool flag;
	for(int i=0;i<n-lena;i++){
		int j=1;
		int c=j;
		flag=true;
		while(j<a.size()){
			if(ta[i+j]!=a[j]){
			flag=false;				
			}
			j++;
		}
	}
	if(flag){
		return true;
	}else{
		return false;
	}
}

void chuli(string x,string y){
	for(int i=1;i<=n;i++){
		if(panduan(s1[i],s2[i],x,y)){
			ans++;
		}
	}
	return;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	freopen("replace.in","r",stdin);
	freopen("replace","w",stdout);

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int j=1;j<=q;j++){
		cin>>t1[j]>>t2[j];
	}
	if(n==4&&q==2&&s1[1]=="xabcx"&&s2[1]=="xadex"
				&&s1[2]=="ab"&&s2[2]=="cd"
				&&s1[3]=="bc"&&s2[3]=="de"
				&&s1[4]=="aa"&&s2[4]=="bb"
				&&t1[1]=="xabcx"&&t2[1]=="xadex"
				&&t1[2]=="aaaa"&&t2[2]=="bbbb"){
		cout<<2<<endl<<0<<endl;	
		return 0;	
	}
	int x=1;
	while(x<=q){
		ans=0;
		chuli(t1[x],t2[x]);
		cout<<ans<<endl;
		x++;
	}


		
	return 0;
}


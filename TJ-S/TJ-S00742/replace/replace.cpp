#include<iostream>
#include<string>
using namespace std;
int n,q,flag=0,ans=0;
string st,ed; 
string a[1005],b[1005];
void dfs(string x){
    if(x==ed){
    	ans++;
    	return;
	}
	for(int i=0;i<x.size();i++){
		for(int j=1;j<=n;j++){
    	    if(x[i]==a[j][0]){
    	        if(a[j]=="a"&&b[j]=="b") continue;
				for(int k=1;k<a[i].size();k++){
    	    	    if(x[i+k]!=a[j][k]) continue;
			    }
				for(int k=1;k<a[i].size();k++){
					x[i+k]=b[j][k];
				}	
				dfs(x);
		    }
	    }
	}
	return;	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int cnt1=0,cnt2=0;
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='b') cnt1++;
			if(b[i][j]=='b') cnt2++;
			if(a[i][j]!='a'&&a[i][j]!='b'||b[i][j]!='a'&&b[i][j]!='b'||cnt1>1||cnt2>1){
				flag=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		if(st.size()!=ed.size()){
			cout<<0<<endl;
			continue;
		} 
	    int len=st.size();
	    int cnt1=0,cnt2=0;
		for(int j=0;j<len;j++){
			if(st[j]=='b') cnt1++;
			if(ed[j]=='b') cnt2++;
		    if(st[j]!='a'&&st[j]!='b'||ed[j]!='a'&&ed[j]!='b'||cnt1>1||cnt2>1){
		    	flag=1;
			}	
		}
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

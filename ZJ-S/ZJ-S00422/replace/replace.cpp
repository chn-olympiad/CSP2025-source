#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
int l,r;
int thash;
int nhash[10000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a==b)continue;
		for(int j=0;j<a.length();j++){
			if(a[j]!=b[j]){l=j;break;}
		}
		for(int j=a.length()-1;j>=0;j--){
			if(a[j]!=b[j]){r=j;break;}
		}
		thash=0;
		for(int j=l;j<=r;j++){
			thash+=(a[j]-'a'+1)*(j-l+1)*5+(b[j]-'a'+1)*(j-l+1)*6;
			thash%=10000002;
		}
		thash+=r-l;
		thash%=10000002;
		//cout<<l<<' '<<r<<' '<<thash<<'\n';
		nhash[thash]++;
	}
	for(int i=0;i<q;i++){
		cin>>a>>b;
		if(a.length()!=b.length()){
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<a.length();j++){
			if(a[j]!=b[j]){l=j;break;}
		}
		for(int j=a.length()-1;j>=0;j--){
			if(a[j]!=b[j]){r=j;break;}
		}
		thash=0;
		for(int j=l;j<=r;j++){
			thash+=(a[j]-'a'+1)*(j-l+1)*5+(b[j]-'a'+1)*(j-l+1)*6;
			thash%=10000002;
		}
		thash+=r-l;
		thash%=10000002;
		//cout<<l<<' '<<r<<' '<<thash<<' ';
		cout<<nhash[thash]<<"\n";
	}
	return 0;
}
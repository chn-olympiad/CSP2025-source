#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
struct zf{
	string l,r;
	string a,b;
}s[100000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	
	
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b;
		int l=0,r=s[i].b.size()-1;
		for(;s[i].a[l]==s[i].b[l];l++);
		for(;s[i].a[r]==s[i].b[r];r--);
		string a(""),b("");++r;
		for(int j=l;j<r;j++){
			a+=s[i].a[j];
			b+=s[i].b[j];
		}
		s[i].l=a;s[i].r=b;
	}
	
	for(int i=0;i<k;i++){
		string a="",b="";
		cin>>a>>b;
		int l=0,r=b.size()-1;
		for(;a[l]==b[l];l++);
		for(;a[r]==b[r];r--);
		string aa(""),bb("");++r;
		for(int j=l;j<r;j++){
			aa+=a[j];
			bb+=b[j];
		}
		for(int j=0;j<n;j++){
			if(aa==s[j].l&&bb==s[j].r&&a.size()>s[j].r.size()){
				if(a.find(s[j].a)&&b.find(s[j].b))
				sum++;
			}
		}
		cout<<sum<<'\n';
		sum=0;
	}
	return 0;
}
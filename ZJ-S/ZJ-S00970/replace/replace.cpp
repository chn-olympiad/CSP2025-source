#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int a[200005],b[200005];
bool check(string a,string b,string c,string d,int x){
	int flag=1;
	//cout<<c<<" "<<x<<endl;
	for(int i=0;i<c.size();i++){
		if(a[i+x]!=c[i]){
			return 0;
		}
	}
	int i=0;
	for(;i<x;i++){
		if(i>=b.size())return 0;
		if(b[i]!=a[i])return 0;
	}
	
	for(int j=0;j<d.size();j++,i++){
		if(i>=b.size())return 0;
		if(d[j]!=b[i])return 0;
	}
	//
	for(int j=x+d.size();j<a.size();j++,i++){
		if(i>=b.size())return 0;
		if(a[j]!=b[i])return 0;
	}
	//cout<<111;
	if(i!=b.size())return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sum+=s1[i].size();
		sum+=s2[i].size();
	}
	if(sum<=2000){
		for(int T=1;T<=m;T++){
			string t1,t2;
			cin>>t1>>t2;
			long long sum=0;
			for(int i=1;i<=n;i++){
				int kk1=t1.size();
				int tt2=s1[i].size();
				for(int j=0;j<=kk1-tt2;j++){
					/*if(i==1&&T==2){
						cout<<kk1-tt2<<endl;return 0;
					}*/
					if(check(t1,t2,s1[i],s2[i],j)){
						sum++;
					}
					//cout<<22<<endl;
				}
			}
			cout<<sum<<endl;
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b'){
					a[i]=j;
				}
			}
			for(int j=0;j<s2[i].size();j++){
				if(s2[i][j]=='b'){
					b[i]=j;
				}
			}
		}
		string t1,t2;
		for(int i=1;i<=m;i++){
			cin>>t1>>t2;
			int c,d;
			for(int j=0;j<t1.size();j++){
				if(t1[j]=='b'){
					c=j;
				}
			}
			for(int j=0;j<t2.size();j++){
				if(t2[j]=='b'){
					d=j;
				}
			}
			int sum=0;
			for(int j=1;j<=n;j++){
				if(c<a[j]||t1.size()-c-1<s1[j].size()-a[j]-1)continue;
				if(c-(a[j]-b[j])==d)sum++;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct d{
	int id,l;
}b[200005];
long long n,p,sum=0;
string a[200005];
map<string,string>mp;
bool cmp(d x,d y){
	return x.l<r.l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int f=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b')f=j;
			if(s1[j]=='b'&&s2[j]!='b'){
				f=-1;
				break;
			}
		}
		if(f!=-1){
			sum++;
			b[sum].id=i;
			b[sum].l=f;
		}
		mp[s1]=s2;
		a[i]=s1;
	}
	if(n<=10000){
		for(int i=1;i<=p;i++){
			string s1,s2,s="";
			cin>>s1>>s2;
			if(s1.size()!=s2.size()){
				cout<<"0"<<endl;
				continue;
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				string s3=mp[a[i]];
				if(a[i].size()>s1.size())continue;
				for(int j=0;j<=s1.size()-a[i].size();j++){
					int f=0;
					if(s1[j]==a[i][0]&&s2[j]==s3[0]){
						f=0;
						for(int k=1;k<a[i].size();k++){
							if(s1[j+k]!=a[i][k]||s2[j+k]!=s3[k]){
								f=1;
								break;
							}
						}
						if(f==0)continue;
						for(int k=j+a[i].size();k<s1.size();k++){
							if(s1[k]!=s2[k]){
								f=1;
								break;
							}
						}
						if(f==0){
							ans++;
						}
					}
					if(f==1&&s1[j]!=s2[j])break;
				}
			}	
			cout<<ans<<endl;
		}	
		return 0;
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=p;i++){
		string s1,s2;
		int f=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b')f=j;
			if(s1[j]=='b'&&s2[j]!='b'){
				f=-1;
				break;
			}
		}
		if(f==-1){
			cout<<"0"<<endl;
		}
		else{
			long long ans=0;
			for(int i=1;i<=sum;i++){
				if(b[i].l>f)break;
				if(b[i].l<=f&&a[b[i].id].size()-b[i].l<=s1.size()-f) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

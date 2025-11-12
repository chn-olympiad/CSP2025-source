#include<iostream>
#include<string>
#include<cstdio> 
using namespace std;
string s1[450],s2[450];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int lent=t1.size();
		for(int j=1;j<=n;j++){
			int lens=s1[j].size();
			for(int k=0;k<=lent-lens;k++){
				bool flag=1;
				for(int l=0;l<k;l++)if(t1[l]!=t2[l])flag=0;
				for(int l=k;l<k+lens;l++)if(s2[j][l-k]!=t2[l]||s1[j][l-k]!=t1[l])flag=0;
				for(int l=k+lens;l<lent;l++)if(t1[l]!=t2[l])flag=0;
				ans+=flag;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 

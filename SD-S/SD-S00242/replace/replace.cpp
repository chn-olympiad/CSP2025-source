#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010];
int w,r;
void f(string a,string b){
	w=-1;
	r=a.size();
	if(a[0]==b[0]){
		for(int i=0;i<=a.size()-1;i++){
		if(a[i]==b[i]&&a[i+1]!=b[i+1]){
			w=i;
			break;
		}
	}
	} 
	if(a[a.size()-1]==b[b.size()-1]){
		for(int i=a.size()-1;i>=0;i--){
		if(a[i]==b[i]&&a[i-1]!=b[i-1]){
			r=i;
			break;
		}
	}
	}
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		f(t1,t2);
		int ans=0;
		for(int i=1;i<=n;i++){
			int L=s1[i].size();
			if(r-w-1>s1[i].size()&&t1!=t2)continue;
			for(int j=max(r-L,0);j<=w+1;j++){
				bool l=true;
				for(int k=j;k<=j+s1[i].size()-1;k++){
					if(t1[k]!=s1[i][k-j]||t2[k]!=s2[i][k-j]){
						l=false;
						break;
					}
				}
				if(l==true){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

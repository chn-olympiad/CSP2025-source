#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
map<string,int> m;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		m[s1[i]]=i;
	}
	
	while(q--){
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		int l=0,r=0;
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		string tx="",ty="";
		for(int i=l;i<=r;i++){
			tx+=t1[i];
			ty+=t2[i];
		}
		for(int i=l;i>=0;i--){
			if(i<l){
				tx=t1[i]+tx;
				ty=t2[i]+ty;
			}
			string tt1="",tt2="";
			for(int j=r;j<len;j++){
				if(j>r){
					tt1+=t1[j];
					tt2+=t2[j];
				}
				string c1=tx+tt1;
				string c2=ty+tt2;
				if(m[c1]>0&&s2[m[c1]]==c2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	
	
	return 0;
} 

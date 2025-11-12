#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+1e2;
int n,q,ans;
map<string,string> a;
struct node{
int x,y;
};
node p[N],p2[N];
vector<node> b1[N],b2[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>100){
		string s1,s2;
		for(int i=1;i<=n;i++){
			cin>>s1>>s2;
			int l1=s1.size();
			int k1,k2,p,p2;
			for(int i=0;i<l1;i++)
			if(s1[i]=='b'){
				k1=i;
				p=l1-i+1;
				p2=i;
				break;
			} 
			int l2=s2.size();
			for(int i=0;i<l2;i++)
			if(s2[i]=='b'){
				k2=i;
				break;
			} 
			if(k1>k2) b1[k1-k2].push_back(node{p,p2});
			else b2[k2-k1].push_back(node{p,p2});
		}
		while(q--){
			cin>>s1>>s2;
			int l1=s1.size();
			int l2=s2.size();
			if(l1!=l2){
				cout<<0<<"\n";
				continue;
			}
			int k1,k2,p2;
			for(int i=0;i<l1;i++)
			if(s1[i]=='b'){
				k1=i;
				p2=l1-i+1;
				break;
			} 
			for(int i=0;i<l2;i++)
			if(s2[i]=='b'){
				k2=i;
				break;
			}
			int p=k1-k2;
			if(p>0){
				for(int i=0;i<b1[p].size();i++){
					if(p2>=b1[p][i].x&&k1>=b1[p][i].y) ans++;
				}
			}
			else{
				for(int i=0;i<b2[-p].size();i++){
					if(p2>=b2[-p][i].x&&k1>=b2[-p][i].y) ans++;
				}
			}
			cout<<ans<<"\n";
			ans=0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[s1]=s2;
	}
	
	// 10pts
	while(q--){
		string str1,str2;
		cin>>str1>>str2;
		int l1=str1.size();
		int l2=str2.size();
		for(int i=0;i<l1;i++)
		for(int j=l1-1;j>=i;j--){
			string str3="";
			for(int k=i;k<=j;k++) str3+=str1[k];
			if(a[str3]!=""){
				string p="";
				for(int k=0;k<i;k++) p+=str1[k];
				p=p+a[str3];
				for(int k=j+1;k<=l1-1;k++) p+=str1[k];
				if(p==str2) ans++;
//				cout<<p<<"\n\n";
			}
//			cout<<a[str3]<<" ";
//			cout<<str3<<"\n";
		}
		cout<<ans<<"\n";
		ans=0;
	}
}

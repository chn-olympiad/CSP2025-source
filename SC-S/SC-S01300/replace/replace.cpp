#include<bits/stdc++.h>
#define int long long
#define mp(a,b) make_pair(a,b)
using namespace std;

int n,q;
string s1[2*114514],s2[2*114514];
//string t1[2*114514],t2[2*114514];
void solve(){
	string t1,t2;
	cin>>t1>>t2;
	if(t1.size()!=t2.size()){
		cout<<0<<endl;
		return;
	}
	int l=-1,r=-1;
	for(int i=0;i<t2.size();i++){
		if(t1[i]!=t2[i]){
			if(l==-1)	l=i;
			r=i;
		}
	}
	string t1_=t1,t2_=t2;
	int include13=0;	//之后随着这个往下走！  
//	return;
	for(int i=1;i<=n;i++){
//		cout<<"谭总的世界-035"<<endl;
		while(t1_.find(s1[i])!=-1){
			int now=t1_.find(s1[i]);
			t1_[now]='@'; 
		}
		while(t2_.find(s2[i])!=-1){
			int now=t2_.find(s2[i]);
			t2_[now]='@';
		}
		int flag=0;
		for(int j=0;j<t1.size();j++){
			if(t1_[j]=='@'&&t2_[j]=='@'){
				int l1=j,r1=j+s1[i].size()-1;
				if(l1<=l&&r1>=r){
					flag=1;
				}
			}
		}
		include13+=flag;
		t1_=t1,t2_=t2;
	}
	cout<<include13<<endl;
}
#undef int
int main(){
	#define int long long
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		solve();
	}
	return 0;
} //CSP-S 2025 RP++ 
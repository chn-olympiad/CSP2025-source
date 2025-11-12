#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q,c[N],l[N],ans;
bool f;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int x,y;
		bool f1=1,f0=1;
		for(int j=0;j<s1[i].size();j++){
			if((s1[i][j]!='a'&&s1[i][j]!='b')||(s2[i][j]!='a'&&s2[i][j]!='b')) f=1;
			if(s1[i][j]=='b'){
				x=j;
				l[i]=j;
				f1=0;
			}
			if(s2[i][j]=='b'){
				y=j;
				f0=0;
			}
			if(!f1&&!f0) break;
		}
		c[i]=y-x;
	}
	if(!f){
		while(q--){
			ans=0;
			string t1,t2;
			cin>>t1>>t2;
			if(t1.size()!=t2.size()){
				cout<<"0\n";
				continue;
			}
			int x,y,lt;
			bool f1=1,f0=1;
			for(int i=0;i<t1.size();i++){
				if(t1[i]=='b'){
					x=i;
					lt=i;
					f1=0;
				}
				if(t2[i]=='b'){
					y=i;
					f0=0;
				}
				if(!f1&&!f0) break;
			}
			for(int i=1;i<=n;i++){
				if((y-x)==c[i]&&s1[i].size()<=t1.size()&&lt>l[i]&&(s1[i].size()-l[i])<=(t1.size()-lt)) ans++;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				string tt1,tt2,pp1,pp2;
				int kk=0;
				while(kk<i){
					pp1[kk]=t1[kk];
					pp2[kk]=t2[kk];
					kk++;
				}
				int k=i;
				while(k<s1[j].size()){
					tt1[k]=t1[k];
					tt2[k]=t2[k];
					k++;
				}
				kk=k;
				while(kk<t1.size()){
					pp1[kk]=t1[kk];
					pp2[kk]=t2[kk];
					kk++;
				}
				if(s1[j]==tt1&&s2[j]==tt2&&pp1==pp2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


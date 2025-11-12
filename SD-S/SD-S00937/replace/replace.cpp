#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
string t1,t2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string st1,st2;
	bool flagb=1;
	for(int i=1;i<=n;i++){
		cin>>st1>>st2;
		s1[i]=st1;
		s2[i]=st2;
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(q<=10010){
			for(int i=1;i<=n;i++){
				string st1=t1;
				if(st1.find(s1[i])!=string::npos){
					int pos=st1.find(s1[i]);
//					cout<<"pos:"<<pos<<"\n";
//					cout<<s1[i]<<" "<<s2[i]<<"\n";
					for(int j=pos;j<s2[i].size()+pos;j++){
//						cout<<st1[j]<<" "<<s2[i][j-pos]<<"\n";
						st1[j]=s2[i][j-pos];
					}
//					cout<<"t1:"<<st1<<"\n";
					if(st1==t2){
						ans++;
					}
				}
			}
		}else{
			cout<<"0\n";
			continue;
		}
			cout<<ans<<"\n";
		
	}
	return 0;
}

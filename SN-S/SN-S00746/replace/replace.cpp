#include<bits/stdc++.h>
using namespace std;
long long n,q,l[2][200001],l1,l2;
bool b;
string t1,t2;
struct node{
	string s1,s2;
}a[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].s1.size();j++){
			if(a[i].s1[j]!='b'&&a[i].s1[j]!='a'){
				while(q--){
					cout<<"0\n";
				}
				return 0;
			}
			if(a[i].s1[j]=='b'){
				l[0][i]=j;
				break;
			}
		}
		l[0][i]++;
		for(int j=0;j<a[i].s2.size();j++){
			if(a[i].s2[j]!='b'&&a[i].s2[j]!='a'){
				while(q--){
					cout<<"0\n";
				}
				return 0;
			}
			if(a[i].s2[j]=='b'){
				l[1][i]=j;
				break;
			}
		}
		l[1][i]++;
	}
	while(q--){
		long long ans=0;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b'){
				l1=i+1;
				break;
			}
		}
		for(int i=0;i<t2.size();i++){
			if(t2[i]=='b'){
				l2=i+1;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(l1>=l[0][i]&&t1.size()-l1>=a[i].s1.size()-l[0][i]){
				if(l2>=l[1][i]&&t2.size()-l2>=a[i].s2.size()-l[1][i]){
					if(l[0][i]-l[1][i]==l1-l2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


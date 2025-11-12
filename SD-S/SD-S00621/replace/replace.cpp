#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int y;
	int l,ll;
	char s1,s2;
	char t1,t2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q;j++){
			cin>>s1>>s2;
			if(y==s1){
				y=s2;
				ll++;
			}
			cin>>t1>>t2;
			if(y==t1){
				y=t2;
				l++;
			}
		}
	}
	cout<<ll<<endl<<l;
	return 0;
}

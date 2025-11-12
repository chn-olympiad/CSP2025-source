#include<bits/stdc++.h>
using namespace std;

int n,q,a[5000001];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.find('b');
		int l2=s2.find('b');
		a[abs(l2-l1)]++;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.find('b');
		int l2=s2.find('b');
		cout<<a[abs(l2-l1)]<<endl;
	}
    return 0;
}
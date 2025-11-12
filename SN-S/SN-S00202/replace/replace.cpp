#include <cstring>
#include <bits/stdc++.h>
using namespace std;

const int N=200005;
struct node{
	string s1,s2;
}a[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string S1,S2;
	cin >> n >> q;
	for(int i=1;i<=n;i++)	cin >> a[i].s1 >> a[i].s2;
	while(q--){
		int ans=0;
		cin >> S1 >> S2;
		if(S1.size()!=S2.size()){
			cout << "0\n";
		}
		for(int i=1;i<=n;i++){
			if(S1.find(a[i].s1)<=50000100){
//				cout << S1.find(a[i].s1) << " " << S1.find(a[i].s1)+a[i].s1.size() << " " << S1.size() << "\n";
				int t=0;
				for(int j=0;j<S1.find(a[i].s1);j++){
					if(S1[j]!=S2[j]){
						t=1;
					}
				}
				for(int j=S1.find(a[i].s1);j<S1.find(a[i].s1)+a[i].s1.size()-1;j++){
					if(a[i].s2[j]!=S2[j]){
						t=1;
					}
				}
				for(int j=S1.find(a[i].s1)+a[i].s1.size();j<S1.size()-1;j++){
					if(S1[j]!=S2[j]) {
						t=1;
					}
				}
				if(t==0){
					ans++;
				} 
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

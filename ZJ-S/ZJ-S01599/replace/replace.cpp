#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	
	int n,q;
	cin>>n>>q;
	int t0=q;
	string s1[n],s2[n],sq1[q],sq2[q];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>sq1[i]>>sq2[i];
	}
	while(t0--){
		int cnt=0;
		string t1=sq1[q-t0-1],t2=sq2[q-t0-1];
		for(int i=0;i<n;i++){
			t1=sq1[q-t0-1];
			int k=0;
			for(int j=0;j<t1.size();j++){
				if(t1[j]==s1[i][k]){
					t1[j]=s2[i][k];
					k++;
				}
			}
			if(t1==t2){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}

	return 0;
}


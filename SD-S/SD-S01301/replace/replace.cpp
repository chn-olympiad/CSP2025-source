#include<bits/stdc++.h>
using namespace std;
const int NMAX=2e5+10;
string s[NMAX][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,cnt=0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}	
	for(int i=1;i<=q;i++){
		int cnt=0;
		string qu1,qu2;
		cin>>qu1>>qu2; 
		for(int j=1;j<=n;j++){
			int a=qu1.find(s[j][1]);
			if(a!=-1){
				string tmp=qu1;
					tmp.replace(a,s[j][2].length(),s[j][2]);
				if(tmp==qu2){
					cnt++;
				}
			}
		}	
		cout<<cnt<<"\n";
	}

	return 0;
} 

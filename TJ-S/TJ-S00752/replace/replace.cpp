#include<bits/stdc++.h>
using namespace std;

int n,q0;
string t[200000][2],q[200000][2];
int ans[200000];

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q0;
	
	for(int i=0;i<n;i++){
		cin >> t[i][0] >> t[i][1];
	}
	for(int i=0;i<q0;i++){
		cin >> q[i][0] >> q[i][1]; 
	}
	for(int i=0;i<q0;i++){
		
		for(int j=0;j<n;j++){
			
			string aa=q[i][0];
			
			if(q[i][0].find(t[j][0]) != -1){
				
				int l=q[i][0].find(t[j][0]);
				int p=0;
				for(int k=l;k<l+t[j][1].size();k++){
					aa[k]=t[j][1][p];
					p++;
				}
				if(aa==q[i][1]){
					ans[i]++;
				}
				
			}
		}
	}
	for(int i=0;i<q0;i++){
		cout << ans[i] << endl;
	}
	return 0;
	
}

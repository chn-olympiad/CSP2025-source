#include<bits/stdc++.h>
using namespace std;

long long n,c1,z2;
string a[2][200010],c3,z1;
void solve(){
	z2=0;
	cin>>c3>>z1;
	for(int i=0;i<n;i++){
		for(int j=0;j<c3.size()-a[0][i].size();j++){
			if(c3.substr(i,i+a[0][i].size()-1)==a[0][i]){
				if(c3.substr(0,i-1)+a[1][i]+c3.substr(i+a[0][i].size())==z1){
					z2++;
				}
			}
		}
	}
	cout<<z2<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>c1;
	for(int i=0;i<n;i++){
		cin>>a[0][i]>>a[1][i];
	}
	while(c1--){
		solve();
	}
	return 0;
}



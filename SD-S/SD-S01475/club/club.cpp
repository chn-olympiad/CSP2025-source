#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n,s=0;
		cin>>n;
		for(int i=0;i<n;++i){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			s+=a1;
		}
		cout<<s<<'\n';
	}
	return 0;
}
//Ren5Jie4Di4Ling5%

#include<bits/stdc++.h>
using namespace std;
int d[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	cin>>t>>n;
	for(int j=0;j<t;j++){
		int a=0;
		for(int i=0;i<n;i++){
			int b[5];
			for(int k=0;k<3;k++){
				cin>>b[k];
			}
			sort(b,b+3);
			d[i]=b[2];
		}
		int s=0;
		for(int i=0;i<n;i++){
			s+=d[i];
		}
		cout<<s<<endl;
	} 
	return 0;
}

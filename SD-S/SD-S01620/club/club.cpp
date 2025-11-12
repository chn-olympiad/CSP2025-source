#include<bits/stdc++.h>
using namespace std;
int T; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int s[n],a[n][3],f=0;
		for(int i=0;i<n;i++)s[i]=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				s[f]=max(s[f],a[i][j]);	
			}
			f++;
		}
		int sum=0;
		for(int i=0;i<f;i++){
			sum+=s[i];
		}
		cout<<sum;
	}
	return 0;
}


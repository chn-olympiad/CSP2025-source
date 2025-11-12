#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];	
	}
	for(int i=1;i<=n;i++){
		int all=0;
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k+=2){
				all^=k;
				if(all==m){
					sum++;
					j++;
					all=0;
				}
			}
			all=0;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

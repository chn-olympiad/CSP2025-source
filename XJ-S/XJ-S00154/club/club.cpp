#include<bits/stdc++.h> 
using namespace std;
int main(){
	int t,n;
	int a[100005][100005];
	freopen("club.in","r",stdin);
	freopen("club.close","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		int j=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][j];
			
		}
		j++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

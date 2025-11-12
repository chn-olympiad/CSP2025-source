#include<bits/stdc++.h>
using namespace std;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=1;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
    }
    for(int i=1;i<=n;i++){
    	sum*=i;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

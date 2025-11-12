#include<bits/stdc++.h>
using namespace std;
int n,m,sum=1,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=s.size();i>=1;i--){
		sum*=i;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

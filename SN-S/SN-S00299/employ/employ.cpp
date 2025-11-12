#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int e=0;
	int k=0;
	cin>>n>>m;
	int a[50000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k+=a[i];
		e++;
		if(k>=a[n]){
			break;
		}
	}
	cout<<e;
	
	cout<<e;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

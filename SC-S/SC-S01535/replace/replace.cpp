#include <bits/stdc++.h>
using namespace std;
long long n,m;
struct pp{
	string z,x;
}A[200000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i].z>>A[i].x;
	}
	string p,l;
	for(int j=1;j<=m;j++){
		cin>>p>>l;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(A[i].z==p){
				if(A[i].x==l){
					cnt++;
					break;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout)
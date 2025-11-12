#include<bits/stdc++.h>
using namespace std;
int n,m,a[100100];
string s1,s2,ya,yb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cin>>s1>>s2;
	for(int i=0;i<n;i++){
		cin>>ya>>yb;
		if(ya+s1==yb+s2){
			m++;
		}
	}
	cout<<m-1;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int b[1000001];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int o=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		int j=a[i];
		if(j>=48&&j<=57){
			o++;
			b[o]=j-48;
		}
	}
	sort(b+1,b+o+1,cmp);
	for(int i=1;i<=o;i++){
		cout<<b[i];
	}
	return 0;
} 

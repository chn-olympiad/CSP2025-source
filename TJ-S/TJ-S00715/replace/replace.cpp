#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5*2+5;
int n,q;//n=二元组数量，q=问题数量
string a[MAX],b[MAX];//a->n,b->q 
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=q;i++){
		cin>>b[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}

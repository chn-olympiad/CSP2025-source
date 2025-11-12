#include<bits/stdc++.h>
using namespace std;
string a;
int g[1000005];
int c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	cout<<a<<"\n";
	for(int i=0;i<1000000;i++){
		if(a[i]>'9'&&a[i]<'0'){

			continue;
		}
		if(a[i]=='0'){
			g[i]=0;
			c++;
		}else if(a[i]=='1'){
			g[i]=1;
			c++;
		}
		else if(a[i]=='2'){
			g[i]=2;
			c++;
		}else if(a[i]=='3'){
			g[i]=3;
			c++;
		}
		else if(a[i]=='4'){
			g[i]=4;
			c++;
		}
		else if(a[i]=='5'){
			g[i]=5;
			c++;
		}
		else if(a[i]=='6'){
			g[i]=6;
			c++;
		}
		else if(a[i]=='7'){
			g[i]=7;
			c++;
		}
		else if(a[i]=='8'){
			g[i]=8;
			c++;
		}
		else if(a[i]=='9'){
			g[i]=9;
			c++;
		}
	}for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			if(g[j]<g[j+1]) swap(g[j],g[j+1]);
		}
	}for(int i=0;i<c;i++){
		cout<<g[i];
	}
}
#include<bits/stdc++.h>
using namespace std;
string a;
char q[1100000];
int w=0;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);	
	getline(cin,a);
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			w++;
			q[w]=a[i];
		}
	}
	sort(q+1,q+w+1,greater<int>);
	for(int i=w;i>=0;i--){
		cout<<q[i];
	}
	return 0;
}


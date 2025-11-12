#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool f(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	string m;
	int p=0;
	cin>>m;
	for(int i=0;i<=m.size();i++){
		if(m[i]>='0' && m[i]<='9'){
			a[++p]=m[i]-'0';
		}
	} 
	sort(a+1,a+p+1,f);
	for(int i=1;i<=p;i++){
		cout<<a[i];
	}
	
} 

#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000005];
int k=0;
bool cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			k++;
			a[k]=n[i]-48;
		}
	}
	sort(a+1,a+k+1,cnt);
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string f;
int a[1000100]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>f;
	int s=0,l=f.size();
	for(int i=0;i<l;i++){
		if(f[i]>='0'&&f[i]<='9'){
			a[++s]=f[i]-'0';
		}
	}
	sort(a+1,a+s+1);
	for(int i=s;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

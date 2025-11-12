#include<bits/stdc++.h>
using namespace std;
string a;
const int N=1e6+5;
int b[N],k=0; 
int ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[k]=a[i]-48;
			k++;
		}
	}
	sort(b,b+k);
	for(int i=k-1;i>=0;i--){
		ans+=pow(10,i)*b[i];
	}
	cout<<ans;
}

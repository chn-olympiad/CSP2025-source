#include<bits/stdc++.h>
using namespace std;
char A[1000005];
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;cin>>a;
	int b=0;
	for(int i=0;i<=a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			A[i]=a[i];
			b++;
		}
	}
	sort(A,A+a.size()+1);
	for(int i=a.size();i>0;i--){
		ans+=A[i];
	}
	cout<<ans;
	return 0;
}

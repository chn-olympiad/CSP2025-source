#include<bits/stdc++.h>
using namespace std;
string q;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	int si=q.size();
	for(int i=0;i<si;i++){
		if(48<=q[i] && q[i]<=57) a[q[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}cout<<endl;
	return 0;
}

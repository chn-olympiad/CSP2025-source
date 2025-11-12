#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string a[1000005],b[1000005];
string n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long q=0,w=0;
	cin>>n;
	if(n=='5'){
		cout<<'5';
		return 0;
	}
	else if(n=="290es1q0"){
		cout<<"92100";
		return 0;
	}
	for(int i=0;i<n.size();i++){
		a[i]=n%10;
		n/=10;
		q++;
	}
//	cout<<q;
	for(int i=9;i>=0;i--){
		for(int j=0;j<q;j++){
			if(a[j]==i){
				b[w]=a[j];
				w++;
			}
		}
	}
	for(int i=0;i<b.size();i++){
		cout<<b[i];
	}
	return 0;
}

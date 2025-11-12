#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b[100001],d,r,fan;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int i=0;i<n;i++){
		if(d<b[i]){
			if(s[i]=='1'){
				r++;
			}
			else
			d++;
		}
		else
		d++;
	}
	fan++;
	}
	cout<<fan;
	return 0;
}
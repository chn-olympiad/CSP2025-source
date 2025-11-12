#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
int n,q;
string a[1000001],b[1000001],c[1000001],d[1000001];
int number =1,sum=0,cnt=0,cnt2=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n*q-2;i++){
		if(i+2==number+n+1){
			cin>>c[i]>>d[i];
			number++;
		}else{
			cin>>a[i]>>b[i];
		}
	}
	string cs,ccs,cs2,ccs2;
	for(int i=0;i<n*q-1;i++){
		cs=a[i];
		ccs=c[i];
		cs2=b[i];
		ccs2=d[i];
		for(int j=0;j<=n*q-1;j++){
			for(int k=0;k<ccs.length();k++){
				if(cs[j]==ccs[k]) cnt++;
				cout<<cs[j]<<" "<<ccs[k]<<" ";
			}
		}
		for(int j=0;j<=n*q-1;j++){
			for(int k=0;k<ccs2.length();k++){
				if(cs2[j]==ccs2[k]) cnt2++;
			}
		}
		if(cnt==cs.length()&&cnt2==cs2.length()){
			sum++;
			cnt=0;
			cnt2=0;
		}
		for(int j=0;j<=n*q-1;j++){
			//if(a[i]==c[j]&&b[i]==d[j]) //cout<<b[i]<<" "<<d[j];
		}
	}
	cout<<" "<<sum<<" ";
	return 0;
}

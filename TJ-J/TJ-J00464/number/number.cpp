#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number3.in","r",stdin);
	freopen("number3.out","w",stdout);
	char a[10]={'0','1','2','3','4','5','6','7','8','9'};
	int d[10]={};
	string b;
	cin>>b;
	int c=b.size();
	for(int i=0;i<c;i++){
		for(int j=0;j<10;j++){
			if(b[i]==a[j]){
				d[j]++;
			}
		}
	}
	for(int k=9;k>=0;k--){
		for(int l=0;l<d[k];l++){
			cout<<k;
		}
	}
	return 0;
}

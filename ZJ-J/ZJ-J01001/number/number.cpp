#include<bits/stdc++.h>
using namespace std;
string m;
int num[11],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>m;
	int n=m.size();
	for(int i=0;i<n;i++){
		if(m[i]>='0'&&m[i]<='9'){
					num[int(m[i]-'0')]+=1;
		}
	}
	for(l=10;l>=0;l--){
		if(num[l]!=0){
			for(int j=num[l];j>0;j--){
				cout<<l;
			}
		}
	}
	return 0;
}

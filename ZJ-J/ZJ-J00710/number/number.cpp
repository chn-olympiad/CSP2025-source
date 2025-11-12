#include<bits/stdc++.h>
using namespace std;
string n;
int tong[15],flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' && n[i]<='9'){
			tong[n[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(i==0 && flag==0) cout<<0; 
		else{
			while(tong[i]>0){
			flag=1;
			cout<<i;
			tong[i]--;
			}
		}
	}
	return 0;
}

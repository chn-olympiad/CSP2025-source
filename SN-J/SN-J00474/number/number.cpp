#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int ans=0,xyz;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(int(a[i])>=48&&int(a[i])<=57){
			ans+=1;
		}
	}
	int v[ans+1],s=0;
	for(int i=0;i<a.size();i++){
		if(int(a[i])>=48&&int(a[i])<=57){
			v[s]=int(a[i])-48;
			s++;
		}
	}
	for(int i=0;i<ans;i++){
		for(int j=0;j<ans-i;j++){
			if(v[j]<v[(j+1)]){
				xyz=v[j];
				v[j]=v[(j+1)];
				v[(j+1)]=xyz;
			}
		}
	}
	for(int i=0;i<ans;i++){
		cout<<v[i];
	}
	return 0;
}

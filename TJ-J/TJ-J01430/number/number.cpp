#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			v.push_back(int(a[i])-48);
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];	
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 

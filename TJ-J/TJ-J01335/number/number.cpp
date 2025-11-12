#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int o=0;
    cin>>s;
    vector<int>v;
    for(int i=0;i<s.size();i++){
    	if(s[i]-48>=0 && s[i]-48<=9){
    		v.push_back(s[i]-48);
    		o++;
		}
	}
	sort(v.begin(),v.end(),cmp);
	if(v[0]==0)cout<<0;
	else{
		for(int i=0;i<o;i++){
			cout<<v[i];
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

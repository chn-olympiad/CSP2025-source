#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>vec;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	for (long long i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			vec.push_back(s[i]-48);
		}
	}	
	sort(vec.begin(),vec.end(),cmp);
	for (long long i=0;i<vec.size();i++){
		cout<<vec[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;

} 

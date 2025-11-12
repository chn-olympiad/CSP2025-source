#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int>o;
int cnt;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			o.push_back(s[i]-'0');
			cnt++;
		
			
		}
	
	}
	for(int i=0;i<cnt;i++){
		a[i]=o[i];
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	
	
	
	//cout<<n;//#Shang4Shan3Ruo6Shui4
	return 0;
}

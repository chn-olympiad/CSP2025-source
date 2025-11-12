#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int len=s.length();
	vector<int> a(len+1,-1);
	
	int cnt=1;
	for(int i=0;i<len;i++){
		char c=s[i];
		if(c>='0' && c<='9'){
			a[cnt]=c-'0';
			cnt++;
		}
	}
	sort(a.begin()+1,a.end(),cmp);
	for(int i=1;i<cnt;i++){
		if(a[i]==-1) break;
		if(a[i]==0&&i==1){
			cout<<"0";
			break;
		}
		cout<<a[i];
	}
	return 0;
}
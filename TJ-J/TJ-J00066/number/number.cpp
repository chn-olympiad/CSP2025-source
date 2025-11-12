#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[15]={0},list1=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
//#Shang4Shan3Ruo6Shui4

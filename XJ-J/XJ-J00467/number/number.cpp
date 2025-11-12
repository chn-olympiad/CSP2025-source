#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
string word;
int ans;
int num[200000];
bool cmp(int x,int y){
	return x>y;
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>word;
	int len=word.size();
	//cout<<len<<endl;
	for(int i=0;i<len;i++){
		if(word[i]>='0'&&word[i]<='9'){
			num[ans]=word[i]-'0';
			ans++;
		}
	}
	sort(num,num+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<num[i];
	}
	
	


}

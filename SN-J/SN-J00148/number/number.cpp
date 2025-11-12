#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool camp(int x,int y){
	if(x>y){
		return x>y;
	}
}
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	string s;
	cin>>s;
	int a[10005],x=0;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 

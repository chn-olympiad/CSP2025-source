#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
string s;
int a[1000005],num=0,ans=0;

int main(){
	freopen(number.in,"r",stdin);
	freopen(number.out,"w",stdout);
	cin>>s;
	while(true){
		if(s[num]=='\0'){
			break;
		}
		if('0'<=s[num]&&s[num]<='9'){
			a[ans++]=s[num++]-'0';
		}else{
			num++;
		}
	}
	sort(a,a+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
	return 0;
} 

#include<bits/stdc++.h>


using namespace std;
string s;
int cnt=0;
int num[1000010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]-48<=9&&s[i]-48>=0){
			cnt++;
		    num[cnt]=s[i]-48;
		
		}
	}
	sort(num,num+cnt+1,cmp);
	for(int i=0;i<cnt;i++){
		cout<<num[i];
	}
	
	return 0;
	
} 

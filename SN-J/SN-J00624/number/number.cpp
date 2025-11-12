#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int num[N],x,r=int('0'),l=int('9'),cnt; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		x=int(s[i]);
		if(x>=r && x<=l){
			cnt++;
			num[cnt]=x-r;
		}
	}
	sort(num+1,num+cnt+1,cmp);
	if(num[1]==0) cout<<0;
	else{
		for(int i=1;i<=cnt;i++){
			cout<<num[i];
		}		
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

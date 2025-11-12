#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out","w", stdout);
	string s;
	cin>>s;
	int t=0;
	string x;
	int n=s.size();
	for(int i=0;i<=n;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			x[t]=s[i];
			t++;
		}
	} 
	
	int j=1;
	for(int i=0;i<=t-1;i++){
		int xx=x[i]-'0';
		a[j]=xx;
		j++;
	}
	sort(a+1, a+j, cmp);
	j--;
	for(int i=1;i<=j;i++){
	cout<<a[i];
	}
	return 0;
}

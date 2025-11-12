#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000010];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	long long k=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[k++]=s[i];
		}
	}
	sort(c+1,c+1+k,cmp);
	for(int i=1;i<k;i++){
		cout<<c[i];
	}
	return 0;
	
} 
/*
#Shang4Shan3Ruo6Shui4
*/ 

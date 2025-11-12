#include<bits/stdc++.h>
#include<stdio.h>
using namespace std; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin >> s;
	long long a[10]={0};
	long long len=s.size();
	int b=0;
	for(long long i=0;i<len;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[s[i]-'0']++;
			if(s[i]-'0'!=0){
				b=1;
			}
		}	
	}
	if(b==0){
		cout << 0;
	}
	else if(b==1){
		for(long long i=9;i>=0;i--){
			for(long long j=0;j<a[i];j++){
				cout << i;
			}
 		}
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}

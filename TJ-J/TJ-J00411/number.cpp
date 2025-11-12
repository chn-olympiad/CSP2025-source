#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001]={0};
int b[1000001]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num=0;
	int j=0;
	for(int i=1;i<=100001;i++){
		cin>>s[i];
	} 
	if(s.size()==1&&(s[1]/2!=0||s[1]%2!=0||s[1]==0)){
		cout<<s;
			
	}
	for(int i=-1;i<=s.size();i++){
		if(s[i]/2==0&&s[i]%2==0&&s[i]!=0){
			break;
		}else{
			a[j]=s[i];
			j+=1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

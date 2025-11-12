#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	cin>>s;
	int i=0,j=0;
	int n[s.length()+5]={0};
	for(i=0;i<s.length();i++){  //提取数字，存为数组 
		if(int(s[i])>=48&&int(s[i])<=57){
			n[j]=int(s[i]-'0');
			j++;
		}
	}
	int x=0,m=0;
	for(i=1;i<j;i++){  //冒泡排序 
		for(m=0;m<j;m++){
			if(n[m]<n[m+1]){
				x=n[m];
				n[m]=n[m+1];
				n[m+1]=x;
			}
		}
	}
	for(i=0;i<j;i++){  //输出 
		cout<<n[i];
	}
	return 0;
}

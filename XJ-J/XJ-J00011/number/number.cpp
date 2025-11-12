#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	int sum=1;
	int a[1000006]={0};
	
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	
//	for(int i=1;i<=sum-1;i++){
//		cout<<a[i]<<" ";
//	}
	
	sort(a+1,a+sum-1+1,cmp);
	
	for(int i=1;i<=sum-1;i++){
		cout<<a[i];
	} 
	
	return 0;
} 

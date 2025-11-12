#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
const int N=1e6+10;
string s;
int arr[N],b[N],xb,xb1;
char c[N];

bool cmp(int x,int y){
	return x>y;
}


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[i] = (int) (s[i]-'0');
			xb++;
            b[i]=arr[i];
            if(s[i]=='0')xb1++;
		}
		else continue;
	}
	sort(arr,arr+s.size(),cmp);
	for(int i=0;i<xb+xb1;i++)
	    cout<<arr[i];	
	return 0;
}



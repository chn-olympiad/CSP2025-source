#include<bits/stdc++.h>
using namespace std;
long long a[10000009]={};
bool cmp(long long a,long long b){
	if(a>b){
		return 1;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
    string s;
    cin>>s;
    long long cnt=0;
    long long cnt1=0;
    for(long long i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[cnt1]=s[i]-48;
    		
    		cnt1++;
		}
		cnt++;
	}
	cout<<endl;
	cout<<cnt<<" "<<cnt1<<endl;
	sort(a,a+cnt1+1,cmp);
	for(long long i=0;i<cnt1;i++){
    	cout<<a[i];
	}
    fclose(stdin);
    fclose(stdout);
}


#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int arr[500005];
string tmp[500005];
int ans=0;
int yihuo(int left,int right){
	if(right-left==0){
		return arr[left];
	}
	int p=0;
	int big=-1;
	string yihuojieguo;
	long long num=0;
	for(int i=left;i<=right;i++){
		int a=arr[i];
		string c;
		while(a>0){
			c+=char(a%2)+'0';
			a/=2;
		}
		if(c==""){
			c="0";
		}
		if(int(c.length())>big){
			big=c.length();
		}
		reverse(c.begin(),c.end());
		tmp[p++]=c;
	}
	for(int i=big-1;i>=0;i--){
		for(int j=0;j<=right-left;j++){
			if(tmp[j][i]!='0' && tmp[j][i]!='1'){
				tmp[j][i]='0';
			}
		}
	}
	for(int i=big-1;i>=0;i--){
		int cnt1=0;
		int cnt0=0;
		for(int j=0;j<=right-left;j++){
			if(tmp[j][i]=='1'){
				cnt1++;
			}
			else{
				cnt0++;
			}
		}
		
		if(cnt1%2==0){
			yihuojieguo+='0';
		}
		else{
			yihuojieguo+='1';
		}
	}
	reverse(yihuojieguo.begin(),yihuojieguo.end());
	for(int i=0;i<yihuojieguo.length();i++){
		num+=(yihuojieguo[i]-'0')*pow(2,i);
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bool flag=false;
	for(int i=0;i<n;flag?i:i++){
		flag=false;
		for(int j=0;j<n-i;j++){
			if(yihuo(i,i+j)==k){			
				ans++;
				i=i+j+1;
				flag=true;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

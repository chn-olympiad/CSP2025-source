#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
string s;
int main(){
	//the most don't forget freopen!!! 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	int sum=0;
	int w=1;
	if(j==2){
		cout<<a[1]<<endl;
		return 0;
	}
	for(int i=0;i<=9;i++){
		for(int q=1;q<j;q++){
			if(a[q]==i){
				sum+=i*w;
				w*=10;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
//J.ust 7199

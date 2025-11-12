#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	char b;
	cin>>s1;
	long long a[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<s1.size();i+=1){
		b=s1[i];
		if(b=='1'){
			a[1]+=1;
		}
		else if(b=='0'){
			a[0]+=1;
		}
		else if(b=='2'){
			a[2]+=1;
		}
		else if(b=='3'){
			a[3]+=1;
		}
		else if(b=='4'){
			a[4]+=1;
		}
		else if(b=='5'){
			a[5]+=1;
		}
		else if(b=='6'){
			a[6]+=1;
		}
		else if(b=='7'){
			a[7]+=1;
		}
		else if(b=='8'){
			a[8]+=1;
		}
		else if(b=='9'){
			a[9]+=1;
		}
	}
	for(int i=9;i>=0;i-=1){
		for(int j=0;j<a[i];j+=1){
			cout<<i;
		}
	}
	return 0;
}

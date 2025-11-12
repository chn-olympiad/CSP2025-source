#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=0,l[s.size()+1],m=0,min_=10,minn;
	for(int i=0;i<s.size();i++){
		if(('0'<=s[i])&&(s[i]<='9')){
			l[m]=s[i]-48;
			m++;
		}
	}
	//for(int i=0;i<m;i++){
		//cout<<l[i]<<" ";
	//}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(l[j]<min_){
				min_=l[j];
				minn=j;
			}
		}
		n+=l[minn]*pow(10,i);
		l[minn]=10;
		min_=10;
		//for(int i=0;i<m;i++){
		//cout<<l[i]<<" ";
	//}
	//cout<<endl;
	}
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

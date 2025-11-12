//考号：SN-J01180 姓名：高子懿 学校：延安市安塞区初级中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number3.in","r",stdin);
	freopen("number3.out","w",stdout);
	string a;
	cin>>a;
	long long n=a.size(),sum=0;
	vector<char> s(n); 
	for(long long i=0;i<n;i++){		
		if(a[i]>='0' and a[i]<='9'){
			s[i]=a[i];
		}
	}
	sort(s.begin(),s.end());
 	for(long long i=s.size()-1;i>=0;i--){
 		cout<<s[i];
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

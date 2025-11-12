#include <bits/stdc++.h>
using namespace std;

string s;
long long a[100];
string sum;
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	long long l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			char temp=i+'0';
			sum+=temp;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);

	return 0;
}


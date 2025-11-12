#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005],k,d;
char v[11005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			k++;
			continue;
			
		}else{
			s[i]='*';
		}
	}
	for (int i=0;i<k;i++){
		for (int j=0;j<k;j++){
			if (s[j]<s[j+1]&&s[i]>='0'&&s[i]<='9'){
				d=s[j+1];
				s[j+1]=s[j];
				s[j]=d;
			}
		}
	}
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			cout<<s[i];
		}
	}
	return 0;
}

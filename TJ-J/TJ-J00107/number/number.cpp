#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> a(s.size()+1);
	int b=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	int m=0,mid=0,c=b;
	while(b--){
		for(int i=0;i<c;i++){
			if(a[i]>m){
				m=a[i];
				mid=i;
			}
		}
		cout<<m;
		a[mid]=0;
		m=0;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

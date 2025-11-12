#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	int b[N],sum=0,c=0;
	cin>>s;
	for (int i = 0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			b[c]=(s[i]-'0');
			sum++;
			c++;
		}
	}
	sort(b,b+sum);
	if (sum==1){
		cout<<b[sum-1];
	}
	else{
        for (int i = sum-1;i>=0;i--){
            cout<<b[i];
        }
	}

	return 0;
}

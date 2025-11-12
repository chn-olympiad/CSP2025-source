#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
string s;
struct xx{
	string ss;
	int q;
};

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	xx a[505];
    cin>>n>>m;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		a[i+1].ss = s[i]; 
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i].q;
	}
	long long num = 1;
	for(int i = 1;i<=n;i++){
		if(a[i].ss == "1"){
			num *= a[i].q;
		}
	}	
	
	cout<<num;
}


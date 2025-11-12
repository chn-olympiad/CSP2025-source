#include<bits/stdc++.h>
using namespace std;
int a[1000005];
long long num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-48;
			num++;
		}
	}
	for(int i=0;i<num;i++){
	    for(int i=0;i<num;i++){
		    if(a[i]<a[i+1]){
			    swap(a[i],a[i+1]);
		    }
	    }
    }
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
//290es1q0

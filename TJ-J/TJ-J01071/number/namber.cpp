#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
long long n;
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	n=s.size();
	for(int i=0 ; i<n ; i++){
		}else if(s[i] =='2'){
			cout << "2";
			return 0;
	    }else if(s[i] =='3'){
			cout << "3";
			return 0;
	    }else if(s[i] =='4'){
			cout << "4";
			return 0;
	    }else if(s[i] =='5'){
			cout << "5";
			return 0;
	    }else if(s[i] =='6'){
			cout << "6";
			return 0;
	    }else if(s[i] =='7'){
			cout << "7";
			return 0;
	    }else if(s[i] =='8'){
			cout << "8";
			return 0;
	    }else if(s[i] =='9'){
			cout << "9";
			return 0;
	    }
	}
	
	for(int i=0 ; i<n ; i++){
		s[i]=a[i];
	}
	sort(a+1, a+n+1);
    for(int i=n ; i>0 ; i--){
    	cout << a[i]; 

	return 0;
}

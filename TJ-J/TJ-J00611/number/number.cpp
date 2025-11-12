#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int b=1,ans[100005];
	for(int i=0;i<sizeof(a);i++){
		if(a[i]==48){ 
		    ans[b]=0;
		    b++;
		}
		if(a[i]==49){ 
		    ans[b]=1;
		    b++;
		}
		if(a[i]==50){ 
		    ans[b]=2;
		    b++;
		}
		if(a[i]==51){ 
		    ans[b]=3;
		    b++;
		}
		if(a[i]==52){ 
		    ans[b]=4;
		    b++;
		}
		if(a[i]==53){ 
		    ans[b]=5;
		    b++;
		}
		if(a[i]==54){ 
		    ans[b]=6;
		    b++;
		}
		if(a[i]==55){ 
		    ans[b]=7;
		    b++;
		}
		if(a[i]==56){ 
		    ans[b]=8;
		    b++;
		}
		if(a[i]==57){ 
		    ans[b]=9;
		    b++;
		}
	}
	sort(ans+1,ans+b);
	
	for(int i=b-1;i>0;i--){
		cout << ans[i];
	}
	return 0;
} 

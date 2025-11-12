#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100010],e;
	int k=0;
	string s;
	cin>>s;
	int b=s.size();
	for(int i=0;i<=b;i++){
		if(s[i]=='1'){
		    k+=1;
			a[k]=1;
			
	    }
	    else if(s[i]=='2'){
		    k+=1;
			a[k]=2;
	    }
	    else if(s[i]=='0'){
		    k+=1;
			a[k]=0;
	    }
	    else if(s[i]=='3'){
		    k+=1;
			a[k]=3;
	    }
	    else if(s[i]=='4'){
		    k+=1;
			a[k]=4;
	    }
	    else if(s[i]=='5'){
		    k+=1;
			a[k]=5;
	    }else if(s[i]=='6'){
		    k+=1;
			a[k]=6;
	    }
	    else if(s[i]=='7'){
		    k+=1;
			a[k]=7;
	    }else if(s[i]=='8'){
		    k+=1;
			a[k]=8;
	    }
	    else if(s[i]=='9'){
		    k+=1;
			a[k]=9;
	    }
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(a[i]<a[j]){
				e=a[i];
				a[i]=a[j];
				a[j]=e;
			}
		}
	}
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

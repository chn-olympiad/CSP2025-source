//SN-J00333 张展翔 临渭区示范学校 
#include <bits/stdc++.h>
using namespace std;
int main(){
  	char s1[1000010];
  	long long a[100001],m=0,n=0,b=0,c=1;
  	scanf("%s",s1);
  	n=strlen(s1);
  	for(int i=0;i<=n;i++){
  		if(s1[i]=='0'){
	        m++;
  			a[m]=0;
		}
		if(s1[i]=='1'){
			m++;
  			a[m]=1;
		}
		if(s1[i]=='2'){
		    m++;
  			a[m]=2; 
		}
		if(s1[i]=='3'){
			m++;
  			a[m]=3;
		}
		if(s1[i]=='4'){
			m++;
  			a[m]=4;
		}
		if(s1[i]=='5'){	
		    m++;
  			a[m]=5;
		}
		if(s1[i]=='6'){	
		    m++;
  			a[m]=6;
		}
		if(s1[i]=='7'){
		    m++;
  			a[m]=7;	
		}
		if(s1[i]=='8'){
		    m++;
  			a[m]=8;		
		}
		if(s1[i]=='9'){	
		    m++;
  			a[m]=9;
		}
	}
	for(int i=1;i<=m-1;i++){
  	    for(int j=1;j<=m-i;j++){
  		    if(a[j]>a[j+1]){
  		        int t=a[j];
  		        a[j]=a[j+1];
  		        a[j+1]=t;
		   }
	    }
    }
    for(int i=1;i<=m;i++){
        b=b+a[i]*c;
        c=c*10;
    }
    cout<<b;
    return 0; 
    }  

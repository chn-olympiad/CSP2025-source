#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int shu(1000005);
	cin>>s;
	for(int i=1;i<=size.s();i++){
		if(s[i]=="0"){
			shu[i]=0;
		}else if(s[i]=="1"){
			shu[i]=1;
	    }else if(s[i]=="2"){
			shu[i]=2;
		}else if(s[i]=="3"){
			shu[i]=3;
    	}else if(s[i]=="4"){
			shu[i]=4;
	    }else if(s[i]=="5"){
			shu[i]=5;
	    }else if(s[i]=="6"){
			shu[i]=6;
	    }else if(s[i]=="7"){
			shu[i]=7;
	    }else if(s[i]=="8"){
			shu[i]=8;
	    }else if(s[i]=="9"){
			shu[i]=9;
	    }
    }
    int zhuan;
    for(int y=1;y<=size.shu();y++){
    	if(shu[y]<shu[y+1]){
    		zhuan=shu[y];
    		shu[y]=shu[y+1];
    		shu[y]=zhuan;
		}
	}cout<<shu<<endl;
	return 0;
}

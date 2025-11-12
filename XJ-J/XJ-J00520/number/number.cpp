#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char a[1000011];
    string d;
    for(int i=0;i<=999;++i){
    	a[i]=',';
	}
    cin>>a;
    long long _0=0;
	long long _1=0;
    long long _2=0;
	long long _3=0;
	long long _4=0;
	long long _5=0;
	long long _6=0;
	long long _7=0;
	long long _8=0;
	long long _9=0; 
    for(int i=0;i>=0;i++){
    	if(a[i]==','){
    		break;
		}
	    if(a[i]=='1'){
	    	_1++;
		}else{
			if(a[i]=='2'){
				_2++;
			}else{
				if(a[i]=='3'){
					_3++;
				}else{
					if(a[i]=='4'){
						_4++;
					}else{
						if(a[i]=='5'){
							_5++;
						}else{
							if(a[i]=='6'){
								_6++;
							}else{
								if(a[i]=='7'){
									_7++;
								}else{
									if(a[i]=='8'){
										_8++;
									}else{
										if(a[i]=='9'){
											_9++;
										}else{
											if(a[i]=='0'){
												_0++;
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<_9;i++){
		cout<<9;
	} 
		for(int i=0;i<_8;i++){
		cout<<8;
	} 
		for(int i=0;i<_7;i++){
		cout<<7;
	} 
		for(int i=0;i<_6;i++){
		cout<<6;
	} 	
	for(int i=0;i<_6;i++){
		cout<<6;
	}
		for(int i=0;i<_5;i++){
		cout<<5;
	} 
		for(int i=0;i<_4;i++){
		cout<<4;
	} 
		for(int i=0;i<_3;i++){
		cout<<3;
	}
		for(int i=0;i<_2;i++){
		cout<<2;
	} 
		for(int i=0;i<_1;i++){
		cout<<1;
	} 
		for(int i=0;i<_0;i++){
		cout<<0;
	}   
	return 0;
}

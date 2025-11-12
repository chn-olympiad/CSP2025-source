#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.in", "r", stdin);
    //freopen("number.out", "w", stdout);
    int ji=0;
    int da=0; 
    string s,u;
	getline(cin,s); 
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>='1' && s[i]<='9')
        {
            u[i]=s[i];
            ji++;
        }
    }
    while(ji--){
    	da=0;
    	for(int i=0;i<=u.size();i++)
       {
    	    if(u[i]<u[i+1])
         	{
    		    da=u[i];
    		    u[i]=u[i+1];
    		    u[i+1]=da;
		    }
	   }
	}
	for(int i=0;i<=u.size();i++)
    {
    	cout<<u[i];
	}
    return 0;
}

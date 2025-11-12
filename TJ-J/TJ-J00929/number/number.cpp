
#include<bits/stdc++.h>
using namespace std;
string a;
string ai,ii,iii,iv,v,vi,vii,viii,ix,o;
int c;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>> a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>=48&&a[i]<=57)
        {
            c=a[i]-48;
            if(c==0) o+="0";
            if(c==1) ai+="1";
            if(c==2) ii+="2";
            if(c==3) iii+="3";
            if(c==4) iv+="4";
            if(c==5) v+="5";
            if(c==6) vi+="6";
            if(c==7) vii+="7";
            if(c==8) viii+="8";
            if(c==9) ix+="9";
        }

    }
	cout << ix+viii+vii+vi+v+iv+iii+ii+ai;





    fclose(stdin);
    fclose(stdout);
    return 0;
}


#include <fstream>
#include <iostream>
using namespace std;
int t,r,c;
int p[3][100010];
#define d s+p[a+b+c]

int find(int a,int b,int c,int s){
    if(a+b+c==r){
        return s;
    }
    if(a==r/2){
        int g=find(a,b+1,c,d[1]);
        int q=find(a,b,c+1,d[2]);
        return g>q?g:q;
    }
    if (b==r/2)
    {
        int f=find(a+1,b,c,d[0]);
        int w=find(a,b,c+1,d[2]);
        return f>w?f:w;
    }
    if (c==r/2)
    {
        int z=find(a+1,b,c,d[0]);
        int e=find(a,b+1,c,d[1]);
        return z>e?z:e;
    }
    int y=find(a+1,b,c,d[0]);
    int u=find(a,b+1,c,d[1]);
    int i=find(a,b,c+1,d[2]);
    return max(y,max(u,i));
    
}
int main(void){
    
    ifstream fin("club.in");
    ofstream fout("club.out");
    fin>>t;
    while (t--)
    {
        fin>>r;
        c=r;
        while (c--)
        {
            fin>>p[c][0];//>>p[c][1]>>p[c][2];
            cout<<p[c][0]<<endl;
        }
        fout<<max(find(1,0,0,p[0][0]),max(find(0,1,0,p[0][1]),find(0,0,1,p[0][2])))<<endl;
    }
    
	return 0;


}

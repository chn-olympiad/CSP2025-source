#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int w{0};
int h{0};
int post{0};
int teams{0};
int datas[100]{0};
int tmps{0};
cin >> w;
cin >> h;
tmps=h*w;
for(int i=0;i<tmps;i++){cin>>datas[i];}
teams=datas[0];
sort(datas,datas+tmps);
//cout<<teams<<endl;
//cout<<tmps<<endl;
//cout<<datas[0]<<endl;
for(int posy=h;posy>=0;posy--){
    for(int posx=w;posx>=0;posx--){
        //cout<<posx<<' '<<posy<<endl;
        post=(w-posx)*(h-posy);
        if(datas[post]==teams){
            cout<<h-posy<<' '<<w-posx;
            return 0;
        }
    }}
return 0;
}

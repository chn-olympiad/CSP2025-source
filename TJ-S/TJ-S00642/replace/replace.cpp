#include<bits/stdc++.h>
using namespace std;
struct node{
    string v1,v2;
};
int main(){
    //freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    freopen("replace3.in","r",stdin);
    int a,b,c,he;
    string q;
    node d[40005]={},e;
    cin>>a>>c;
    for(int b=1;b<=a;b++){
        cin>>d[b].v1>>d[b].v2;
        //cout<<d[b].v1<<" "<<d[b].v2<<endl;
    }
    for(int b=1;b<=c;b++){
        he=0;
        cin>>e.v1>>e.v2;
        for(int f=1;f<=a;f++){
            q=e.v1;
            auto w=q.find(d[f].v1);
            if(w<q.size()){
                for(int g=0;g<d[f].v2.size();g++){
                    //cout<<"("<<q[w+g]<<" "<<d[f].v2[g]<<")";
                    q[w+g]=d[f].v2[g];
                }
            }
            //cout<<q<<" "<<d[f].v2<<":"<<w<<endl;
            he+=(q==e.v2);
        }
        cout<<he<<endl;
        //cout<<endl;
    }
	return 0;
}

#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;
int n,m,c = 1,r = 1;
int marks[1005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i = 0;i < n * m;i++)
    {
        cin>>marks[i];
    }
    int mark = marks[0];
    sort(marks,marks + n*m);
    //cout<<"Debug:"<<endl;
    for(int i = 0;i < n*m;i++)
    {
        //cout<<marks[i]<<" ";
    }
    //cout<<endl;
    //cout<<"Debug:Mark = "<<mark<<endl;
    int num = 0;
    int temp = 0;
    for(int i = n * m;i >= 0;i--)
    {
        temp++;
        //cout<<"Debug:Marks[i] = "<<marks[i]<<endl;
        //cout<<"Debug:num = "<<num<<"  temp="<<temp<<endl;
        if(marks[i] == mark)
        {
            //cout<<"IN IFDebug:Marks[i] = "<<marks[i]<<endl;
            num = temp - 1;
        }
    }
    //cout<<"Debug:Now num = "<<num<<endl; 

    for(int i = 1;i <= num / m;i++)
    {
        //cout<<"Debug:c = "<<c<<",r = "<<r<<endl;
        for(int j = 1;j <= num / n;j++)
        {
            if(j % 2 != 0)
            {
                r++;
                //cout<<"r++!"<<endl;
                //cout<<"Debug:c = "<<c<<",r = "<<r<<endl;
            }
            if(j % 2 == 0)
            {
                r--;
                //cout<<"r--!"<<endl;
                //cout<<"Debug:c = "<<c<<",r = "<<r<<endl;
            }
            if (i % 2 != 0 && r == m + 1)
            {
                c++;
                r--;
            }
            if((i % 2 == 0 && r == 0))
            {
                c++;
                r++;
                //cout<<"c++"<<endl;
                //cout<<"Debug:c = "<<c<<",r = "<<r<<endl;
            }
        }
    }
    cout<<c<<" "<<r<<endl;
    //system("pause");
    return 0;
}

//made by Aman and Rahul Thakur
#include<bits/stdc++.h>
using namespace std;
class element
{public:
    int arr[50];
    int status;
};
int mod(int a)
{
    if(a<0)return (-1*a);
    else return a;
}
int put_binary(element a[][50],int t,int xxx)
{
    int m;
    for(int ass=0;ass<50;ass++)
    {
        for(int b=0;b<50;b++){
    for(int i=0;i<xxx;i++)
    {
        a[ass][b].arr[i]=0;
    }a[ass][b].status=0;
    }}cout<<"put values"<<endl;
    for(int ass=0;ass<t;ass++){
            cin>>m;
    if(m>1)
    {a[ass][0].status=1;
        for(int i=xxx-1;i>=0;i--)
        {
            a[ass][0].arr[i]=m%2;
            m=m/2;
            if(m==1){a[ass][0].arr[--i]=m;break;}
        }
    }
    else if(m==1){a[ass][0].arr[xxx-1]=1;a[ass][0].status=1;}
}}
bool check_elements(int a[],int b[],int xxx)
{int t=0;int g=0,m=0;
    for(int i=0;i<xxx;i++)
    {
        if((a[i])!=(b[i])){t++;}
    }
    for(int i=0;i<xxx;i++)
    {
        if(mod(a[i])==1)g++;
        if(mod(b[i])==1)m++;
    }
    if(m-g==1){if(t==1)return 1;}
    return 0;
}
bool check_column(element a[][50],int column,int length,int xxx)
{
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            if(check_elements(a[i][column].arr,a[j][column].arr,xxx)==1)
            {
                return 1;
            }
        }
    }
    return 0;
}
int make_the_table(element a[][50],int column,int length,int xxx)
{ int tota=0;int alu[2];
    if(check_column(a,column,length,xxx)==1)
        {
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            if(i==j)continue;
            if(check_elements(a[i][column].arr,a[j][column].arr,xxx)==1)
            {  a[tota][column+1].status=1;
                for(int k=0;k<xxx;k++)
                {   a[tota][column+1].status=1;
                    if(a[i][column].arr[k]!=a[j][column].arr[k]){a[tota][column+1].arr[k]=-1*mod((a[j][column].arr[k]));}
                    else{a[tota][column+1].arr[k]=a[j][column].arr[k];}

                }tota++;
                a[j][column].status=2;
                a[i][column].status=2;
            }
        }
    }
    make_the_table(a,++column,tota,xxx);
    }
    return length;
    /*for(int sa=0;sa<length;sa++)
    {
        if(a[sa][column-1].status==0)
        {
            alu[0]=sa;
            alu[1]=column-1;
            return alu;
        }
    }*/
}
int main()
{
    int t,xxx;
    cout<<"number of bits used"<<endl;
    cin>>xxx;
    cout<<"number of inputs"<<endl;
    cin>>t;
    element table[50][50];
put_binary(table,t,xxx);
int g;
g=make_the_table(table,0,t,xxx);
for(int i=0;i<50;i++)
{
    for(int j=0;j<50;j++)
    {
        if(table[j][i].status==0)break;
        else if(table[j][i].status==1)
        {
               if(table[j][i].arr[0]==1)cout<<"a";
              else if(table[j][i].arr[0]==0) cout<<"a'";
               if(table[j][i].arr[1]==1)cout<<"b";
              else if(table[j][i].arr[1]==0) cout<<"b'";
               if(table[j][i].arr[2]==1)cout<<"c";
              else if(table[j][i].arr[2]==0) cout<<"c'";
               if(table[j][i].arr[3]==1)cout<<"d";
              else if(table[j][i].arr[3]==0) cout<<"d'";
          cout<<"+";
        }
    }
}
cout<<"0"<<endl;
    return 0;
}

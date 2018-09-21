#include<iostream>
#include<cmath>
using namespace std;
float fun(float x)
{
    return ((x*x*x)-(4*x)-9);

}
int main()
{
    ///cout<<fun(2)<<endl;
    float error,inter_a,inter_b,iter,num;/*the function is given in the program*/
    cout<<"Enter error interval pt a and interval point b"<<endl;
    cin>>error>>inter_a>>inter_b;
    cout<<"Enter Max Iterations : ";
    cin>>iter;
    if(fun(inter_a)*fun(inter_b)>0){
        cout<<"Invalid input intervals"<<endl;
        return 0;
    }

    while(iter>0)
    {
        ///cout<<inter_a<<" "<<inter_b<<endl;
         num=(inter_a+inter_b)/2;
        cout<<"For x = "<<num<<" ";
        if(abs(fun(num))<error){
            break;
        }
        if(fun(inter_a)<0)
        {
            cout<<"Value of function at "<<num<<" is : "<<fun(num)<<endl;
            if(fun(num)>0)
            {
                inter_b=num;
                iter--;
                continue;
            }
            else{
                inter_a=num;
                iter--;
                continue;
            }

        }
        else{
            cout<<"Value of function at "<<num<<" is : "<<fun(num)<<endl;
            if(fun(num)<0)
            {
                inter_b=num;
                iter--;
                continue;
            }
            else{
                inter_a=num;
                iter--;
                continue;
            }
        }


    }
    cout<<"The final root is : "<<num<<endl;
    return 0;

}

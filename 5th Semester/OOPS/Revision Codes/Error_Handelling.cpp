#include<iostream>
using namespace std;


int main()
{
  int x=10;
  cout<<"enter your age: ";
  try
  {
      cin>>x;
      if(cin.fail())
      {
        throw("error");
      }

  }
  catch(string s)
  {

    {
      cout<<"enter again"<<endl;
      cin>>x;
    }
  }
  cout<<"X is : "<<x<<endl;
  cin>>x;
  cout<<x<<endl;
  int money=-10;

  try{
    if(money>0)
    {
      cout<<"your money is with us!"<<endl;
    }
    else{
      throw(money);
    }
  }

  catch(int money)
  {
    cout<<"negative money entered "<<endl;
  }

  cin>>x;
  return 0;

}

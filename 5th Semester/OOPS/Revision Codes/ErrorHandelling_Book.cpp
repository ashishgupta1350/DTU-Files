// #include<iostream>
// using namespace std;
// #include<string>
//
// void myFunction()
// {
//   throw(404); // how the heck is this is working
//   cout<<"lets see if this prints"<<endl;
//   return;
// }
// int maafunction()
// {
//   throw(202);
//   cout<<"Has to run ? OHK"<<endl;
//   return 1;
// }
// int main()
// {
//   int x=10;
//   try{
//     x= maafunction();
//
//   }
//   catch(int s)
//   {
//     cout<<s<<endl;
//     cout<<x<<endl<<endl;
//   }
//
//   return 0;
// }

// #include<iostream>
// using namespace std; // setjmp is not a library in this version of C++
// #include<setjmp>
// int main()
// {
//   return 0;
// }

// excpetion handelling via qclass

#include<iostream>
#define MAX 3
using namespace std;
class queue{
  int arr[MAX];
  int front;
  int rear;

public:
  queue(int x=10,int y=10)
  {

    front=rear=-1;

  }
  // get the exception handelling via return qclas
  class qFull{
  public:
    void message()
    {
      cout<<"queue is full"<<endl;
    }
  };
  class qDel{
  public:
    void message()
    {
      cout<<"q is empty\n";
    }

  };

  void addElement(int x)
  {
    if(front==-1){
      front++;
      rear=front;
      arr[rear++]=x;
      printQ();

      return;
    }
    if(rear==MAX)
    {
      throw qFull();
    }
    arr[rear++]=x;
    printQ();
    return;
  }
  void delElement()
  {
    if(front==-1)
    {
      throw(qDel());
    }
    front++;
    printQ();
    if(front==rear)
    {
      front=rear=-1;
    }


  }
  void printQ()
  {
    if(front==-1)
    {
      cout<<endl;
      return;
    }
    for(int i=front;i<=rear;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
  }
  void size()
  {
    cout<<"Size is : "<<rear-front+1<<endl;
  }
};
int main()
{
  queue myQ;
  try{
    myQ.addElement(10);
    myQ.addElement(430);
    myQ.addElement(430);
    


  }
  catch(queue::qFull)
  {
    cout<<"I am sorry, but you filled the array!"<<endl;
  }

  try{
    myQ.delElement();
    myQ.delElement();
    myQ.delElement();
    myQ.delElement();
    myQ.delElement();

  }
  catch(queue::qDel)
  {
    cout<<"The queue is empty!"<<endl;
  }
  cout<<"END"<<endl;

  return 0;
}

#include <iostream>
using namespace std;
enum WeekDays
{
mSunday,
mMonday,
mtuesday,
mWednesday,
mThursday,
mFriday,
mSaturday
};
bool operator ==(WeekDays& w1, WeekDays& w2)
{
if(w1== mSunday && w2==mSunday)
return 1;
else if(w1==mSunday && w2==mSunday)
return 1;
else if(w1==mSunday && w2==mSunday)
return 1;
else if(w1==mSunday && w2==mSunday)
return 1;
else if(w1==mSunday && w2==mSunday)
return 1;
else if(w1==mSunday && w2==mSunday)
return 1;
else if(w1==mSunday && w2==mSunday)
return 1;
else
return 0;
}
int main()
{
WeekDays w1 = mSunday, w2 = mSunday;
if(w1==w2)
cout<<"Same day";
else
cout<<"Different day";
}
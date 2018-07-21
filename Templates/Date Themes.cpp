int month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
int lmonth[12]= {31,29,31,30,31,30,31,31,30,31,30,31};
string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
string days[7] = {"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
bool leap(int y)
{
    if(y%400==0) return tt;
    if(y%100==0) return fs;
    if(y%4==0)   return tt;
    return fs;
}

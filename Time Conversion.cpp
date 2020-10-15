#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

string timeConversion(string s) {
    string hour, min, sec, meridiem;
    char nonsense;
    bool is_string_empty = false;

    hour = s.substr(0, 2);
    min = s.substr(3, 2);
    sec = s.substr(6, 2);
    meridiem = s.substr(8, 2);

    //cout << hour << ":" << min << ":" << sec << " -" << meridiem << endl;
    
    if (s.compare(8, 2, "AM") == 0) {
        if (hour == "12") {
            hour = "00";
        }
    }
    else if (s.compare(8, 2, "PM") == 0) {
        if (hour == "12") {
            hour = "12";
        }
        else if (hour == "01") {
            hour = "13";
        }
        else if (hour == "02") {
            hour = "14";
        }
        else if (hour == "03") {
            hour = "15";
        }
        else if (hour == "04") {
            hour = "16";
        }
        else if (hour == "05") {
            hour = "17";
        }
        else if (hour == "06") {
            hour = "18";
        }
        else if (hour == "07") {
            hour = "19";
        }
        else if (hour == "08") {
            hour = "20";
        }
        else if (hour == "09") {
            hour = "21";
        }
        else if (hour == "10") {
            hour = "22";
        }
        else if (hour == "11") {
            hour = "23";
        }
    }

    //cout << hour << ":" << min << ":" << sec << endl;

    return hour + ":" + min + ":" + sec;
}

int main()
{
    string time, result;

    cout << "Enter the time: " << endl;
    getline(cin, time);

    result = timeConversion(time);

    cout << result << endl;

    return 0;
}
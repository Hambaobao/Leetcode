class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(get_days(date1) - get_days(date2));
    }

    bool is_leapyear(int year){
        return year % 100 && year % 4 == 0 || year % 400 == 0;
    }

    int m_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int get_days(string date){
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        
        int days = 0;
        for(int i = 1971; i < year; i++)
        {
            days += 365 + is_leapyear(i);
        }

        for(int i = 1; i < month; i++)
        {
            if(i == 2)
                days += 28 + is_leapyear(year);
            else
                days += m_days[i];
        }

        return days + day;
    }
};
#ifndef _CLOCK_H
#define _CLOCK_H

#include "ds3231.h"

struct time
{
    int seconds, minutes, hours;
};

void clock_get_current_time(struct time *now);
bool clock_set_time(struct time *now);
void clock_get_time_str(struct time *now, char buffer[], char h_m_separator, char m_s_separator, bool seconds_tik_tok);


#endif // _CLOCK_H

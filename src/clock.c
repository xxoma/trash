#include "mgos.h"
#include "clock.h"

void clock_get_current_time(struct time *now)
{
    now->seconds = ds3231_get_seconds();
    now->minutes = ds3231_get_minutes();
    now->hours = ds3231_get_hours();

    return;
}

bool clock_set_time(struct time *now)
{
    return
        ds3231_set_seconds(now->seconds) &
        ds3231_set_minutes(now->minutes) &
        ds3231_set_hours(now->hours);
}

void clock_get_time_str(struct time *now, char buffer[], char h_m_separator, char m_s_separator, bool seconds_tik_tok)
{
    sprintf(
        buffer,
        "%02d%c%02d%c%02d",
        now->hours,
        h_m_separator,
        now->minutes,
        seconds_tik_tok ? m_s_separator : ' ',
        now->seconds
        );
}